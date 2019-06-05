#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <strings.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

#define PORT 3535
#define NOSE 2
struct sockaddr_in server, client1;
// signal -- setsocketopt (antes del bind)
int main(){
  size_t tama;
  int fd, r , fd1, tamaClient;
  //Creando servidor con socket
  fd = socket(AF_INET, SOCK_STREAM, 0);
  tama = sizeof(server);
  if(fd<1){
    perror("Error en funcion socket");
  }
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr =	INADDR_ANY;
  bzero(server.sin_zero, 8);
  //Configurando servidor con bind
  r = bind(fd,(struct sockaddr*)&server,tama);
  if(r<0){
    perror("Error configurando el socket");
  }
  r = listen(fd,NOSE );
  if(r<0){
    perror("Error en el listen");
  }
  tamaClient = 0;
  fd1 = accept(fd,(struct sockaddr*)&client1, &tamaClient);
  if(fd1<0){
    perror("Error");
  }
  r = send (fd1, "hola mundo", 10, 0);
  if(r<0){
    perror("Error enviando");
  }
  close(fd);
  close(fd1);
  return 0;
}
