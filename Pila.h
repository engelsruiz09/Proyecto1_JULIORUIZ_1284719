#pragma once
// las siguiente estructuras se tomaron de guia de la clase de teoria con el ingeniero brayan
//dejo links de ayudahttps://www.itsa.edu.co/docs/25-E-Arrieta-Manual-de-Estructura-de-Datos.pdf
//JOYANES Aguilar, Luis. Fundamentos de Programación: Algoritmos, estructuras de datos y objetos (4ta. Edición). Mc-Graw Hill. España, 2008.
#include "List.h";
class Pila
{
private:
	List* list;
public:
	Pila();
	~Pila();
	Cancion* pop();
	void push(Cancion* value);
	bool stackempty();
	int size();
	Cancion* peak();
	Cancion* GetValue(int position);

	void OrdenarArtistaAsendente();
	void OrdenarCancionAsendente();

	void OrdenarArtistaDescendente();
	void OrdenarCancionDescendente();
};
