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


/*Se incluyen las variables Globales para todo el programa*/


int N, Nthreads;
double **Ma, **Mb, **Mc;
/*Funcion a ser enviada a cada hilo, que realiza la multiplicacion de 
 matrices se divide por porciones en funcion de la dimension y de numero
 de hilos que requiere el usuaro.
 La funcion sera del tipo void, la cual retornara potencial de riesgo*/
void *multMM_posix(void *arg){
	/*arg tiene el id del hilo*/
	int i, j, idTh;
	int porcionSize, iniFila, finFila;
	double sum;/*Auxiliar para suma parcial*/

	/*el argumento es del tipo puntero vacio, 
	y se castea a puntero entero*/
	idTh = *(int *)(arg);

	/*Se determina la porcion de la matriz a ser enviada a cada hilo*/
	porcionSize = N/Nthreads;

	/*Se pasa el inicio de fila, segun el Id del hilo*/
	iniFila = idTh*porcionSize;
	/*Se pasa el fin de fila, segun el Id del hilo*/
	finFila = (idTh+1)*porcionSize;

	for(i=iniFila; i< finFila; ++i){
		for(j=0; j<N; ++j){
			sum = 0.0;
			for (int k = 0; k < N; ++k)
			{
				sum += Ma[i][k] * Mb[k][j];

			}
			Mc[i][j] = sum;
		}
	}
}

int main(int argc, char* argv[]){

	if ( argc != 3){
		printf("./exe N<dimMatriz> Nth<numHIlos>\n");
		return -1;
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

	if (N < 4){
		printf("Matriz A\n");
		printMatriz_posix(Ma,N);
		printf("Matriz B\n");
		printMatriz_posix(Mb,N);
	}

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

	if(N < 4){
		printf("Matriz C\n");
		printMatriz_posix(Mc,N);
	
	}	
	return 0;
}
