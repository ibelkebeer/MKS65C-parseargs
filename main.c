#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char ** parse_args(char* line){
  char** ary = calloc(6, sizeof(char*));
  int i = 0;
  char * k = "a";
  char * m = " ";
  int ctr = 0;
  for(i; i < 6; i++){
    if (m == k && ctr != 1){
      ary[i] = m;
      ctr ++;
    }
    if (m == k)
      ary[i] = NULL;
    if (m != k){
      k = strsep(&line, " ");
      ary[i] = k;
    }
    m = line;
    printf("in array[%d]: %s\n", i, ary[i]);
    printf("still need to parse: %s\n", line);
  }
  
  return ary;
}


int main(){
  char ex[100] = "ls -a -l";
  char * input = ex;
  char** command;
  command = parse_args(input);
  
  execvp(command[0], command);
  return 0;
}
