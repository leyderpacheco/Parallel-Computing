/*
* Date: 2022-03-16
* Author: Leyder Pacheco
* Subject: Parallel and Distributed Computing.
* Topic: Build of parallel benchmark
* Description: Application that allows evaluating the performance
* of a specific aspect of the computer using matrix multiplication
* with the calssical algorithm (rows x columns)
*
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



/* -------------------------------------Funciones ------------------------------------*/

/*Varaible of high value to reserve memory*/
#define DATA_SZ (1024*1024*64*3)

/*Memory space acordin reserve memory value*/
static double MEM_CHUNK[DATA_SZ];

int main(int argc, char *argv[]) {
	
	/*Matrix size*/
	int N = (int) atof(argv[1]);
	
	/*Point to vectors (creation) of memory space reserve with dimension NxN */
	double *Ma, *Mb, *Mr;
	Ma = MEM_CHUNK;
	Mb = Ma + N*N;
	Mr = Mb + N*N;
	
	initMatrix(N, Ma, Mb, Mr);
	sampleStart();
	MM1c(N, Ma, Mb, Mr);
	sampleEnd();
	if(N<4){
		printf("Ma\n");
		printMatrix(N, Ma);
		printf("Mb\n");
		printMatrix(N, Mb);
		printf("Mr\n");
		printMatrix(N, Mr);
	}
	return 0;
}
