#pragma once
// las siguiente estructuras se tomaron de guia de la clase de teoria con el ingeniero brayan
// //dejo links de ayudahttps://www.itsa.edu.co/docs/25-E-Arrieta-Manual-de-Estructura-de-Datos.pdf
#include "List.h";
class Queue
{
private:
	List* list;
public:
	void enqueue(Cancion* value);
	Cancion* dequeue();
	bool queueempty();
	Queue();
	~Queue();
};

