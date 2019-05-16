#include "triad.h"

void my_print(int *c){
	FILE *output;
	output = fopen("output.data", "w");
	int i = 0;
	for(i=0; i<NUM; i++)
		fprintf(output, "%d,", c[i]);
	fprintf(output, "\n");
	fclose(output);
}
void triad(int *a,int *b, int *c, int s){
	int i;
	for(i=0;i<NUM;i++){
		c[i] = a[i] + s*b[i];
	}
}

int main(){
	int *a, *b, *c;
	a = (int *) malloc (sizeof(int) * NUM);
	b = (int *) malloc (sizeof(int) * NUM);
	c = (int *) malloc (sizeof(int) * NUM);
	int i;
	srand(time(NULL));
	for(i=0; i<NUM; i++){
		a[i] = rand();
		b[i] = rand();
	}
	triad(&a[0],&b[0],&c[0],3);
	my_print(&c[0]);
	return 0;
}
