/*
* Date: 2022-02-011
* Author: Juan Camilo Rodriguez
* Course: Paralell and Distributed Computing
* Topic: build of Second benchmark
* Benchmark: toy app thath allows to meausre performance 
* of a specific aspet of the computer
* 
* to compile: gcc Bench02.c -o resultado_bench2
* ./resultado_bench2
*/
#include "funciones.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>
#include<errno.h>
#include<sys/time.h>

/* Se crea una variable con un valor alto para reservar memoria*/

#define DATA_SZ (1024*1024*64*3)

/* Se reserva el espacio de  memoria, segun el valor*/

static double MEM_CHUNK[DATA_SZ];

int main (int argc, char** argv){

	/* Apuntamos los vextores al espacio reservado con dimension N*N */

	double *Ma, *Mb, *Mr;
	
	/*Se captura la dimension de la matriz*/
	int  N = (int) atof(argv[1]);
	printf("valor ingresado %d\n", N);

	Ma =  MEM_CHUNK;
	Mb = Ma + N*N;
	Mr = Mb + N*N;

	init_matriz(N, Ma, Mb, Mr);

	SampleStart();

	MarixcMM(N, Ma, Mb, Mr);

	SampleEnd();
	
	return 0;
}
