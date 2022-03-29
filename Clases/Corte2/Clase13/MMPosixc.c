/* Universidad Sergio Arboleda 
	Fecha : 08-02-2022
	Autor : Juan Camilo Rodriguez
	Materia : Parallel Computing
	Tema : Implementación Posix
	Programa para multiplicar dos matrices con variables GLOBALES
1. Creacion de variablse doble puntero para matrices pricipal Global
2. Funcion reserva de memoria para las matrices de doble puntero
3. FUncion inicializacion de matrices
4. Funcion para el producto de matrices:
se dividide la matriz A por porciones a ser enviadas a cada hilo
--> el numero de hilos sera cargado al ejecutar
--> La dimension de la matriz sera enviada al ejecutar
5. La dimension de la matriz siempre sera N*N
6. Se necesita duncion para impresion de matrices (doble puntero)
*/

#include "modulo.h"
#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <pthread.h>

void main(int argc, char* argv[]){

	int N, Nthreads;
	double **Ma, **Mb, **Mc;
	if ( argc != 3){
		printf("./exe N<dimMatriz> Nth<numHIlos>\n");
	}
	/*Se capturan las variables size y numero de hilos*/

	N = atof(argv[1]);
	Nthreads = atof(argv[2]);

	/*Se crea el pool de hilos*/
	pthread_t *hilosExe;
	/*Se reserva mamoria para los hilos*/
	hilosExe = (pthread_t *) malloc(Nthreads*sizeof(pthread_t)); 

	/*Creacion y reserva de memoria para cada matriz*/

	Ma = reserva_memoria(N);
	Mb = reserva_memoria(N);
	Mc = reserva_memoria(N);
	/*Se inicializan las matrices*/
	initMatrix_posix(Ma,Mb,Mc,N);


	recoger_datos(N, Nthreads, Ma, Mb, Mc);

	/*Se reparten las tareas a cada hilo al usar la funcion pthread_t*/
	sampleStart();

	for(int i = 0; i< Nthreads; ++i){
		int *idThread;
		idThread = (int *)malloc(sizeof(int));
		*idThread = i;
		pthread_create(&hilosExe[i], NULL, multMM_posix,(void *)idThread);
	}
	for(int i = 0; i< Nthreads; ++i){
		pthread_join(hilosExe[i], NULL);
	}
	sampleEnd();
	free(hilosExe);	
}
