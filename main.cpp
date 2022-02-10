#include<iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[])
{
   int n, nt;
   cout<<"Ingrese el numero de filas"<<endl;
   cin>>n;

  for (int i = 0; i < n; i++)
  {
      nt=1;

      for (int j = 0; j <= i; j++)
      {
          cout<<nt<< " ";
          nt= nt * (i-j)/(j+1);
      }

      cout<<"\n";
      

  }



    
}
