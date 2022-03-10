/*
* Date: 2022-0222
* Author: Leyder Pacheco
* Course: Paralell and Distributed Computing
* Topic: Posix
* Benchmark: Programa PRINCIPAL para multiplical matrices sin variables globales
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

//FUncion: Cada thread calcula un elemento sobre el resultado

/*SE pasa como argumento al vector de datos
EL vector de datos, sera la porcion envidada para el calculo del elemento sobre la 
matriz resultado*/

void *multiplicacion(void *arg){ 
	/*La variable "datos" de tipoo entero apunta al vector argumentos*/
	int *datos = (int *)arg; 
	int i, j, k;
	/* VAr que contenga el primer valor de v*/
	int x = datos[0];
	for (i=0; i<=x;i++){
		k+= datos[i]*datos[i+x];
	}
	int *p = (int *)malloc(sizeof(int));
	*p= k;

	pthread_exit(p)
}
