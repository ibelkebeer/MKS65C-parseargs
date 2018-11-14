#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char ** parse_args(char* line){
  char** ary= calloc(6, sizeof(char*));
  int i;
  for(i = 0; i < 6; i++){
    char sep[] = line;
    printf("%s\n", sep);
    ary[i] = strsep(&line, " ");
  }
  return ary;
}

int main(){
  char* input = "ls -l";
  char** command;
  command = parse_args(input);
  execvp(command[0], command);
  return 0;
}
