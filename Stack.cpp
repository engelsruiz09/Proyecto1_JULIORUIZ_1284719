#include "Stack.h"
// las siguiente estructuras se tomaron de guia de la clase de teoria con el ingeniero brayan
//dejo links de ayudahttps://www.itsa.edu.co/docs/25-E-Arrieta-Manual-de-Estructura-de-Datos.pdf
Stack::Stack() {
	list = new List();
}

void Stack::push(Cancion* value) {
	list->Insertend(value);
}

Cancion* Stack::pop() {
	return list->Extractend();
}

bool Stack::stackempty() {
	return list->Listempty();
}

Stack::~Stack() {
	delete list;
}