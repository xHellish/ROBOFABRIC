#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

// --------- Leer archivo TXT. ---------- // 
string* leerTXT(string ubicacion) {
    ifstream archivo(ubicacion.c_str());
    string linea;
    int contadorArray = 0;

    // Contar las l�neas en el archivo
    while (getline(archivo, linea)) {
        contadorArray++;
    }

    // Volver al inicio del archivo
    archivo.clear();
    archivo.seekg(0, ios::beg);

    string* datosTXT = new string[contadorArray];
    contadorArray = 0;
	
    while (getline(archivo, linea)) {
        cout << linea << endl;
        datosTXT[contadorArray] = linea;
        contadorArray++;
    }
    archivo.close();

    return datosTXT;
}
// ----- Analizar carpeta -----> Nombre de cada archivo ----- //
void analizarCarpeta(string rutaCarpeta) {

    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile((rutaCarpeta + "\\*").c_str(), &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                cout << findFileData.cFileName << endl;
            }
        } while (FindNextFile(hFind, &findFileData) != 0);
        FindClose(hFind);
    } else {
        cerr << "Error al abrir la carpeta" << endl;
    }
}

// --------- Timer ------------ //
void tick() {
    while (true) {
    	
        cout << "Tick" << endl;
        
        analizarCarpeta("C:/Users/Hellish/Desktop/Programa1_CPP/Sistema/Pedidos/Pendientes");
        
        sleep_for(seconds(1));
    }
}





