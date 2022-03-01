/*
 * Date: 2022-02-01
 * Author: Leyder Jesus Pacheco Pèrez
 * Course: Paralell and Distributed Computing
 * Topic: build of first benchmark
 * Benchmark: toy app thath allows to meausre performance
 * of a specific aspet of the computer
 *
 * to compile: g++ -g MyProgram3.cpp -o MiPrograma3
 */

/* Its required to impolement an app that multiply 2 matrixes
   the algorithm to use will be the clasic (rows * columns)
*/

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <unistd.h>
#include <cstring>
#include <math.h>
using namespace std;

/*Definicion de constantes*/
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
void multiMatrix(vector<vector<double>> Ma, vector<vector<double>> Mb)
{
    vector<vector<double>> MResult(Ma.size(), vector<double>(Ma.size(), 0));
    /* Hacemos una punta de prueba para tomae tiempo inicial*/
    int i,j,k;

    for (i = 0; i < Ma.size(); i++)
    {
        for (j = 0; j < Ma.size(); j++)
        {
            for (k = 0; k < Ma.size(); k++)
            {
                MResult[i][j] += Ma[i][k] * Mb[k][j];
            }
        }
    }
}
/**
 * @brief Function that generates a random value
 *
 * @param fMin that is the lower limit of the random value
 * @param fMax that is the higher limit of the random value
 * @return a double value between fMin and fMax
 */
double randomNumber(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
/**
 * Function that generates a matrix with truly random values
 * @param N that is the size of the matrix
 * @return a matrix with random values
 */
vector<vector<double>> generateMatrix(int N)
{
    int i,j;
    vector<vector<double>> M(N, vector<double>(N, 0));
    double lower_bound = 0.001, upper_bound = 9.999;
    // default_random_engine generator;
    // uniform_real_distribution<double> distribution(lower_bound,upper_bound);

    for (i = 0; i < M.size(); i++)
    {
        for (j = 0; j < M.size(); j++)
        {
            M[i][j] = randMM();
        }
    }
    return M;
}

/**
 * Function that prints in console a matrix
 * @param M that its the matrix will be printed
 */

void printMatrix(vector<vector<double>> M)
{
    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M.size(); j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 * Main function
 * @param argc that is the number of arguments
 * @param argv that is a vector with the arguments
 */
int main(int argc, char **argv)
{
    srand(time(NULL));
    int i, j, k;
    int N = atoi(argv[1]);
    /*It is used the vector class to create the matrixes*/
    cout << "Número ingresado: " << N << endl;
    vector<vector<double>> M1(N, vector<double>(N, 0));
    vector<vector<double>> M2(N, vector<double>(N, 0));
    vector<vector<double>> MR(N, vector<double>(N, 0));
    M1 = generateMatrix(N);
    M2 = generateMatrix(N);
    /*
    // Se imprime M1
    cout << "Se imprime M1" << endl;
    printMatrix(M1);
    cout << endl
         << endl
         << endl;
    // Se imprime M2
    cout << "Se imprime M2" << endl;
    printMatrix(M2);
    cout << endl
         << endl
         << endl;
    MR = multiMatrix(M1, M2);
    // Se imprime MR
    cout << "Se imprime MR" << endl;
    cout << endl
         << endl
         << endl;
    printMatrix(MR);
    */
   SampleStart();
   multiMatrix(M1, M2);
   SampleEnd();
}