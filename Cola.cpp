#include "Cola.h"
Cola::Cola() {
	list = new List();
}

Cola::~Cola() {
	delete list;
}
void Cola::enqueue(Cancion* value) {
	list->Insertend(value);
}

Cancion* Cola::dequeue() {
	return list->Extractstart();
}
Cancion* Cola::peak()
{
	return list->Getvalue(0);
}

bool Cola::queueempty() {
	return list->Listempty();
}

int Cola::size()
{
	return list->size();
}
Cancion* Cola::GetValue(int position)
{
	return list->Getvalue(position);
}
