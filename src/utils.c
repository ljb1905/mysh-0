#include "utils.h"

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  int idx=0;//

  strtok((char*)command, "\n");
  strtok((char*)command, " ");
  
  (*argv) = (char**)malloc(sizeof(char*)*20);
  for(int i=0;i<20;i++)
  {
    (*argv)[i] = (char*)calloc(sizeof(char),100);
  }
}
