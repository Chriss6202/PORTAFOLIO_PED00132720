#include <iostream>
using namespace std;

//Estructuras y clase del programa

struct estudiante {
    string nombre, curso, horas;
    int carnet;
};

struct nodo {
    estudiante datosEstudiante;
    nodo* sig;
};

class manejoEstudiante {
    private: 
        nodo *pPila, *pCola;
        void pilaDatosIns(estudiante ez);
        void colaDatosIns(estudiante ez);

    public:
        manejoEstudiante() {
            pPila = NULL;
            pCola = NULL;
        }
        ~manejoEstudiante() {
            delete pPila;
            delete pCola;
        }

        void pilaDatos();
        void colaDatos();

        void filtrarDatos(int carnet);
        void mostrarEstudiante();
        void mostrarEstudiante2();
       
};

//Recoleccion de datos de los estudiantes

void manejoEstudiante::pilaDatos() {
    estudiante ez;
    int masDatos = 0;

    do {
        cout << "Carnet: "; cin >> ez.carnet;
        cin.clear(); cin.ignore(1000, '\n');

        cout << "Nombre: "; cin >> ez.nombre;
        
        cout << "Horas sociales: "; cin >> ez.horas;
     
        cout << "Anio de estudio: "; cin >> ez.curso;

        pilaDatosIns(ez);

        cout << "Mas datos (0 = No, 1 = Si) "; cin >> masDatos;

    }while(masDatos != 0);
}

void manejoEstudiante::colaDatos () {
    estudiante ez;
    int masDatos = 0;

    do {
        cout << "Carnet: "; cin >> ez.carnet;
        cin.clear(); cin.ignore(1000, '\n');

        cout << "Nombre: "; cin >> ez.nombre;
        cout << "Horas sociales: "; cin >> ez.horas;
        cout << "Anio de estudio: "; cin >> ez.curso;

        colaDatosIns(ez);

        cout << "Mas datos (0 = No, 1 = Si) "; cin >> masDatos;

    }while(masDatos != 0);
};

//Organizacion de los datos de los estudiantes en los nodos

void manejoEstudiante::pilaDatosIns(estudiante ez) {
    nodo* n = new nodo;
    n->datosEstudiante = ez;
    n->sig = pPila;
    pPila = n;
}

void manejoEstudiante::colaDatosIns(estudiante ez) {
    nodo* n = new nodo;
    n->datosEstudiante = ez;
    n->sig = NULL;

    if(!pCola)
        pCola = n;
    else {
        nodo* aux = pCola;

        while(aux->sig)
            aux = aux->sig;
        
        aux->sig = n;
    }
}

//Busqueda por carnet

void manejoEstudiante::filtrarDatos(int carnet) {
    bool encontrado = false;

    nodo* aux = pPila;

    while(aux) {
        if(aux->datosEstudiante.carnet == carnet) {
            cout << "Nombre: "<< aux->datosEstudiante.nombre<<endl;
            cout << "Horas sociales: "<< aux->datosEstudiante.horas<<endl;
            cout << "Anio de estudio: "<< aux->datosEstudiante.curso<<endl<<endl;

            encontrado = true;
            break;
        }
        aux = aux->sig;
    }

    if(encontrado)
        return;
        
    
    aux = pCola;

    while(aux) {
        if(aux->datosEstudiante.carnet == carnet) {
        cout << "Nombre: "<< aux->datosEstudiante.nombre<<endl;
            cout << "Horas sociales: "<< aux->datosEstudiante.horas<<endl;
            cout << "Anio de estudio: "<< aux->datosEstudiante.curso<<endl<<endl;

            encontrado = true;
            break;
        }
        aux = aux->sig;
    }

    if(!encontrado)
        cout << "No se ha encontrado al alumno que esta buscando" << endl;
} 

//Impresion de la informacion de los estudiantes

void manejoEstudiante::mostrarEstudiante() {
    nodo* aux = pPila;

    while(aux) {
        cout << "Carnet: " << aux->datosEstudiante.carnet << endl;
        cout << "Nombre: " << aux->datosEstudiante.nombre << endl;
        cout << "Curso: " << aux->datosEstudiante.curso << endl;
        cout << "Horas sociales: " << aux->datosEstudiante.horas << endl << endl;

        aux = aux->sig;
    }
}

void manejoEstudiante::mostrarEstudiante2() {
    nodo* aux = pCola;

    while(aux) {
        cout << "Carnet: " << aux->datosEstudiante.carnet << endl;
        cout << "Nombre: " << aux->datosEstudiante.nombre << endl;
        cout << "Curso: " << aux->datosEstudiante.curso << endl;
        cout << "Horas sociales: " << aux->datosEstudiante.horas << endl << endl;

        aux = aux->sig;
    }
}

int main() 
{
    manejoEstudiante ez;

    int opcion = 0, Buscarnet = 0;

    do{
        cout << "\tRegistro estudiantil de la universidad Jose Simeon Canias (UCA)" << endl;
        cout << "1. Ingresar estudiante" << endl;
        cout << "2. Ingresar orden de llegada de estudiantes" << endl;
        cout << "3. Buscar estudiante mediante su carnet" << endl;
        cout << "4. Ver todos los estudiantes" << endl;
        cout << "5. Ver orden de salida de los estudiantes" << endl;
        cout << "6. Salir" << endl;
        cout << "Su opcion: "; cin >> opcion;

        cin.clear(), cin.ignore(1000, '\n');

        switch (opcion) {
        case 1:
            ez.pilaDatos();
            break;
        case 2:
            ez.colaDatos();
            break;
        case 3:
            cout << "Carnet del estudiante: "; cin >> Buscarnet;
            ez.filtrarDatos(Buscarnet);
            break;
        case 4:
            cout << "\tEstudiantes Registrados" << endl<<endl;
            ez.mostrarEstudiante();
            break;
        case 5:
            cout << endl << "\tOrden de salida de los Estudiantes:" << endl<<endl;
            ez.mostrarEstudiante2();    
        default:
            break;
        }
    } while(opcion != 6);

    return 0;
}