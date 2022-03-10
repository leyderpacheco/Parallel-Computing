/*
* Date: 2022-0222
* Author: Leyder Pacheco
* Course: Paralell and Distributed Computing
* Topic: Posix
* Benchmark: Programa para multiplical matrices sin variables globales
* Se requiere que sea modular
* Se implementaran los hilos que haran el calculo de las matrices
* 
* to compile: gcc Bench03.cpp -o res
* ./res <dimension de la matriz>
* time ./res 200
*/

#include "Modulo.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

//SE define el numero de hilos segun configuracion

#define MAX 4

//se implementa el principal

int main(){
	int mA[MAX][MAX];
	int mB[MAX][MAX];

	// se crean variables para los indices de las matrices

	int f1 = MAX, f2 = MAX;
	int c1 = MAX, c2 = MAX;

	//se generan aleatorios para las matrices
	for (int i = 0; i< f1 ; i++){
		for (int i = 0; i< f1 ; i++){
			mA[i][j] = rand()%10;
			mB[i][j] = rand()%10;
		}
	}
	//presentar la matriz A

	for (int i = 0; i< f1 ; i++){
		for (int i = 0; i< f1 ; i++){
			printf ( " %f ", mA[i][j]);
			
		}
		printf("\n");
	}
	//presentar la matriz B

	for (int i = 0; i< f1 ; i++){
		for (int i = 0; i< f1 ; i++){
			printf ( " %f ", mB[i][j]);
			
		}
		printf("\n");
	}

	int maxFC = f1 * c1;

	pthreads *hilos;
	hilos = (pthread_t *)malloc(maxFC*sizeof(pthread_t));

	int contador= 0;
	int* dato = NULL;

	for (int i = 0; i< f1 ; i++){

		for (int i = 0; i< c2 ; i++){
			//almacenar filas y columnas en datos ( punteros)
			dato = (int *)malloc((24)*)sizeof(int);


			for (int k = 0; k< c1 ; k++){
			//almacenar filas y columnas en datos ( punteros)
				dato[k+1]= mA[i][j];
			}		
			
			for (int k = 0; k< c1 ; k++){
			//almacenar filas y columnas en datos ( punteros)
			dato[k+c1+1]= mB[i][j];
			}
		}


		pthreads_create (&hilos [contador++], NULL, multiplicacion, (void *)(dato));
	}
}