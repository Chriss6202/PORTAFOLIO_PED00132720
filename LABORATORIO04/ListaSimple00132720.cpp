#include <iostream>
#include <conio.h>
using namespace std;

struct nodo{
    int numero;
    nodo* sig;
};

class ManejoListaSimple{
    private:
    nodo* pInicio;

    public:
    ManejoListaSimple(){
        pInicio=NULL;        
    }
    ~ManejoListaSimple(){
        nodo *p;

        while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
    }
    void Recdato();
    void Insdato(int dato);
    void Mostrardato();
    void Borrarnodos(int datoref);
    void DesplegarPar();
    void DesplegarImpar();
};

void  ManejoListaSimple::Recdato(){
    
    int dato;
    bool cont=1;
    
    cout << "Introduzca un numero"<<endl;
    while(cont != 0){
        cin >> dato;
        Insdato(dato);
        cout << "Quiere introducir mas datos? Si = 1, No = 0 ";
        cin >> cont;
    }
}

void ManejoListaSimple::Insdato(int dato){
    nodo* nuevo;
    nuevo = new nodo;
    nuevo->numero = dato;
    nuevo->sig = pInicio; 
    pInicio = nuevo;
}

void ManejoListaSimple::Mostrardato(){
    nodo* aux;
    aux = pInicio;
    cout << "Los datos de la lista son: " << endl;
    while(aux)
    {
        cout << aux->numero <<endl;
        aux = aux->sig;
    };
    
}

void ManejoListaSimple::Borrarnodos(int datoref){
    nodo* aux1, *ant=NULL;
    
    aux1 = pInicio;

    while(aux1!= NULL && aux1->numero != datoref){    
    ant = aux1;
    aux1 = aux1 ->sig;
    }
    if(aux1==NULL){

    }
    else if(ant==NULL){
        pInicio = pInicio -> sig;
        delete aux1;
        Borrarnodos(datoref);   
    }
    else{
        ant->sig = aux1->sig;
        delete aux1;
        Borrarnodos(datoref); 
        }
}


void ManejoListaSimple::DesplegarPar(){
    nodo* aux;
    aux = pInicio;
    cout << "Los datos de la lista pares son: " << endl;
    while(aux)
    {
        if(aux->numero % 2==0){
        cout << aux->numero <<endl;
        aux = aux->sig;
    }
        else{
        aux = aux->sig;   
        }
    };
}

void ManejoListaSimple::DesplegarImpar(){
    nodo* aux;
    aux = pInicio;
    cout << "Los datos de la lista impares son: " << endl;
    while(aux)
    {
        if(aux->numero % 2!= 0){
        cout << aux->numero <<endl;
        aux = aux->sig;
    }
        else{
        aux = aux->sig;   
        }
    };
}


int main(){
    
    ManejoListaSimple ML;
    int datoref=0;
    cout << "\nLista simple, datos pares e impares."<<endl;
    ML.Recdato();
    ML.Mostrardato();

    cout << "Introduzca el dato a borrar: " << endl;
    cin >> datoref;
    
    ML.Borrarnodos(datoref);
    ML.Mostrardato();
    ML.DesplegarPar();
    ML.DesplegarImpar();
    
    getch();
}

