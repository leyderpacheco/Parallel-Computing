/***************************************
 * Fecha:   01-03-2022
 * Autor:   Leyder Pacheco
 * Materia: COmputacion paralela y distribuida
 * Tema:    IMplementacion POsix (library)
 * Modulo del principal para Multiplicar 2 matrices sin variables glonbales
 * Se requiere que el diseño sea modular,
 * EL modulo implementarà los hilos que haran el
 * calculo del producto de la matrix
 * ***************************************************************/

#include "modulo.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

//Cada thread calcula un solo elemento sobre la matriz resultado 

//Funcion para cada thread
/*  Se pasa como argumento el puntero al vector de datos
*   EL vector de datos serà la porcion enviada para el 
*   calculo del elemento sobre la matriz del resultado*/

void *multiplicacion(void *arg){

//  la variable "datos" del tipo entero, apunta al vector argumentos
    int *datos = (int *)arg;
    int i,j,k;
    // var que contenga el primer valor del v
    int x = datos[0];

    for (i = 0; i < x; i++)
    {
        k+=datos[i]*datos[i+x];
    }
    int *p= (int *)malloc(sizeof(int));
    *p = k;
// se usa para terminar el hilo y retornar el vLor pasado como puntero
    pthread_exit(p);
}