#pragma once
#include "List.h"
#include "Cancion.h"
class Ordenamientos
{
public:
	Ordenamientos();
public:
	void BubbleSort(Cancion** vectcanciones[], int n);
	void Cambiarpos(Cancion** vectcanciones[], int left, int right);
};

