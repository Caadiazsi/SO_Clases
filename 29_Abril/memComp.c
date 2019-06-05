#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <float.h>
#include <sys/shm.h>

int main(){
  key_t key = 123;
  int shmID;
  double *data_P;
  shmID = shmget(key,sizeof(double), 0600|IPC_CREAT);
  if(shmID<0){
    perror("Error en shmget");
  };
  data_P = shmat(shmID, NULL, NULL);
  if(data_P < 0 ){
    perror("Error en shmat");
  };
  pid_t pid = fork();
  int status;
  if (pid<0){
    perror("Error en fork");
  }
  if(pid==0){
    *data_P = 3.1415926535;
  }else{
    while(wait(&status) !=pid){
      printf(".");
    };
    printf("%f\n",*data_P);
  }
  int check = shmdt(data_P);
  if(check<0){
    perror("Error en shmdt");
  }
  return 0;
}
