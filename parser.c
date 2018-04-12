COMMAND*Jdf34jflk09dklinvalid_command(COMMAND*Jdf34jflk09dklcommlist,char*
Jdf34jflk09dklmsg){fprintf(stderr,"\x45\x52\x52\x4f\x3a\x20\x25\x73" "\n",
Jdf34jflk09dklmsg);free_commlist(Jdf34jflk09dklcommlist);return NULL;}COMMAND*
parse(char*linha){COMMAND*Jdf34jflk09dklhead_com,*Jdf34jflk09dklcom;char*
Jdf34jflk09dkllinha_com,*Jdf34jflk09dklfirst,*Jdf34jflk09dklsecond,*
Jdf34jflk09dklthird,*Jdf34jflk09dklin,*Jdf34jflk09dklout;int 
Jdf34jflk09dkllen;inputfile=NULL;outputfile=NULL;background_exec=
(0x768+4444-0x18c4);
if(linha[(0x149b+494-0x1689)]==((char)(0x4a6+3916-0x1376))||linha[strlen(linha)-
(0x1ab+4254-0x1248)]==((char)(0xbdf+5513-0x20ec)))return 
Jdf34jflk09dklinvalid_command(NULL,
"'|' como primeiro ou último caracter da linha");Jdf34jflk09dklhead_com=NULL;
Jdf34jflk09dkllinha_com=strtok(linha,"\x7c");while(Jdf34jflk09dkllinha_com){if
(Jdf34jflk09dkllinha_com[strlen(Jdf34jflk09dkllinha_com)+(0x1d53+1659-0x23cd)]
==((char)(0x1b8c+1318-0x2036)))return Jdf34jflk09dklinvalid_command(
Jdf34jflk09dklhead_com,
"\x64\x6f\x69\x73\x20\x63\x61\x72\x61\x63\x74\x65\x72\x65\x73\x20\x27\x7c\x27\x20\x73\x65\x67\x75\x69\x64\x6f\x73"
);if(Jdf34jflk09dklhead_com){Jdf34jflk09dklcom->next=malloc(sizeof(COMMAND));
Jdf34jflk09dklcom=Jdf34jflk09dklcom->next;}else{Jdf34jflk09dklhead_com=malloc
(sizeof(COMMAND));Jdf34jflk09dklcom=Jdf34jflk09dklhead_com;}Jdf34jflk09dklcom
->cmd=Jdf34jflk09dkllinha_com;Jdf34jflk09dkllinha_com=strtok(NULL,"\x7c");}
Jdf34jflk09dklcom->next=NULL;
Jdf34jflk09dklcom=Jdf34jflk09dklhead_com;while(Jdf34jflk09dklcom){
Jdf34jflk09dkllinha_com=Jdf34jflk09dklcom->cmd;
if(Jdf34jflk09dkllinha_com[(0x2078+1291-0x2583)]==((char)(0x1362+1651-0x19af)))
return Jdf34jflk09dklinvalid_command(Jdf34jflk09dklhead_com,
"\x27\x26\x27\x20\x63\x6f\x6d\x6f\x20\x70\x72\x69\x6d\x65\x69\x72\x6f\x20\x63\x61\x72\x61\x63\x74\x65\x72\x20\x64\x6f\x20\x63\x6f\x6d\x61\x6e\x64\x6f"
);Jdf34jflk09dkllen=strlen(Jdf34jflk09dkllinha_com);Jdf34jflk09dklfirst=
strtok(Jdf34jflk09dkllinha_com,"\x26");if(strtok(NULL,"\x20"))return 
Jdf34jflk09dklinvalid_command(Jdf34jflk09dklhead_com,
"'&' não é o último caracter do comando");if(Jdf34jflk09dkllen!=strlen(
Jdf34jflk09dkllinha_com))background_exec=(0xa3f+3810-0x1920);
if(Jdf34jflk09dkllinha_com[strlen(Jdf34jflk09dkllinha_com)-(0x913+342-0xa68)]
==((char)(0x7fc+7160-0x23b8))||Jdf34jflk09dkllinha_com[strlen(
Jdf34jflk09dkllinha_com)-(0x55d+875-0x8c7)]==((char)(0x211+9217-0x25d4)))return
 Jdf34jflk09dklinvalid_command(NULL,
"'<' ou '>' como último caracter do comando");if(Jdf34jflk09dkllinha_com[
(0x245a+554-0x2684)]==((char)(0xd90+687-0x1003))){if(Jdf34jflk09dkllinha_com[
(0x67a+1806-0xd87)]==((char)(0x2239+957-0x25ba))||Jdf34jflk09dkllinha_com[
(0xb79+5108-0x1f6c)]==((char)(0x126c+4481-0x23af)))return 
Jdf34jflk09dklinvalid_command(NULL,"sequência '<<' ou '<>' no comando");
Jdf34jflk09dklin=Jdf34jflk09dklfirst=strtok(Jdf34jflk09dkllinha_com,"\x3c");
if(strtok(NULL,""))return Jdf34jflk09dklinvalid_command(NULL,
"\x64\x6f\x69\x73\x20\x63\x61\x72\x61\x63\x74\x65\x72\x65\x73\x20\x27\x3c\x27\x20\x6e\x6f\x20\x63\x6f\x6d\x61\x6e\x64\x6f"
);strtok(Jdf34jflk09dklfirst,"\x3e");if(Jdf34jflk09dklfirst[strlen(
Jdf34jflk09dklfirst)+(0xbc6+3641-0x19fe)]==((char)(0x505+104-0x52f)))return 
Jdf34jflk09dklinvalid_command(Jdf34jflk09dklhead_com,
"\x64\x6f\x69\x73\x20\x63\x61\x72\x61\x63\x74\x65\x72\x65\x73\x20\x27\x3e\x27\x20\x73\x65\x67\x75\x69\x64\x6f\x73"
);Jdf34jflk09dklout=Jdf34jflk09dklsecond=strtok(NULL,"\x3e");if(strtok(NULL,""
))return Jdf34jflk09dklinvalid_command(NULL,
"\x64\x6f\x69\x73\x20\x63\x61\x72\x61\x63\x74\x65\x72\x65\x73\x20\x27\x3e\x27\x20\x6e\x6f\x20\x63\x6f\x6d\x61\x6e\x64\x6f"
);Jdf34jflk09dklthird=NULL;}else if(Jdf34jflk09dkllinha_com[(0x636+1328-0xb66)
]==((char)(0x2613+179-0x2688))){if(Jdf34jflk09dkllinha_com[(0xa1c+1916-0x1197)]
==((char)(0x18c6+2619-0x22c5))||Jdf34jflk09dkllinha_com[(0x1031+3888-0x1f60)]==
((char)(0x1472+2234-0x1cee)))return Jdf34jflk09dklinvalid_command(NULL,
"sequência '><' ou '>>' no comando");Jdf34jflk09dklout=Jdf34jflk09dklfirst=
strtok(Jdf34jflk09dkllinha_com,"\x3e");if(strtok(NULL,""))return 
Jdf34jflk09dklinvalid_command(NULL,
"\x64\x6f\x69\x73\x20\x63\x61\x72\x61\x63\x74\x65\x72\x65\x73\x20\x27\x3e\x27\x20\x6e\x6f\x20\x63\x6f\x6d\x61\x6e\x64\x6f"
);strtok(Jdf34jflk09dklfirst,"\x3c");if(Jdf34jflk09dklfirst[strlen(
Jdf34jflk09dklfirst)+(0x12dc+1650-0x194d)]==((char)(0x1bcb+262-0x1c95)))return 
Jdf34jflk09dklinvalid_command(Jdf34jflk09dklhead_com,
"\x64\x6f\x69\x73\x20\x63\x61\x72\x61\x63\x74\x65\x72\x65\x73\x20\x27\x3c\x27\x20\x73\x65\x67\x75\x69\x64\x6f\x73"
);Jdf34jflk09dklin=Jdf34jflk09dklsecond=strtok(NULL,"\x3c");if(strtok(NULL,"")
)return Jdf34jflk09dklinvalid_command(NULL,
"\x64\x6f\x69\x73\x20\x63\x61\x72\x61\x63\x74\x65\x72\x65\x73\x20\x27\x3c\x27\x20\x6e\x6f\x20\x63\x6f\x6d\x61\x6e\x64\x6f"
);Jdf34jflk09dklthird=NULL;}else{Jdf34jflk09dklfirst=strtok(
Jdf34jflk09dkllinha_com,"\x3c");if(Jdf34jflk09dklfirst[strlen(
Jdf34jflk09dklfirst)+(0x32a+5556-0x18dd)]==((char)(0x53d+4906-0x182b))||
Jdf34jflk09dklfirst[strlen(Jdf34jflk09dklfirst)+(0x1af+3660-0xffa)]==
((char)(0x463+6010-0x1b9f)))return Jdf34jflk09dklinvalid_command(NULL,
"sequência '<<' ou '<>' no comando");Jdf34jflk09dklin=strtok(NULL,"\x3c");if(
Jdf34jflk09dklin&&strtok(NULL,""))return Jdf34jflk09dklinvalid_command(NULL,
"\x64\x6f\x69\x73\x20\x63\x61\x72\x61\x63\x74\x65\x72\x65\x73\x20\x27\x3c\x27\x20\x6e\x6f\x20\x63\x6f\x6d\x61\x6e\x64\x6f"
);strtok(Jdf34jflk09dklfirst,"\x3e");if(Jdf34jflk09dklfirst[strlen(
Jdf34jflk09dklfirst)+(0x1fe8+113-0x2058)]==((char)(0x560+5096-0x190c))||
Jdf34jflk09dklfirst[strlen(Jdf34jflk09dklfirst)+(0x21f2+106-0x225b)]==
((char)(0x23d+6276-0x1a83)))return Jdf34jflk09dklinvalid_command(NULL,
"sequência '><' ou '>>' no comando");Jdf34jflk09dklout=strtok(NULL,"\x3e");if(
Jdf34jflk09dklout&&strtok(NULL,""))return Jdf34jflk09dklinvalid_command(NULL,
"\x64\x6f\x69\x73\x20\x63\x61\x72\x61\x63\x74\x65\x72\x65\x73\x20\x27\x3e\x27\x20\x6e\x6f\x20\x63\x6f\x6d\x61\x6e\x64\x6f"
);if(Jdf34jflk09dklout){strtok(Jdf34jflk09dklin,"\x3e");if(strtok(NULL,""))
return Jdf34jflk09dklinvalid_command(NULL,
"\x64\x6f\x69\x73\x20\x63\x61\x72\x61\x63\x74\x65\x72\x65\x73\x20\x27\x3e\x27\x20\x6e\x6f\x20\x63\x6f\x6d\x61\x6e\x64\x6f"
);Jdf34jflk09dklsecond=Jdf34jflk09dklout;Jdf34jflk09dklthird=
Jdf34jflk09dklin;}else if(Jdf34jflk09dklin){strtok(Jdf34jflk09dklin,"\x3e");
if(Jdf34jflk09dklin[strlen(Jdf34jflk09dklin)+(0x17b+6596-0x1b3e)]==
((char)(0x1cf8+2624-0x26fa)))return Jdf34jflk09dklinvalid_command(
Jdf34jflk09dklhead_com,
"\x64\x6f\x69\x73\x20\x63\x61\x72\x61\x63\x74\x65\x72\x65\x73\x20\x27\x3e\x27\x20\x73\x65\x67\x75\x69\x64\x6f\x73"
);Jdf34jflk09dklout=strtok(NULL,"\x3e");if(strtok(NULL,""))return 
Jdf34jflk09dklinvalid_command(NULL,
"\x64\x6f\x69\x73\x20\x63\x61\x72\x61\x63\x74\x65\x72\x65\x73\x20\x27\x3e\x27\x20\x6e\x6f\x20\x63\x6f\x6d\x61\x6e\x64\x6f"
);Jdf34jflk09dklsecond=Jdf34jflk09dklin;Jdf34jflk09dklthird=
Jdf34jflk09dklout;}else Jdf34jflk09dklsecond=Jdf34jflk09dklthird=NULL;}
if(Jdf34jflk09dklin&&Jdf34jflk09dklcom!=Jdf34jflk09dklhead_com)return 
Jdf34jflk09dklinvalid_command(Jdf34jflk09dklhead_com,
"'<' não está no primeiro comando");if(Jdf34jflk09dklout&&Jdf34jflk09dklcom
->next)return Jdf34jflk09dklinvalid_command(Jdf34jflk09dklhead_com,
"'>' não está no último comando");if(background_exec==(0x1e90+701-0x214c)&&
Jdf34jflk09dklcom->next)return Jdf34jflk09dklinvalid_command(
Jdf34jflk09dklhead_com,"'&' não está no último comando");
Jdf34jflk09dklcom->argc=(0x1548+3203-0x21cb);if((Jdf34jflk09dklcom->argv[
Jdf34jflk09dklcom->argc]=strtok(Jdf34jflk09dklfirst,"\x20"))==NULL)return 
Jdf34jflk09dklinvalid_command(Jdf34jflk09dklhead_com,
"\x66\x61\x6c\x74\x61\x6d\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x6f\x73");if(
Jdf34jflk09dklin==Jdf34jflk09dklfirst)inputfile=Jdf34jflk09dklcom->argv[
Jdf34jflk09dklcom->argc];else if(Jdf34jflk09dklout==Jdf34jflk09dklfirst)
outputfile=Jdf34jflk09dklcom->argv[Jdf34jflk09dklcom->argc];else 
Jdf34jflk09dklcom->argc++;while((Jdf34jflk09dklcom->argv[Jdf34jflk09dklcom->
argc]=strtok(NULL,"\x20"))!=NULL)Jdf34jflk09dklcom->argc++;if(
Jdf34jflk09dklsecond){if((Jdf34jflk09dklcom->argv[Jdf34jflk09dklcom->argc]=
strtok(Jdf34jflk09dklsecond,"\x20"))==NULL)return 
Jdf34jflk09dklinvalid_command(Jdf34jflk09dklhead_com,
"\x66\x61\x6c\x74\x61\x6d\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x6f\x73");if(
Jdf34jflk09dklin==Jdf34jflk09dklsecond)inputfile=Jdf34jflk09dklcom->argv[
Jdf34jflk09dklcom->argc];else if(Jdf34jflk09dklout==Jdf34jflk09dklsecond)
outputfile=Jdf34jflk09dklcom->argv[Jdf34jflk09dklcom->argc];else 
Jdf34jflk09dklcom->argc++;while((Jdf34jflk09dklcom->argv[Jdf34jflk09dklcom->
argc]=strtok(NULL,"\x20"))!=NULL)Jdf34jflk09dklcom->argc++;}if(
Jdf34jflk09dklthird){if((Jdf34jflk09dklcom->argv[Jdf34jflk09dklcom->argc]=
strtok(Jdf34jflk09dklthird,"\x20"))==NULL)return Jdf34jflk09dklinvalid_command
(Jdf34jflk09dklhead_com,
"\x66\x61\x6c\x74\x61\x6d\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x6f\x73");if(
Jdf34jflk09dklin==Jdf34jflk09dklthird)inputfile=Jdf34jflk09dklcom->argv[
Jdf34jflk09dklcom->argc];else if(Jdf34jflk09dklout==Jdf34jflk09dklthird)
outputfile=Jdf34jflk09dklcom->argv[Jdf34jflk09dklcom->argc];else 
Jdf34jflk09dklcom->argc++;while((Jdf34jflk09dklcom->argv[Jdf34jflk09dklcom->
argc]=strtok(NULL,"\x20"))!=NULL)Jdf34jflk09dklcom->argc++;}Jdf34jflk09dklcom
->argv[Jdf34jflk09dklcom->argc]=NULL;Jdf34jflk09dklcom->cmd=Jdf34jflk09dklcom
->argv[(0x1a9a+921-0x1e33)];Jdf34jflk09dklcom=Jdf34jflk09dklcom->next;}return 
Jdf34jflk09dklhead_com;}
