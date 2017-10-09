#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;
  int tmp = chdir(argv[1]);
  return tmp;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;
  char tmp[9000] = {};
  getcwd(tmp,9000);
  printf("%s\n",tmp);
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  if(strcmp(argv[0],"cd")==0 && argc == 2) return 1;
  return 0;
}

int validate_pwd_argv(int argc, char** argv) {
  if(strcmp(argv[0],"pwd")==0 && argc == 1) return 1;
  return 0;
}
