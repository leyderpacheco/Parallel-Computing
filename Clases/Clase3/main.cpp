/*Materia : Computacion Paralela
 *Fecha : 1/2/2022
 *Autor : Leyder Pacheco
 *Tema : Mini benchmark
*/

/*Se declaran las interfaces*/
#include <iostream>
/*definicion funcion lambda para calculo de bites*/
#define SIZEBITES(X) sizeof(X)*8
/*Se declara el espacio de dominio*/
using namespace std;

int main() {
	cout<<"========================================================================================================="<<endl;
	cout<<"	Type		|		Meaning		|		Bytes		|	bites	|"<<endl;
	cout<<"========================================================================================================="<<endl;
	cout<<"	bool		|	boolean			|		 "<< sizeof(bool) << "		|	  "<<SIZEBITES(bool)<< "	|"<< endl;
	cout<<"	char		|	Character		|		 "<< sizeof(char) << "		|	  "<<SIZEBITES(char)<< "	|"<< endl;
	cout<<"	wchar_t		|	wide character		|		 "<< sizeof(wchar_t) << "		|	 "<<SIZEBITES(wchar_t)<<"	|"<< endl;
	cout<<"	char16_t	|	unicode character	|		 "<< sizeof(char16_t) << "	| 	 "<<SIZEBITES(char16_t)<< "	|"<< endl;
	cout<<"	char32_t	|	unicode character	|		 "<< sizeof(char32_t) << "		|	 "<<SIZEBITES(char32_t)<< "	|"<< endl;
	cout<<"	int		|	Integer			|		 "<< sizeof(int) << "		|	 "<<SIZEBITES(int)<< "	|"<< endl;
	cout<<"	long		|	long Integer		|		 "<< sizeof(long) << "		|	 "<<SIZEBITES(long)<< "	|"<< endl;
	cout<<"	long long	|	long long Integer	|		 "<< sizeof(short) << "		|	 "<<SIZEBITES(short)<< "	|"<< endl;
	cout<<"	float		|Single precision float point	|		 "<< sizeof(float) << "		|	 "<<SIZEBITES(float)<< "	|"<< endl;
	cout<<"	double		|double precision float point	|		 "<< sizeof(double) << "		|	 "<<SIZEBITES(double)<< "	|"<< endl;
	cout<<"	long double	|extend precision float point	|		"<< sizeof(long double) << "		|	"<<SIZEBITES(long double)<< "	|"<< endl;
	cout<<"========================================================================================================="<<endl;
}
	
	

