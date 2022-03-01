/*
* Date: 2022-02-011
* Author: Leyder Pacheco
* Course: Paralell and Distributed Computing
* Topic: build of Second benchmark
* Benchmark: toy app thath allows to meausre performance 
* of a specific aspet of the computer
* 
* to compile: gcc Bench02.c -o resultado_bench2
* ./resultado_bench2
*/
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

struct timespec inicio,fin;


/*********************** Funciones *********************/
/*Inicio para medida de tiempo */

void SampleStart(){
    clock_gettime(CLOCK_MONOTONIC,&inicio);
}
/* Fin: medida de tiempo*/

void SampleEnd(){
    clock_gettime(CLOCK_MONOTONIC,&fin);
    /*  Se imprime el tiempo */
    double tiempoTotal;
    tiempoTotal = (fin.tv_sec - inicio.tv_sec)*1e9;
    tiempoTotal = (tiempoTotal + (fin.tv_nsec - inicio.tv_nsec))*1e-9;

    printf(" %f \n",tiempoTotal);

} 
/**
 * Function that multiplies two matrixes
 * @param Ma that is the A matrix
 * @param Mb that is the B matrix
 * @return The matrix product between Ma and Mb
 */

/*  Se crea un doble precision aleatorio */
float randMM(){
    float min = 0.001, max = 9.999;
    static int first = -1;
    if((first = (first<0))){
        srand(time(NULL)+getpid());
    }
    if (min>max)
    {
        return errno=EDOM,NAN;
    }
    return min + (float)rand()/((float)RAND_MAX/(max-min));
    
}


/* SE crea la funcion para inicializar las matrices*/

void init_matriz(int SZ, double *Ma, double *Mb, double *Mr){
	int i, j, k;
	for (i=0; i<SZ;i++){
		for (j=0; j<SZ;j++){
			
			Ma[j+i*SZ] = randMM();
			Mb[j+i*SZ] = randMM();
			Mr[j+i*SZ] = 0.0;
			
		}
	}
}

/* Se implementa la impresion para efectos de validacion*/

void print_matriz(int SZ, double *M){
	int i, j, k;
	for (i=0; i<SZ;i++){
		for (j=0; j<SZ;j++){
			printf("   %f   ", M[j+i*SZ]);
			
		}
		printf("\n");
	}	
}


void MarixMM(int size, double *a, double *b, double *c){
	int i, j, k;

	for(i=0;i<size;++i){
		for(j=0;j<size;++j){
			double *pa, *pb;
			double suma_auxiliar = 0.0;

			pa = a + i;
			pb = b + ( j * size );
			for(k=0; k<size; ++k, pa+=size, pb++){

				suma_auxiliar += (*pa * *pb);
			}
			c[j*size+i] = suma_auxiliar;
		}
	}
}

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
	/*printf("Matriz A: \n");
	print_matriz(N, Ma);
	printf("\nMatriz B: \n");
	print_matriz(N, Mb);
*/
	SampleStart();
	MarixMM(N, Ma, Mb, Mr);
	SampleEnd();
	/*
	printf("\nMatriz r: \n");
	print_matriz(N, Mr);
*/

	return 0;
}
