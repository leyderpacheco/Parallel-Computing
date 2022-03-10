/***************************************
 * Fecha:   01-03-2022
 * Autor:   Leyder Pacheco
 * Materia: Computacion paralela y distribuida
 * Tema:    Implementacion POsix (library)
 * Programa principal para Multiplicar 2 matrices sin variables glonbales
 * Se requiere que el diseño sea modular,
 * EL modulo implementarà los hilos que haran el
 * calculo del producto de la matrix
 * ***************************************************************/

#include "modulo.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

// Se define el numero de hilos segun configuraciòn
#define MAX 12

// Se implementa el principal

int main()
{

    int mA[MAX][MAX];
    int mB[MAX][MAX];

    // Se crean variables para los indices de las matrices

    int f1 = MAX;
    int c1 = MAX;
    int f2 = MAX;
    int c2 = MAX;

    // Se generan aleatorios para las matrices
    for (int i = 0; i < f1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            mA[i][j] = rand() % 10;
            mB[i][j] = rand() % 10;
        }
    }

    // Presentar la matriz A
    for (int i = 0; i < f1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("%d", mA[i][j]);
        }
        printf("\n");
    }

    // Presentar la matriz B
    for (int i = 0; i < f1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("%d", mB[i][j]);
        }
        printf("\n");
    }

    // Declarar un entero que tenga el producto fxc
    int maxFC = f1 * c1;

    // Se declara el numero de threads de soze maxFC
    pthreads *hilos;
    hilos = (pthread_t *)malloc(maxFC * sizeof(pthread_t));

    int contador = 0;
    int *dato = NULL;

    for (int i = 0; i < f1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            // Almacenar filas y columnas en data (puntero)
            dato = (int *)malloc((24) * sizeof(int));
        }

        for (int k = 0; i < c1; k++)
        {
            dato[k + 1] = mA[i][k];
        }

        for (int k = 0; i < f2; k++)
        {
            dato[k+c1+1] = mB[k][j];
        }
        
        //Se crean los threads
        pthread_create(&hilos[contador++],NULL,multiplicacion,(void *)(dato));
    }

    // Presentar la matriz REsultado
    for (int i = 0; i < maxFC; i++)
    {
        //Joining hilos
        void *k;
        pthread_join(hilos[i],&k);
    }
    

    return o;
}