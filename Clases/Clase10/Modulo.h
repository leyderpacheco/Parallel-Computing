/*
* Date: 2022-0222
* Author: Leyder Pacheco
* Course: Paralell and Distributed Computing
* Topic: Posix
* Benchmark: Programa PRINCIPAL para multiplical matrices sin variables globales
* Se requiere que sea modular
* Se implementaran los hilos que haran el calculo de las matrices
* 
*/
#ifndef MODULO_H_INCLUDED
#define MODULO_H_INCLUDED

#include "Modulo.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

/*PRototipos de las funciones a prensentar como interfaz del Modulo.C*/


void *multiplicacion(void *arg);

#endif