#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  int idx=0;
  char*tmp;
  char*ptr[]={};
  char copy[9000]={};

  strcpy(copy,command);
  
  for(idx = 0;copy[idx]!=NULL;idx++)
  {
    if(copy[idx]=='\n') copy[idx]=' ';
  }
  
  (*argv) = (char**)malloc(sizeof(char*)*200);
  for(idx=0;idx<200;idx++)
  {
    (*argv)[idx] = (char*)malloc(sizeof(char)*1000);
    strcpy((*argv)[idx],"");
  }

  tmp = strtok(copy, " ");
  
  for(idx=0;tmp!=NULL;idx++)
  {
    ptr[idx] = tmp;
    argv[idx] = &ptr[idx];
    strcpy((*argv)[idx],tmp);
    tmp = strtok(NULL, " ");
  }
  argc = &idx;
  *argc = idx;
}
