#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  int idx=0;
  char*tmp;
  char*ptr[200]={};

  (*argv) = (char**)malloc(sizeof(char*)*200);
  for(idx=0;idx<200;idx++)
  {
    (*argv)[idx] = (char*)calloc(sizeof(char),1000);
  }

  tmp = strtok((char*)command, "\n");
  tmp = strtok((char*)command, " ");
  
  for(idx=0;tmp!=NULL;idx++)
  {
    ptr[idx] = tmp;
    argv[idx] = &ptr[idx];
    strcpy((*argv)[idx],tmp);
    tmp = strtok(NULL, "\n");
    tmp = strtok(NULL, " ");
  }
  *argc = idx;
  argc = &idx;
}
