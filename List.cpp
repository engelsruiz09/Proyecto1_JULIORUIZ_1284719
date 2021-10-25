#include "List.h"
//JOYANES Aguilar, Luis. Fundamentos de Programación: Algoritmos, estructuras de datos y objetos (4ta. Edición). Mc-Graw Hill. España, 2008.
//se tomo de guia el codigo mostrado en la clase de teoria
List::List() {
	first = nullptr;
	last = nullptr;
	count = 0;

};

void List::Insertstart(Cancion* value) {
	this->Insertposition(value, 0);//los elementos en una lista ordenada  en realidad el orden en el que aparece entonces se inserta al incio
}
void List::Insertend(Cancion* value) {
	this->Insertposition(value, count);
}
void List::Insertposition(Cancion* value, int position) {
	Nodo* new_node = new Nodo();
	new_node->value = value;

	if (first)
	{
		Nodo* pretemp = first;
		Nodo* temp = first->next;
		int index = 0;
		while ((temp) && (index < position)) {
			pretemp = temp;
			temp = temp->next;
			index++;
		}
		new_node->next = temp;
		pretemp->next = new_node;
	}
	else
		first = new_node;

	count++;
}

Cancion* List::Extractstart() {
	return this->Extractposition(0);
}
Cancion* List::Extractend() {
	return this->Extractposition(count - 1);
}
Cancion* List::Extractposition(int position) 
{
	if (!(position >= 0 && position < count))
		return nullptr;

	Nodo* temp = first;
	if (!Listempty()) {
		Nodo* pretemp = nullptr;
		int index = 0;
		while ((temp) && (index < position)) {
			pretemp = temp;
			temp = pretemp->next;
			index++;
		}

		count--;

		if (temp)
		{
			Cancion* cancion = temp->value;
			if (pretemp)
				pretemp->next = temp->next;
			else
				first = temp->next;
			return cancion;
		}
		else
		{
			Cancion* cancion = pretemp->value;

			Nodo* temp = first;
			while (temp->next != pretemp) {
				pretemp = temp;
				temp = pretemp->next;
			}
			temp->next = nullptr;

			return cancion;
		}
	}

	return nullptr;
}

Cancion* List::Getvalue(int position) {
	if ((position >= 0) && (position < count)) {
		return GetNodo(position)->value;
	}
	return nullptr;
}
Nodo* List::GetNodo(int position) {
	if ((position >= 0) && (position < count)) {
		Nodo* temp = first;
		int index = 0;
		while ((temp) && (index < position)) {
			temp = temp->next;
			index++;
		}
		return temp;
	}
	return nullptr;
}

bool List::Listempty() {
	return count == 0;
}
int List::size() {
	return count;
}

void List::Intercambiar(int pos1, int pos2)
{
	Nodo* nodo1 = GetNodo(pos1);
	Nodo* nodo2 = GetNodo(pos2);

	std::swap(nodo1->value, nodo2->value);
}

void List::OrdenarArtistaAsendente()
{
	int w = count - 1;//contador que este en la ultima posicion
	for (int i = 0; i <= w; i++)//un ciclo el cual busque si el artista es desconocido y lo cambie por una posicion en donde el artista si sea conocido y dejar todos los desconocidos hasta el final
	{
		if (Getvalue(i)->GetArtista() == "desconocido")
		{
			Intercambiar(i, w);//intercambia la posicion donde encuentre un desconocido con la ultima posicion 
			w--; i--;//el w se le resta el tamaño para ya no tocar a los elementos desconocidos y el i se resta para volver a evaluar el arreglo
		}
	}

	for (int i = 0; i <= w; i++)//para ordenar la parte que si tengan artista 
		for (int j = 0; j <= w; j++)
		{
			if (Getvalue(i)->GetArtista() < Getvalue(j)->GetArtista())
			{
				Intercambiar(i, j);
			}
		}
}
void List::OrdenarCancionAsendente()
{
	for (int i = 0; i < count; i++)
		for (int j = 0; j < count; j++)
		{
			if (Getvalue(i)->GetNombre() < Getvalue(j)->GetNombre())
			{
				Intercambiar(i, j);
			}
		}
}

void List::OrdenarArtistaDescendente()
{
	int w = count - 1;
	for (int i = 0; i <= w; i++)
	{
		if (Getvalue(i)->GetArtista() == "desconocido")
		{
			Intercambiar(i, w);
			w--; i--;
		}
	}

	for (int i = 0; i <= w; i++)//para ordenar la parte que si tengan artista 
		for (int j = 0; j <= w; j++)
		{
			if (Getvalue(i)->GetArtista() > Getvalue(j)->GetArtista())
			{
				Intercambiar(i, j);
			}
		}
}
void List::OrdenarCancionDescendente()
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (Getvalue(i)->GetNombre() > Getvalue(j)->GetNombre())
			{
				Intercambiar(i, j);
			}
		}
	}
}