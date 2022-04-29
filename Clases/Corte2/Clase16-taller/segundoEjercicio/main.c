/*
# punto 2 taller
# Serie Fibonacci
# Autor: Leyder Pacheco
# computacion paralela */

/*Se crea la funcion main para generar la serie fibonacci, */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cfib.h"


/*funcion main que recibe el tamaño de la serie como argumento y un numiter */

int main(int argc, char **argv) 
{
	int arg=-1, numiter=-1, i;
	clock_t t;
	if (argc != 3) {
		printf("Wrong number of arguments,expecting 2 (got %d)\n.", argc-1);
	return 1;
	}
	arg = atoi(argv[1]);
	numiter = atoi(argv[2]);
	t = clock();
	for (i=0; i<numiter; ++i) {
		cfib(arg);
	}
	t = clock() - t;
	printf("%f\n", ((float)t) / 1000000/ numiter * 1e9);
	return 0;
}