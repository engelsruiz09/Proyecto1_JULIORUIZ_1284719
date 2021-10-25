#include "Ordenamientos.h"
static int Ascendente(std::string x, std::string y) {
	if (x > y)
		return 1;
	if (x == y)
		return 0;
	if (x < y)
		return -1;
}

static int Descendente(std::string x, std::string y) {
	if (x < y)
		return 1;
	if (x == y)
		return 0;
	if (x > y)
		return -1;
}

void Ordenamientos::BubbleSort(Cancion** vectcanciones[], int n) {
	int i = n - 1;
	int indiceintcambio;
	while (i > 0)
		indiceintcambio = 0;
	for (int j = 0; j < i; j++)
		if (vectcanciones[j] > vectcanciones[j + 1])
			int aux = vectcanciones[j];
			vectcanciones[j] = vectcanciones[j + 1];
			vectcanciones[j + 1] = aux;
			indiceintcambio = j;

	i = indiceintcambio;
}