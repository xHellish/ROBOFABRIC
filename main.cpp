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
	/*
	ola->insertar("ola");
	ola->insertar("ola1");
	ola->insertar("ola2");
	ColaPedidos * pedidos = new ColaPedidos();
	pedidos->encolar(new Nodo("Terminal", ola));
	pedidos->imprimir();
	*/
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
	ColaPedidos * cola = analizarCarpeta("C:/Users/Usuario/Desktop/robofabric/ROBOFABRIC/Sistema/Pedidos/Pendientes");
	cola->imprimir();
	
	
	return 0;
}


