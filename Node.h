#pragma once
#include "Cancion.h"
// las siguiente estructuras se tomaron de guia de la clase de teoria con el ingeniero brayan
//dejo links de ayudahttps://www.itsa.edu.co/docs/25-E-Arrieta-Manual-de-Estructura-de-Datos.pdf
//JOYANES Aguilar, Luis. Fundamentos de Programaci�n: Algoritmos, estructuras de datos y objetos (4ta. Edici�n). Mc-Graw Hill. Espa�a, 2008.
class Node
{
public:
	Cancion* value;//variable 
	Node* next;//un nodo que apunte al siguiente

	Node();//constructor
	~Node();//destructor
};
