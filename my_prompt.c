/////////////////////////////////////////////////////////
//                                                     //
//               Trabalho I: Mini-Shell                //
//                                                     //
// Compilação: gcc my_prompt.c -lreadline -o my_prompt //
// Utilização: ./my_prompt                             //
//                                                     //
/////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>

#define MAXARGS 100
#define PIPE_READ 0
#define PIPE_WRITE 1

typedef struct command {
    char *cmd;              // string apenas com o comando
    int argc;               // número de argumentos
    char *argv[MAXARGS+1];  // vector de argumentos do comando
    struct command *next;   // apontador para o próximo comando
} COMMAND;

// variáveis globais
char* inputfile = NULL;	    // nome de ficheiro (em caso de redireccionamento da entrada padrão)
char* outputfile = NULL;    // nome de ficheiro (em caso de redireccionamento da saída padrão)
int background_exec = 0;    // indicação de execução concorrente com a mini-shell (0/1)

// declaração de funções
COMMAND* parse(char *);
void print_parse(COMMAND *);
void command_filtro(COMMAND *);
void execute_commands(COMMAND *);
void free_commlist(COMMAND *);

// include do código do parser da linha de comandos
#include "parser.c"

int main(int argc, char* argv[]) {
  char *linha;
  COMMAND *com;

  while (1) {
    if ((linha = readline("my_prompt$ ")) == NULL)
      exit(0);
    if (strlen(linha) != 0) {
      add_history(linha);
      com = parse(linha);
      if (com) {
	//print_parse(com);  //linha comentada pois ja nao era necessaria
	execute_commands(com);
	free_commlist(com);
      }
    }
    free(linha);
  }
}


void print_parse(COMMAND* commlist) {
  int n, i;

  printf("---------------------------------------------------------\n");
  printf("BG: %d IN: %s OUT: %s\n", background_exec, inputfile, outputfile);
  n = 1;
  while (commlist != NULL) {
    printf("#%d: cmd '%s' argc '%d' argv[] '", n, commlist->cmd, commlist->argc);
    i = 0;
    while (commlist->argv[i] != NULL) {
      printf("%s,", commlist->argv[i]);
      i++;
    }
    printf("%s'\n", commlist->argv[i]);
    commlist = commlist->next;
    n++;
  }
  printf("---------------------------------------------------------\n");
}


void free_commlist(COMMAND *commlist){
    // ...
    // Esta função deverá libertar a memória alocada para a lista ligada.
    // ...
    //esta função foi está corrigida pelo professor - 100% certa
    while(commlist!=NULL){
        COMMAND *i = commlist;
        commlist = commlist->next;
        free(i);
    }

}

#define MAXFORKS 15
void execute_commands(COMMAND *commlist) {
    // ...
    // Esta função deverá "executar" a "pipeline" de comandos da lista commlist.
    // ...
    if(!strcmp(commlist->cmd,"filtro")){
        command_filtro(commlist);
    }
    else{
        pid_t pid[MAXFORKS];
        int fd[2], fd2[2];//file descriptor atual e antigo respetivamente
        int stdin, stdout, filhos = 0;//serve para iterar pelos filhos do processo pai
        while(commlist!=NULL){//verificar se só tem um comando
            if(commlist->next!=NULL){
                if(pipe(fd)<0){//cria-se pipe caso haja mais comandos
                    perror("erro no pipes\n");
                }
            }
            if((pid[filhos] = fork()) < 0){
                perror("erro no fork\n");
                exit(0);
            }

            else if(pid[filhos]!=0){//código do pai
                if(filhos>0){//se não é o primeiro filho
                    close(fd2[0]);//por default vão estar abertos ao pai, o que não queremos
                    close(fd2[1]);
                }
                fd2[0] = fd[0];//atualização do file descriptor antigo, esta linha não é necessária.
                fd2[1] = fd[1];
                commlist = commlist->next;//itera-se na lista de comandos
                filhos++;//passa-se ao filho seguinte

            }

            else{//código do filho
                if(filhos==0 && inputfile!=NULL){//Se está no primeiro e há inputfile
                    if((stdin = open(inputfile, O_RDONLY)) < 0){
                        perror("Erro a abrir o ficheiro de input\n");
                    }
                    dup2(stdin,0);//lê do ficheiro dado
                    close(stdin);
                }
                if(commlist->next==NULL && outputfile!=NULL){ //Se está no último filho e existe
                    if((stdout = open(outputfile, O_WRONLY| O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR)) < 0){
                        perror("erro a abrir o ficheiro de output\n");
                    }
                    dup2(stdout, 1); //Passa a escrever para o file em vez do terminal
                    close(stdout);
                }
                if(filhos>0){ // se não for o primeiro comando (mas pode ser o último)
                    dup2(fd2[0], 0);//deixa de ler onde o pai lia (stdinput) e passa a ler da pipe
                    close(fd2[0]);
                    close(fd2[1]);
                }
                if(commlist->next!=NULL){//se não for o último(mas pode ser o primeiro)
                    dup2(fd[1], 1);
                    close(fd[0]);
                    close(fd[1]);
                }

                if((execvp(commlist->cmd, commlist->argv)) < 0){
                    perror("erro no execvp\n");
                }
                exit(0);
            }
        }
        if(background_exec == 0){//esperamos caso não haja concorrencia
            for(int i=0;i<filhos;i++){
                waitpid(pid[i], NULL, 0);
            }
        }
        return;
    }
}

void command_filtro(COMMAND *com){
    //cat < fin | grep palavra > fout
 
    int fd[2];
    int stdout;
    if(pipe(fd) < 0){
        perror("erro na pipe\n");
    }
    pid_t pid;
    if((pid = fork()) < 0){
        perror("erro no fork\n");
    }
    if(pid == 0) {
        dup2(fd[1],1);
        if(execlp("cat","cat",com->argv[1],NULL)){
            perror("erro no cat.");
        }
        exit(1);
    }
    
    //código do pai agora
    close(fd[1]);
    
    if((pid = fork()) < 0){
        perror("erro no fork");
    }
    else if(pid == 0){
        dup2(fd[0],0);
        if((stdout = open(com->argv[2], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR))<0){
            perror("erro a escrever para o ficheiro.");
        }
        dup2(stdout,1);
        if(execlp("grep","grep",com->argv[3],NULL) < 0){
            perror("erro no grep.");
        }
        exit(1);
    }
    close(fd[0]);
    wait(NULL);
}

        
/*
 * 
 * typedef struct command {
    char *cmd;              // string apenas com o comando
    int argc;               // número de argumentos
    char *argv[MAXARGS+1];  // vector de argumentos do comando
    struct command *next;   // apontador para o próximo comando
   } COMMAND;
*/
