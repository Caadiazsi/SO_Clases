#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <strings.h>
#include <sys/types.h>
#include <time.h>

#define PORT 3535

struct sockaddr_in server;

int main(){
  size_t tama;
  int fd, r;
  fd = socket(AF_INET, SOCK_STREAM, 0);
  if(fd<1){
    perror("Error en funcion socket");
  }
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  server.sin_addr.s_addr =	inet_addr("127.0.0.1");
  tama = sizeof(server);
  r = connect(fd,(struct sockaddr*)&server,tama);
  if(r<0){
    perror("Error en connect");
  }
  char buffer[10];
  r = recv(fd, buffer,10,0);
  printf(" %s\n", buffer);
  close(fd);
  return 0;
}
