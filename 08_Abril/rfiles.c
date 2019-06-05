#include <stdio.h>
#include <stdlib.h>

struct dataType{
	char nombre[32];
	int edad;
	float estatura;
	float peso;
};

struct dataType * datos;

int leer(void *ap){
	struct dataType * data;
	data = ap;
	FILE *f;
	int r;
	f = fopen("data.dat","r");
	if(f==NULL){
		perror("Error abriendo .dat");
		exit(-1);
	}
	r = fread(data,sizeof(struct dataType),1,f);
	if(r==0){
		perror("Error leyendo .dat");
		exit(-1);
	}
	printf(" %s",data->nombre);
	printf(" %i",data->edad);
	printf(" %f",data->estatura);
	printf(" %f",data->peso);
	return 0;
}
//wlp9s0
int main(){
	datos = malloc(sizeof(struct dataType));
	if(datos==NULL){
		perror("error en malloc");
		exit(-1);
	}
	leer(datos);
	free (datos);
	return 0;
}
