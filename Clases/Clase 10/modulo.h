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
#ifndef MODULO_H_INCLUDED
#define MODULO_H_INCLUDED

#include "modulo.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>





void *multiplicacion(void *arg);

#endif