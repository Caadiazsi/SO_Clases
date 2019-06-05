#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Hello, World!\n");
	//char a; int b;float c;short d;double e;long f;long long g;
	char *a; int *b;float *c;short *d;double *e;long *f;long long *g;
	/*printf("char:%li",sizeof(a));
	printf("int:%li",sizeof(b));
	printf("float:%li",sizeof(c));
	printf("short:%li",sizeof(d));
	printf("double:%li",sizeof(e));
	printf("long:%li",sizeof(f));
	printf("longlong:%li",sizeof(g));
	printf("\n");*/
	a = (char*)malloc(10);
	if(a==NULL){
		perror("error malloc: ");
		exit(-1);
	} 
	return 0;
}
