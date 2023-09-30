#include <iostream>
#include "Funciones.h"


int main(int argc, char** argv) {
	
	//thread hiloTick(tick);
	
	string* array1 = leerTXT("C:/Users/Hellish/Desktop/Programa1_CPP/Sistema/Pedidos/Pendientes\\pedido1.txt");	
	//cout << array1[1];
	analizarCarpeta("C:/Users/Hellish/Desktop/Programa1_CPP/Sistema/Pedidos/Pendientes");
	
	//hiloTick.join();
	
	return 0;
}


