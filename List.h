#pragma once
#include "Nodo.h"
//las siguiente estructuras se tomaron de guia de la clase de teoria con el ingeniero brayan
//dejo links de ayudahttps://www.itsa.edu.co/docs/25-E-Arrieta-Manual-de-Estructura-de-Datos.pdf
//JOYANES Aguilar, Luis. Fundamentos de Programación: Algoritmos, estructuras de datos y objetos (4ta. Edición). Mc-Graw Hill. España, 2008.
class List
{
public:
	Nodo* first;
	Nodo* last;
	int count;

	List();
	void Insertstart(Cancion* value);
	void Insertend(Cancion* value);
	void Insertposition(Cancion* value, int position);
	Cancion* Extractstart();
	Cancion* Extractend();
	Cancion* Extractposition(int position);
	bool Listempty();
	Cancion* Getvalue(int position);
	Nodo* GetNodo(int position);
	int size();
	void Intercambiar(int pos1, int pos2);
	~List() {};

	void OrdenarArtistaAsendente();
	void OrdenarCancionAsendente();

	void OrdenarArtistaDescendente();
	void OrdenarCancionDescendente();
};