#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <float.h>
long iter = 19999999999;
double calc_Pi (long start, long iterations){
  double pi;
  int mult = 1;
  for(long i=start;i<start+iterations;i+=2){
    double add = (double)((double)(4)/(double)(i));
    if(mult==1){
      pi = pi + add;
      mult = 0;
    }else{
      pi = pi - add;
      mult = 1;
    }
  }
	return pi;
}

int main(){
  int pipefd[2];
  int r;
  pid_t pid;
  r= pipe(pipefd);
  if(r<0){
    perror("Error declarando tuberia");
    exit(-1);
  }
  pid = fork();
  if(pid<0){
    perror("Error declarando fork");
    exit(-1);
  }
  if(pid==0){
    //Child
    close(pipefd[0]);
    double pi_C = calc_Pi(1,iter);
    r = write(pipefd[1],&pi_C,sizeof(pi_C));
    if(r<0){
      perror("Error escribiendo en tuberia");
      exit(-1);
    }
  }else{
    //Parent
    close(pipefd[1]);
    double pi;
    double pi_P = calc_Pi(iter+2,iter+iter);
    r = read(pipefd[0],&pi,sizeof(pi_P));
    pi = pi + pi_P;
    close(pipefd[0]);
    printf("%1.32f\n", pi);
    if(r<0){
      perror("Error leyendo en tuberia");
      exit(-1);
    }
  }
  return 0;
}
