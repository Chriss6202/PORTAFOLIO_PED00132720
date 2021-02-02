#include <iostream>
#include <conio.h>
using namespace std;

struct nodo{
    int numero;
    nodo* sig, *ant;
};

class ManejoListaDoble{
    private:
    nodo* pInicio;

    public:
    ManejoListaDoble(){
        pInicio = NULL;
    }
    ~ManejoListaDoble(){
        nodo *p;

        while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
    }

    void RecDatosListadoble();
    void Insdatodoble(int dato);
    void Mostrardato();
    void EliminarDato(int Datoref);
};

void ManejoListaDoble::RecDatosListadoble(){
    int dato;
    bool tru;
    do{
        cout<<"Inserte un numero: ";
        cin >> dato;
        Insdatodoble(dato);
        cout<<"Quiere introducir mas datos? (Si=0, No=1) ";
        cin >> tru;
    }while(tru!=1);

}

void ManejoListaDoble::Insdatodoble(int dato){
    nodo* nuevo;
    nuevo = new nodo;
    nuevo->numero = dato;
    nuevo->ant = NULL;
    nuevo->sig = pInicio;
    if(nuevo->sig) nuevo->sig->ant = nuevo;
    pInicio = nuevo;
}

void ManejoListaDoble::Mostrardato(){
    nodo* aux;
    aux = pInicio;
    while(aux){
        cout << aux->numero << endl;
        aux = aux->sig;
    }
}

void ManejoListaDoble::EliminarDato(int datoref){
    nodo* p, *s=NULL, *r;
    p=pInicio;

    while(p->numero!=datoref && p!=NULL){
        s = p;
        p = p->sig;
    }
    if(p==NULL){
        cout<<"No se ha encontrado el elemento";
    }
    if(p->ant==NULL){
        cout<<"No hay un elemento detras del elemento referenciado"<<endl;
    }
    else{
        r = s->ant;
        if (r==NULL){
            pInicio = p;
            p->ant = NULL;
            delete s;
        }
        else{
        r->sig = s->sig;
        p->ant = s->ant;
        delete s;
        }
    }


}
int main(){
    
    ManejoListaDoble MD;
    int datoref=0;

    cout << "\nLista Doblemente enlazada"<<endl;
    MD.RecDatosListadoble();
    MD.Mostrardato();

    cout << "Inserte el dato cuyo dato anterior quiere borrar: ";
    cin >> datoref;
    MD.EliminarDato(datoref);
    MD.Mostrardato();
    getch();
}