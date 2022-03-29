/*
* Date: 2022-0222
* Author: Juan Camilo Rodriguez
* Course: Paralell and Distributed Computing
* Topic: Posix
* Benchmark: Programa PRINCIPAL para multiplical matrices sin variables globales
* Se requiere que sea modular
* Se implementaran los hilos que haran el calculo de las matrices
* 
*/
#ifndef MODULO_H_INCLUDED
#define MODULO_H_INCLUDED


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


void *multiplicacion(void *arg);
void SampleStart();
void SampleEnd();
float randMM();
void init_matriz(int SZ, double *Ma, double *Mb, double *Mr);
void print_matriz(int SZ, double *M);
void MarixcMM(int size, double *a, double *b, double *c);
void MarixfMM(int size, double *a, double *b, double *c);

#endif