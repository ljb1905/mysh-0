#include "utils.h"
#include <stdio.h>
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  int idx=0;
  char*tmp;
  char*ptr[20]={};

  (*argv) = (char**)malloc(sizeof(char*)*20);
  for(idx=0;idx<20;i++)
  {
    (*argv)[idx] = (char*)calloc(sizeof(char),100);
  }

  tmp = strtok((char*)command, "\n");
  tmp = strtok((char*)command, " ");
  
  for(idx=0;tmp!=NULL;idx++)
  {
    ptr[idx] = tmp;
    argv[idx] = &ptr[idx];
    strcpy((*argv)[i],tmp);
    tmp = strtok(NULL, "\n");
    tmp = strtok(NULL, " ");
  }
  *argc = idx;
  argc = &idx;
  }
}
