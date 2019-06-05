//Para compilar gcc fork.c -o fork -lm
//htop para observar como corre el sistema
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
int fun(){
  float x;
  for(long i=0;i<2000000000;i++){
    x = x+sin(i);
  }
}

int main(int argc, char const *argv[]){
  pid_t p;
  p = fork();
  if(p<0){
    perror("Error en Fork");
    exit(-1);
  }
  if(p==0){
    printf("Child\n");
    fun();
  }else{
    printf("Parent\n");
    fun();
  }
  return 0;
}
