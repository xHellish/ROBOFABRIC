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

// --------- Timer ------------ //
void tick() {
    while (true) {
    	
        cout << "Tick" << endl;
        
        analizarCarpeta("C:/Users/Hellish/Desktop/Programa1_CPP/Sistema/Pedidos/Pendientes");
        
        sleep_for(seconds(1));
    }
}





