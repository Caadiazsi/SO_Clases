//Para compilar gcc fork.c -o fork -lm
//htop para observar como corre el sistema
// LINUX DEVICE DRIVERS 3  - DIAGRAMA DE BLOQUES DEL KERNELL
//jjpulidos
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <float.h>

int fun_child(){
  double pi;
  int mult = 1;
  long impar;
  for(long i=1;i<20000000000;i+=2){
    double add = (double)((double)(4)/(double)(i));
    if(mult==1){
      pi = pi + add;
      mult = 0;
    }else{
      pi = pi - add;
      mult = 1;
    }
    impar = i;
  }
  FILE *f;
	int w;
	f = fopen("data.dat", "w+");
	if(f==NULL){
		perror("Error abriendo .dat");
		exit(-1);
	}
	w = fwrite(&pi, sizeof(pi),1,f);
	if (w == 0){
		perror("Error escribiendo .dat");
    exit(-1);
	}
	fclose (f);
  printf("%1.32f\n",pi);
	return 0;
}
double fun_parent(){
  double pi = 0;
  int mult = 1;
  long impar = 19999999999;
  for(long i=impar;i<impar+20000000000;i+=2){
    double add = (double)((double)(4)/(double)(i));
    if(mult==1){
      pi = pi + add;
      mult = 0;
    }else{
      pi = pi - add;
      mult = 1;
    }
  }
  printf("%1.32f\n",pi);
  return 0;
}
int sum (double pi_P){
  FILE *f;
  int r;
  double pi_C;
  f = fopen ("data.dat","r");
  if(f == NULL){
    perror("Error abriendo .dat");
    exit(-1);
  }
  r = fread(&pi_C, sizeof(pi_C),1,f);
	if (r == 0){
		perror("Error leyendo .dat");
    exit(-1);
	}
  double pi = pi_P+pi_C;
  printf("%1.32f\n", pi);
  fclose(f);
  return 0;
}
int main(int argc, char const *argv[]){
  pid_t p = fork();
  int status;
  if(p<0){
    perror("Error en Fork");
    exit(-1);
  }
  if(p==0){
    printf("Hello Child\n");
    fun_child();
  }else{
    printf("Parent\n");
    double pi_Pa = fun_parent();
    while(wait(&status) !=p){
      printf(".");
    };
  }
  return 0;
}
