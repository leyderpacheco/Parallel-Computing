/*
* Date: 2022-02-01
* Author: Leyder Pacheco
* Course: Paralell and Distributed Computing
* Topic: build of Second benchmark
* Benchmark: toy app thath allows to meausre performance 
* of a specific aspet of the computer
* 
* to compile: g++ -g MyProgram3.cpp -o MiPrograma3
*/
#include<stdio.h>
#include<stdlib.h>

/* Se crea una variable con un valor alto para reservar memoria*/

#define DATA_SZ (1024*1024*64*3)

/* Se reserva el espacio de  memoria, segun el valor*/

static double MEM_CHUNK[DATA_SZ];


/* SE crea la funcion para inicializar las matrices*/

void init_matriz(int SZ, double *Ma, double *Mb, double *Mr){
	int i, j, k;
	for (i=0; i<SZ;i++){
		for (j=0; j<SZ;j++){
			
			Ma[j+i*SZ] = 3.0*(i-j);
			Mb[j+i*SZ] = 2.8*(j+i);
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


int main (int argc, char** argv){

	/* Apuntamos los vextores al espacio reservado con dimension N*N */

	double *Ma, *Mb, *Mr;
	int i, j, k;

	/*Se captura la dimension de la matriz*/
	int  N = (int) atof(argv[1]);
	printf("valor ingresado %d\n", N);

	Ma =  MEM_CHUNK;
	Mb = Ma + N*N;
	Mr = Mb + N*N;

	init_matriz(N, Ma, Mb, Mr);
	printf("Matriz A: \n");
	print_matriz(N, Ma);
	printf("\nMatriz B: \n");
	print_matriz(N, Mb);

	for(i=0;i<N;++i){
		for(j=0;j<N;++j){
			double *pa, *pb;
			double suma_auxiliar = 0.0;

			pa = Ma +( i * N );
			pb = Mb + j;
			for(k=0; k<N; ++k, pa++, pb+=N){

				suma_auxiliar += (*pa * *pb);
			}
			Mr[i*N+j] = suma_auxiliar;
		}
	}

	printf("\nMatriz r: \n");
	print_matriz(N, Mr);


	return 0;
}
