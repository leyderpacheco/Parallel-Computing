/*Date: 2022-03-30
* Author: Leyder Pacheco
* Subject: Parallel and Distributed Computing.
* Topic: Posix implemetation (Library)
* Description: Application for matrix multiplication
  with the classical algorithm (rows x columns) using
  global variables. Also, using the following functions:
    1. Creation of double pointer variables for matrices
    2. Memory reserve for double pointer matrices
    3. Init matrix
    4. Function for the matrix's product:
        4.1.1 The matrix A is divide and those portions 
        will be sent to an individual thread
        4.1.2 The matrix's size will be sent in the 
        execution.
    5. Matrix's size always squared (NxN)
    6.  Print matrix with double pointer.

* 
*/


/*Interfaces*/
#include "modulo.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <omp.h>

typedef struct argsThreads{
    int numThreads;
    int matrixSize;
    double **matrixA;
    double **matrixB;
    double **matrixR;
    int idThread;
} threadsArguments;

/**
 * @brief Function that will be sent to each thread, that makes the matrix multiplication.
 * The matrix A divides in slices, in function with the dimension and the number of threads that requires the
 * user.
 *
 * Note: the function will be void, and this returns a potential warning. Think in it to improve it
 * @param arg that has the thread struct with the needed info for the thread
 */
void *multMM(void *arg)
{
    int i, j, k,idTh,N,Nthreads,portionSize,initRow,endRow;
    double **Ma,**Mb,**Mr,sum;
	idTh = ((threadsArguments*)arg)->idThread;
	Ma = ((threadsArguments*)arg)->matrixA;
	Mb = ((threadsArguments*)arg)->matrixB;
	Mr = ((threadsArguments*)arg)->matrixR;
	N = ((threadsArguments*)arg)->matrixSize;
	Nthreads = ((threadsArguments*)arg)->numThreads;
	portionSize = N / Nthreads;		   /*It is determined the portion of matrix A to send to each thread*/
	initRow = idTh * portionSize;	   /*It is passed the beggining of the row*/
	endRow = (idTh + 1) * portionSize; /*It is passed the end of the row*/
	for (i = initRow; i < endRow; i++)
	{
		for (j = 0; j < N; ++j)
		{
			sum = 0;
			for (k = 0; k < N; k++)
			{
				sum += Ma[i][k] * Mb[k][j];
			}
			Mr[i][j] = sum;
		}
	}
    return arg;
}

/**
 * @brief Main function
 * 
 * @param argc That is the arguments count
 * @param argv That is the arguments values
 * @return 0 if everything is ok or another number in error case
 */
int main(int argc, char* argv[]){
    double **Ma,**Mb,**Mc;
    int N,Nthreads,i;
    pthread_t *threads;
    threadsArguments *theArguments;
    if (argc!=3){
        printf("./MMPosix <matrix size> <# of threads>\n");
        return -1;
    }
    
    
    /*Init of global variables*/
    N           = atof(argv[1]);    /* Matrix's size.*/
    Nthreads    = atof(argv[2]);    /* Number of threads.*/
    if(Nthreads>omp_get_max_threads()){
        printf("El número de hilos debe ser menor o igual a %d",omp_get_max_threads());
        return -1;
    }

    threads=(pthread_t*)malloc(N*sizeof(pthread_t));/*Thread reservation*/
    theArguments= (threadsArguments*)malloc(Nthreads*sizeof(threadsArguments));
    /*Memory creation and reserce for each matrix*/
    Ma = memReserve(N); 
    Mb = memReserve(N);
    Mc = memReserve(N);
    initMatrix_DoublePointers (Ma, Mb, Mc, N);
    
    printMatrix_DoublePointers (Ma, N);
    printMatrix_DoublePointers (Mb, N);
    
    sampleStart();
    for (i = 0; i < Nthreads; ++i){
        theArguments[i].numThreads=Nthreads;
        theArguments[i].matrixSize=N;
        theArguments[i].matrixA=Ma;
        theArguments[i].matrixB=Mb;
        theArguments[i].matrixR=Mc;
        theArguments[i].idThread=i;
        pthread_create(&threads[i],NULL,multMM,&theArguments[i]);
    }
    for (i = 0; i < Nthreads; ++i){
        
        pthread_join(threads[i],NULL);
    }
    sampleEnd();
    free(threads);
    printMatrix_DoublePointers (Mc, N);
    return 0;
}

