#include <stdio.h>
#include <stdlib.h>

struct dataType{
	char nombre[32];
	int edad;
	float estatura;
	float peso;
};

struct dataType * datos;

int cargar(void *ap){
	struct dataType *data;
	data = ap;
	printf("Nombre");
	scanf(" %s",data->nombre);
	printf("Edad");
	scanf(" %i",&data->edad);
	printf("Estatura");
	scanf(" %f",&data->estatura);
	printf("Peso");
	scanf(" %f",&data->peso);
	return 0;
}
int guardar(void * ap){
	struct dataType * data;
	data = ap;
	FILE *f;
	int w;
	f = fopen("data.dat", "w+");
	if(f==NULL){
		perror("Error abriendo .dat");
		exit(-1);
	}
	w = fwrite(data, sizeof(struct dataType),1,f);
	if (w == 0){
		printf("Error escribiendo .dat");
	}
	fclose (f);
	return 0;
}
int main(){
 	datos = malloc(sizeof(struct dataType));
	if(datos==NULL){
		perror("error en malloc");
		exit(-1);
	}
	cargar(datos);
	guardar(datos);
	free (datos);
	return 0;
}
