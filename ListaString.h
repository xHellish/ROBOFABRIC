#include <iostream>
#include <string>
using namespace std;

struct NodoStr{
	
	NodoStr* siguiente;
	string dato;
	
	NodoStr(string dato){
		siguiente = NULL;
		this->dato = dato;
	}
	
	void imprimir(){
        cout << dato << endl;  
	}
};

struct ListaString {
	
	NodoStr* pn; // Primer nodo.
	NodoStr* un; //Ultimo Nodo
	
	ListaString(){
		pn = NULL;
		un = NULL;
	}
	
	// ¿Está vacía?
	bool isEmpty(){
		 return pn == NULL;
	}
	
	// Insertar al final.
	void insertar(string datoStr){
		
		NodoStr* nuevo = new NodoStr(datoStr);
		
		if (isEmpty()){
			pn = un = nuevo;
			
		}else{
			un->siguiente = nuevo;
			un = nuevo;
		}
	}
	
	// Imprimir lista.
	void imprimir() {
        NodoStr* tmp = pn;
        while (tmp != NULL) {
            tmp->imprimir();
            tmp = tmp->siguiente;
        }
        cout << endl;
    }
};
