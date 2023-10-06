#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>

#include "ColaPedidos.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

//Convertir string a integer--------------------
int strToInt(string str){
	int result = 0;
	int i = 0;
	while (i < str.length() && isdigit(str[i])) {
		if (i != ' '){
			result = result * 10 + (str[i] - '0');	
		}
        
        i++;
    }
    return result;
}

// --------- Leer archivo TXT. ---------- // 
ListaString* leerTXT(string ubicacion) {
    ifstream archivo(ubicacion.c_str());
    string linea;
	ListaString* datosPedidoLista = new ListaString();

    // Volver al inicio del archivo
    archivo.clear();
    archivo.seekg(0, ios::beg);
    
	//Insertar lineas a la lista
    while (getline(archivo, linea)) {
        datosPedidoLista->insertar((string)linea);
    }
    archivo.close();
    
    return datosPedidoLista;
}
// ----- Analizar carpeta -----> Nombre de cada archivo ----- //
ColaPedidos * analizarCarpeta(string rutaCarpeta) {

    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile((rutaCarpeta + "\\*").c_str(), &findFileData);
	
	ColaPedidos* colaPendientes = new ColaPedidos();
	
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            	ListaString * lista = leerTXT(rutaCarpeta+"\\"+findFileData.cFileName);
                colaPendientes->encolar(new Nodo(findFileData.cFileName, lista));
				  
            }
        } while (FindNextFile(hFind, &findFileData) != 0);
        FindClose(hFind);
    } else {
        cerr << "Error al abrir la carpeta" << endl;
    }
    
	return colaPendientes;
  
}

// Extraer los datos del cliente de la linea del txt---------------------
Cliente * extraerCliente(string linea){
	string codigo = "";
	string nombre = "";
	int prioridad = 0;
	
	int cont = 0;
	string dato = "";
	
	while(linea != "" ){
		char letra = linea[0];
		linea = linea.substr(1);
		if (letra != '\t') {
			dato += letra;
		}
		
		else {
			if (cont == 0) codigo = dato;
			else if (cont == 1) nombre = dato;
			dato = "";
			cont ++;
		}
	} 
	prioridad = strToInt(dato);
	return new Cliente(codigo, nombre, prioridad);
}

//------Agregar cliente del txt a la lista de clientes-------//
ListaCliente * agregarClientes(string ubicacion){
	ListaCliente * clientes = new ListaCliente();
	
	ListaString * stringClientes = leerTXT(ubicacion);
	NodoStr * tmp = stringClientes->pn;
	while (tmp != NULL) {
        clientes->insertarAlFinal(extraerCliente(tmp->dato));
        tmp = tmp->siguiente;
    }
    return clientes;
}

// ------------ Cliente prio ------------ //
int clientePrio(string nombreCliente){
	
	
	ListaString* clientes = leerTXT("C:\\Users\\Hellish\\Desktop\\Programa1_CPP\\ROBOFABRIC\\Sistema\\Clientes.txt");
	clientes->imprimir();
	
	int prio = clientes->prioCliente(nombreCliente);
	
	
	
	return prio;
}

// --------- Timer ------------ //
void tick() {
    while (true) {
    	
        cout << "Tick" << endl;
        
        analizarCarpeta("C:/Users/Hellish/Desktop/Programa1_CPP/Sistema/Pedidos/Pendientes");
        
        sleep_for(seconds(1));
    }
}





