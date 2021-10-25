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
	
//Un m�todo Get es por lo general un m�todo con una sola l�nea de c�digo que retorna el valor actual de la variable privada. Tiene valor de retorno del mismo tipo de la variable en cuesti�n y en general no tiene par�metros de entrada.

//Por otra parte, un m�todo Set es un m�todo en el cual por lo menos una de las l�neas de c�digo modifica directamente el valor de la variable privada.Es poco usual que tenga valor de retorno, pero s� debe tener por lo menos un par�metro de entrada para el valor con el que se modificar� la variable.
};