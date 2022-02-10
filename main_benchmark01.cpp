/* Fecha : 03-02-2022
   Autor : Leyder Jesus PAcheco Perez
   Materia : Computaci�n Paralela y Distribuida
   Tema : Construcci�n del Primer Benchmark
   Benchmark : Aplicaci�n de Juguete que permite evaluar rendimiento de un aspecto en espec�fico de la computadora */
   
   
#include <iostream>
#include <vector>
#include <random>
using namespace std;




double randomNUmber(double fMin, double fMax){
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}
	/* Funci�n Multiplicaci�n Matrices:
		Se requiere multiplicar las dos matrices : Adicionalmente 
		los ingenieros deben verificar y validar que realmente 
		se cumpla el algoritmo de multiplicaci�n */
vector<vector<double>> MultiMatriz(vector<vector<double>> Ma,
								   vector<vector<double>> Mb){
	int i,j,k;
	vector<vector<double>> Mresultado(Ma.size(),vector<double>(Ma.size(),0));					   	
	for(i=0;i<Ma.size();++i)
		for(j=0;j<Ma.size();++j)
			for(k=0;k<Ma.size();++k)
				Mresultado[i][j] += Ma[i][k] *Mb[k][j];
				
	return Mresultado;
}
		




/* Funci�n Inicializaci�n : Se requiere inicializar las matrices
   	con n�meros aleatorios */
vector<vector<double>> InicializacionMatriz(vector<vector<double>> M){
	int i,j;
	float limInf = 0.001 , limSup = 9.999;
	vector<vector<double>> Minicializada(M.size(), vector<double> (M.size(),0));
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(limInf,limSup);
	for(i=0;i<M.size();++i){
			for(j=0;j<M.size();++j){ 
				Minicializada[i][j] = dis(gen) ;
			}
		}
	return Minicializada;

}

		
		
		
/* Se crea la funci�n para imprimir matriz */
void imprimirMatriz(vector<vector<double>> M){
	int i,j;
	for(i=0;i<M.size();++i){
		for(j=0;j<M.size();++j){ 
			cout << M[i][j]<< "\t" ;
		}
		cout << "\n" ;
	}
	
}




/* Se requiere implementar una aplicaci�n que multiplique dos matrices
   Las matrices deben ser de doble precisi�n
   El algoritnmo a usar ser� el cl�sico (filas por columnas) */

int main(int argc, char *argv[]) {
	int i, j , k;
	int N = atoi(argv[1]); 
	
	/* Se usa la clase vector para crear las matrices */
	vector<vector<double>> M1(N,vector<double>(N,0));
	vector<vector<double>> M2(N,vector<double>(N,0));
	vector<vector<double>> MR(N,vector<double>(N,0));
	
	M1 = InicializacionMatriz(M1);
	M2 = InicializacionMatriz(M2);
	
			
	/*Se imprime M1 */
	cout << "Se imprime M1" << "\n";
	imprimirMatriz(M1);
	cout <<"\n \n \n" ;
	
	/*Se imprime M2 */
	cout << "Se imprime M2" << "\n";
	imprimirMatriz(M2);
	cout <<"\n \n \n" ;
	
	/*Se hace la multiplicaci�n */
	MR = MultiMatriz(M1,M2);
	
	/*Se imprime MR */
	cout << "Se imprime MR" << "\n";
	imprimirMatriz(MR);
	cout <<"\n \n \n" ;

}
