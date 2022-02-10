/*	Fecha: 3-2-2022
	Autor: Leyder Pacheco
	Materia: Computacion Paralela Y Distribuida
	Tema: Construccion del Primer Benchmark
	Benchmark: Aplicacion de Juguete que permite evaluar rendimiento
	de un aspecto en especifico de la computadora */
	
#include <iostream>
#include <vector>
#include <random>
using namespace std;

/*	Funcion inicializacion: S requiere inicializar las matrices
	con numeros aleatros */
vector<vector<double>> InicializacionMatriz(vector<vector<double>> M){
	int i,j;
	float liminf = 0.001, limsup = 9.999;
	vector<vector<double>> Minicializada(M.size(), vector<double> (M.size()),0));
	random_device rd; //Se usa para inicializar
	mt19937 gen(rd());
	uniform_real_distribution<> dis(liminf, limsup);
}
	

/* Se requiere una aplicacion que multiplique dos matrices.
	El algoritmo a usar será el clasico(filas por columnas) */

void ImprimirMatriz(vector<vector<double>> M){
	int i,j;
	
	for(i=0;i<M.size();i++){
		for(j=0;j<M.size();j++){
		cout << M[i][j] << "\t";
	
		}
		cout << "\n";
	}
}
int main(int argc, char** argv) {
	int i,j,k;
	int N = atoi(argv[1]);
	
	/*	Se usa la clase vector para crear las matrices */
	vector<vector<double>> M1(N,vector<double>(N,0));
	vector<vector<double>> M2(N,vector<double>(N,0));
	
	
	/* Se requiere inicializar las matrices con numeros aleatorios */
	
	
	ImprimirMatriz(M1);
	cout << "\n \n \n";
	
	ImprimirMatriz(M2);
	
	
	/* Se requiere multiplicar las dos matrices: adicionalmente los ingenieros deben verificar
	y validar que realmente se cumple el algoritmo de multiplicacion */
	
	return 0;
}
