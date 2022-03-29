
/* Universidad Sergio Arboleda 
	Fecha : 08-02-2022
	Autor : Juan Camilo Rodriguez
	Materia : Parallel Computing
	Tema : Implementación Benchmark en C
*/


/*Interfaces*/

#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>


/*CONSTANTS*/
struct timespec inicio, fin;

/* -------------------------------------Funciones ------------------------------------*/


/* Se crea una variable con un valor alto 
   para reservar memoria */
#define DATA_SZ (1024*1024*64*3)


/* Se reserva el espacio de memoria según el valor */
static double MEM_CHUNK[DATA_SZ];

int main(int argc, char *argv[]) {
	
	/*Matrix size*/
	int N = (int) atof(argv[1]);
	
	/*Apuntamos los vectores (creacion) a espacio de memoria reservada con dimension NxN */
	double *Ma, *Mb, *Mr;
	Ma = MEM_CHUNK;
	Mb = Ma + N*N;
	Mr = Mb + N*N;
	
	initMatrix(N, Ma, Mb, Mr);
	sampleStart();
	matrixMultiplyMM1f(N, Ma, Mb, Mr);
	sampleEnd();
		
	return 0;
}
/*
Compile
    gcc modulo.c -c
    gcc MM1c.c -c
	gcc modulo.o MM1c.o -o MM1c
Execute
	time ./MM1c N--> N : Any number
*/