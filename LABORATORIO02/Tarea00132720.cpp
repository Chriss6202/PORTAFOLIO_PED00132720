#include "iostream"
#include "cmath"
#include "math.h"
#include "conio.h"
using namespace std;

int a,b,c=1, temporal, A, B;
bool mayor;

int intro();

int calculo();

int intro()
{
cout<<"Introduzca el valor del primer entero (Este tiene que ser mayor que el segundo) ";
cin>> a;
cout<<endl<<"Introduzca el valor del segundo entero (Este tiene que ser mayor que el segundo) ";
cin>> b;
cout<<endl<<endl;

A=a;
B=b;
}

int calculo()
{

if(!c==0)//Se revisa si c (el residuo) ha llegado a 0, pues, en dicho caso, ya se tiene el MCD
{
c=a-b;
a=b;
b=c; //a se vuelve b y b se vuelve c
mayor=a>=b?0:1; // si a es mayor o igual que b, las variables se mantienen, en caso contrario, se deben invertir.
if (mayor == 1)
{
temporal=a;
a=b;
b=temporal;
}
calculo();
}
else
{
cout<<"El MCD de "<< A << " y "<< B << " es "<< a;
}
}

int main()
{
c = 1;

cout<<      "-------------------------------------------------------------------------";
cout<<endl<<"Algoritmo de Euclides (Calcular el maximo comun multiplo de dos enteros)."<<endl;
cout<<      "-------------------------------------------------------------------------"<<endl<<endl;
intro();

    if(a<b)
{
cout<<"El primer entero introducido es menor que el segundo, por favor, intentelo de nuevo"<<endl;
intro();

}

calculo();
cout<<endl<<endl<<"Si quiere realizar un nuevo calculo, presione 0, si quiere cerrar el programa, presione cualquier numero"<<endl;
cin>>mayor;

if(mayor==0)
{main();}



}
