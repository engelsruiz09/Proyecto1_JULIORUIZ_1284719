#pragma once
// las siguiente estructuras se tomaron de guia de la clase de teoria con el ingeniero brayan
//dejo links de ayudahttps://www.itsa.edu.co/docs/25-E-Arrieta-Manual-de-Estructura-de-Datos.pdf
//JOYANES Aguilar, Luis. Fundamentos de Programaci�n: Algoritmos, estructuras de datos y objetos (4ta. Edici�n). Mc-Graw Hill. Espa�a, 2008.
#include "List.h";
class Stack
{
private:
	List* list;
public:
	Stack();
	Cancion* pop();
	void push(Cancion* value);
	bool stackempty();
	~Stack();
};
