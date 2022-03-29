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

void sampleStart(){
	clock_gettime(CLOCK_MONOTONIC, &inicio);	
}


void sampleEnd(){
	clock_gettime(CLOCK_MONOTONIC, &fin);	
	double totalTime;
	totalTime = (fin.tv_sec - inicio.tv_sec)*1e9;
	totalTime = (totalTime + (fin.tv_nsec - inicio.tv_nsec))*1e-9;
	//printf ("\nTotal time: %f seg \n", totalTime);
	printf ("%f\n", totalTime);
}

double randNumber(){
    float min = 0.001, max = 9.999;
    static int first = -1;
    if(first == (first < 0)){
       srand(time(NULL) + getpid());
    }
    if(min >= max){
        return errno = EDOM, NAN;
    }
    return min + (float)rand()/((float)RAND_MAX/(max-min));
}

/* Se crea la función para inicializar las matrices */
void InitMatrix(int SZ, double *Ma, double *Mb, double *Mr){
    int i,j;
    for(i=0; i < SZ; ++i){
        for(j=0;j<SZ;++j){
            Ma[j+i*SZ] = 3.9*(i-j);
            Mb[j+i*SZ] = 2.0*(j+i);
            Mr[j+i*SZ] = 0.0;
        }
    }
}

/* Se crea la función para inicializar las matrices */
void initMatrix(int SZ, double *Ma, double *Mb, double *Mr){
	int i, j;
	for(i=0; i<SZ; ++i){
		for(j=0;j<SZ;++j){
			Ma[j+i*SZ] = 3.0*(i-j);
			Mb[j+i*SZ] = 2.8*(j+i);
			Mr[j+i*SZ] = 0.0;
		}
	}
		
}

/*Se implementa la impresión (para efectos de validación) */
void printMatrix(int SZ, double *M){
	int i,j;
	for (i=0;i<SZ; ++i){
		for (j=0;j<SZ; ++j){
			printf("  %f  ",M[j+i*SZ]);
		}
		printf("\n");
	}
		printf("----------------------------");
		printf("\n");
		
		
}

/*	@brief: Multiply matrices
	@param size: Size of matrix
	@param a: Matriz A to multiply
	@param b: Matriz B to multiply
	@param c: Total matrix of multiplication
    ---
*/
void matrixMultiplyMM1c(int size, double *Ma, double *Mb, double *Mr){
	int i, j;
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
		/*Necesita punteros auxiliares*/
		double *pA, *pB;
		double sumaAuxiliar = 0.0;
		pA = Ma + (i*size);
		pB = Mb + j;
			for(int k = 0; k < size; ++k, pA ++, pB+=size){
				sumaAuxiliar += (*pA * *pB);
			}
			Mr[i*size+j] = sumaAuxiliar;
		}
	}
}

void matrixMultiplyMM1f(int size, double *Ma, double *Mb, double *Mr){
  int i, j;
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
		/*Necesita punteros auxiliares*/
		double *pA, *pB;
		double sumaAuxiliar = 0.0;
		pA = Ma + (i*size);
		pB = Mb + (j*size);
			for(int k = 0; k < size; ++k, pA++, pB++){
				sumaAuxiliar += (*pA * *pB);
			}
			Mr[i*size+j] = sumaAuxiliar;
		}
	}
}

/*	Se imlementa paso a paso benchmark Multiaplicacion de matrices
	Algoritmo clasico (filas x columnas) de matrices
	de igual diemnsion
*/

/************************FUnciones para pthread**************************/

/*FUncion para reserva de memoria para matrices de doble puntero*/

double ** reserva_memoria(int size){
	/*REservamos la memoria de dimension N*N contigua*/
	double * valor = (double *) malloc(size*size*sizeof(double));

	/* Reserva de un vector de punteros double con dimensio size*/
	double ** ptr = (double **) malloc(size*size*sizeof(double *));

	/*Iteracion para que cada puntero posicione en la reserva de memoria*/
	for(int i = 0; i < size; i++){
		ptr[i] = &valor[i*size];

	}
	return ptr;
}

/* Se crea la función para inicializar las matrices */
void initMatrix_posix(double **Ma,double **Mb,double **Mc, int size){
	int i, j;
	for(i=0; i<size; ++i){
		for(j=0;j<size;++j){
			Ma[i][j] = 3.9*(i-j);
			Mb[i][j] = 2.0*(i+j);
			Mc[i][j] = 0.0;		
		}
	}
}
/*IMpresion de matriz*/
void printMatriz_posix(double **matriz, int size){
	int i, j;
	for(i=0; i<size; ++i){
		for(j=0;j<size;++j){
		printf("%lf     ", matriz[i][j]);	
		}
		printf("\n");
	}
	printf("**********************************************\n");
}	

