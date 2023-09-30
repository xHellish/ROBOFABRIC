#include <iostream>
#include "Funciones.h"

int main(int argc, char** argv) {
	/*
	//thread hiloTick(tick);
	
	string* array1 = leerTXT("C:/Users/Hellish/Desktop/Programa1_CPP/Sistema/Pedidos/Pendientes\\pedido1.txt");	
	//cout << array1[1];
	analizarCarpeta("C:/Users/Hellish/Desktop/Programa1_CPP/Sistema/Pedidos/Pendientes");
	
	//hiloTick.join();
	*/
	ListaString * ola = new ListaString();
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	ColaPedidos * cola = analizarCarpeta("C:/Users/Usuario/Desktop/robofabric/ROBOFABRIC/Sistema/Pedidos/Pendientes");
	cola->imprimir();

	extraerCliente("A002	ola		3")->imprimir();
	cout << endl;
	ListaCliente * clientes = agregarClientes("C:/Users/Usuario/Desktop/robofabric/ROBOFABRIC/Sistema\\Clientes.txt");
	clientes->imprimir();
	
	
	
	return 0;
}


