#include "Queue.h"
Queue::Queue() {
	list = new List();
}
//Si último no es NULO, hacemos que ultimo.siguiente apunte a nodo.Y actualizamos último, haciendo que apunte a nodo.Si primero es NULO, significa que la cola estaba vacía, así  que primero apunte también a nodo.
void Queue::enqueue(Cancion* value) {
	list->Insertend(value);
}

Cancion* Queue::dequeue() {
	return list->Extractstart();
}

bool Queue::queueempty() {
	return list->Listempty();
}

Queue::~Queue() {
	delete list;
}

