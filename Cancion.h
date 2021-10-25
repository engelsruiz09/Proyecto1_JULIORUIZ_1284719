#pragma once
#include <iostream>
using namespace std;
class Cancion
{
private:
	string nombre;
	string artista;
public:
	//int value;
	Cancion* next;
	Cancion();
	~Cancion();
	Cancion(string nombre, string artista);

	//get  para obtener el valor de una propiedad y set para asignar el valor a una propiedad
	string GetNombre();
	string GetArtista();

	void SetNombre(string valor);
	void SetArtista(string valor);

	string ToString();//da un texto que tiene los datos del objeto 
	
//Un método Get es por lo general un método con una sola línea de código que retorna el valor actual de la variable privada. Tiene valor de retorno del mismo tipo de la variable en cuestión y en general no tiene parámetros de entrada.

//Por otra parte, un método Set es un método en el cual por lo menos una de las líneas de código modifica directamente el valor de la variable privada.Es poco usual que tenga valor de retorno, pero sí debe tener por lo menos un parámetro de entrada para el valor con el que se modificará la variable.
};