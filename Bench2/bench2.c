/*  UNiversidad Setgio Arboleda
    Fecha: 8-22-2022
    Autor: John Corredor
    Materia: Parallel Computing
    Tema: Implementacion benchmark en C
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>
#include <errno.h>

struct timespec start, endCount;
/*Inicio: medida de tiempo*/
void sampleStart()
{
    clock_gettime(CLOCK_MONOTONIC, &start);
}

/*Fin: medida de tiempo*/
void sampleEnd()
{
    clock_gettime(CLOCK_MONOTONIC, &endCount);
    /*Se imprime el tiempo*/
    double totalTime;
    totalTime = (endCount.tv_sec - start.tv_sec) * 1e9;
    totalTime = (totalTime + endCount.tv_nsec - start.tv_nsec) * 1e-9;
    printf("%f\n", totalTime);
}

/*More randomly*/
float randMM()
{
    float min = 0.001, max = 9.999;
    static int first = -1;
    if ((first = (first < 0)))
        srand(time(NULL) + getpid());
    if (min > max)
        return errno = EDOM, NAN;
    return min + (float)rand() / ((float)RAND_MAX / (max - min));
}

// Variable with high value to reserve memory

#define DATA_SZ (1024 * 1024 * 64 * 3)

// Its reserved the memory space taking into account DATA_SZ
static double MEM_CHUNK[DATA_SZ];

// Its created the function to initialize matrix
void initializeMatrix(int SZ, double *Ma, double *Mb, double *Mr)
{
    int i, j, k;
    for (i = 0; i < SZ; ++i)
    {
        for (j = 0; j < SZ; ++j)
        {
            Ma[j + i * SZ] = randMM();
            Mb[j + i * SZ] = randMM();
            Mr[j + i * SZ] = 0.0;
        }
    }
}

// Its implemented the print to validate data
void printMatrix(int SZ, double *Ma)
{
    int i, j, k;
    for (i = 0; i < SZ; ++i)
    {
        for (j = 0; j < SZ; ++j)
        {
            printf("%f  ", Ma[j + i * SZ]);
        }
        printf("\n");
    }
}

void MatrixMM(int size, double *Ma, double *Mb, double *Mr)
{
    int i, j, k;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            // Auxiliar pointers
            double *pA, *pB;
            double auxiliarSum = 0;
            pA = Ma + (i * size);
            pB = Mb + j;
            for (k = 0; k < size; k++, pA += size, pB++)
            {
                auxiliarSum += (*pA * *pB);
            }
            Mr[i * size + j] = auxiliarSum;
        }
    }
}
/**
 * Main function
 * @param argc that is the number of arguments
 * @param argv that is a vector with the arguments
 */
int main(int argc, char **argv)
{
    /*Its captured the dimesion of the matrix*/
    int N = (int)atof(argv[1]);
    printf("Valor ingresado %d\n", N);
    // create the pointers to the reserved memory with dimension NxN
    double *Ma, *Mb, *Mr;
    Ma = MEM_CHUNK;
    Mb = Ma + N * N;
    Mr = Mb + N * N;
    initializeMatrix(N, Ma, Mb, Mr);
    printf("\nMatriz A\n");
    printMatrix(N, Ma);
    printf("\nMatriz B\n");
    printMatrix(N, Mb);
    MatrixMM(N, Ma, Mb, Mr);
    printf("\nMatriz resultante\n");
    printMatrix(N, Mr);

    return 0;
}
