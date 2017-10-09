#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{   
  int idx=0;
  int cnt=0;
  char*tmp;
  char copy[9000]={};
  strcpy(copy,command);  
  for(idx = 0;copy[idx]!=0;idx++)
  {
    if(copy[idx]=='\n'||copy[idx]=='\t') copy[idx]=' ';
    else if(copy[idx]!=' ') cnt++;
  }
  if(cnt==0)
  {
    *argc = 1;
    *(argv) = (char**)malloc(sizeof(char*));
    (*argv)[0] = (char*)malloc(sizeof(char));
    strcpy((*argv)[0],"");
    return;
  }
  tmp = strtok(copy, " ");   
  for(idx=0;tmp!=0;idx++)
  {
    *(argv) = (char**)realloc(*argv,sizeof(char*)*(idx+1));    
    int size=strlen(tmp);
    (*argv)[idx]=(char*)malloc(sizeof(char)*(size+1));
    strcpy((*argv)[idx],tmp);
    tmp = strtok(NULL," ");
  }
  *argc = idx;
  printf("%d\n",*argc);
}
