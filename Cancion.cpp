#include "Cancion.h"
Cancion::Cancion(string nombre, string artista)
{
	this->nombre = nombre;
	this->artista = artista;
	//this este puntero es un parámetro implícito a todas las funciones miembro. Por lo tanto, dentro de una función miembro, esto puede usarse para referirse al objeto que invoca.
}
Cancion::Cancion() {
	next = nullptr;
}
Cancion::~Cancion() {
	next = nullptr;
}

string Cancion::GetNombre()
{
	return this->nombre;
}
string Cancion::GetArtista()
{
	return this->artista;
}

void Cancion::SetNombre(string valor)
{
	this->nombre = valor;
}
void Cancion::SetArtista(string valor)
{
	this->artista = valor;
}

string Cancion::ToString()
{
	return nombre + " - " + artista;//retorna como quiere que se mire en el listbox
}