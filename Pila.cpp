#include "Pila.h"
// las siguiente estructuras se tomaron de guia de la clase de teoria con el ingeniero brayan
//dejo links de ayudahttps://www.itsa.edu.co/docs/25-E-Arrieta-Manual-de-Estructura-de-Datos.pdf
Pila::Pila() {
	list = new List();
}

Pila::~Pila() {
	delete list;
}

void Pila::push(Cancion* value) {
	list->Insertend(value);
}

Cancion* Pila::pop() {
	return list->Extractend();
}

bool Pila::stackempty() {
	return list->Listempty();
}

int Pila::size()
{
	return list->size();
}

Cancion* Pila::peak()
{
	return list->Getvalue(list->size() - 1);
}

Cancion* Pila::GetValue(int position)
{
	return list->Getvalue(position);
}

void Pila::OrdenarArtistaAsendente()
{
	list->OrdenarArtistaAsendente();
}
void Pila::OrdenarCancionAsendente()
{
	list->OrdenarCancionAsendente();
}

void Pila::OrdenarArtistaDescendente()
{
	list->OrdenarArtistaDescendente();
}
void Pila::OrdenarCancionDescendente()
{
	list->OrdenarCancionDescendente();
}