#include "ListaQuejas.h"
ListaQuejas::ListaQuejas() :first(NULL), actual(NULL) {}
ListaQuejas::~ListaQuejas() {}
bool ListaQuejas::estaVacia() {
	if (first == NULL) { return true; }
	return false;
}
void ListaQuejas::agregarIni(Queja* dato) {
	first = new nodoQueja(dato, first);
}
void ListaQuejas::agregarFinal(Queja* q) {
	actual = first;
	if (estaVacia()) {
		first = new nodoQueja(q, NULL);
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new nodoQueja(q, NULL));
	}
}
bool ListaQuejas::eliminarEspecifico(string  x) { //Busca por placa
	nodoQueja* panterior = NULL;
	actual = first;
	if (first == NULL) {
		return false;
	}
	if (first->getInfo()->getId()== x) {
		actual = actual->getSig();
		delete (first);
		first = actual;
		return true;
	}
	while (actual != NULL && actual->getInfo()->getId() != x) {
		panterior = actual;
		actual = actual->getSig();
	}

	if (actual == NULL) { return false; }
	else {
		panterior->setSig(actual->getSig());
		delete actual;
		return true;
	}
	return false;
}
bool ListaQuejas::eliminarIni() {
	if (estaVacia()) {
		return false;
	}
	else {
		actual = first;
		first = first->getSig();
		delete actual;
		return true;
	}
}
bool ListaQuejas::eliminaFinal() {
	actual = first;
	nodoQueja* anterior = NULL;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(anterior->getSig());
		delete actual;
		actual = first;
		return true;
	}
}
int ListaQuejas::cuentaNodos() {
	int cont = 0;
	actual = first;
	while (first != NULL) {
		first = first->getSig();
		cont++;
	}
	return cont;
}
bool ListaQuejas::busquedaid(string id) {
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->getInfo()->getId() == id) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
Queja* ListaQuejas::busquedaid2(string id2) {
	if (estaVacia()) {
		return NULL;
	}
	else {
		if (busquedaid(id2) != false) {
			return actual->getInfo();
		}
		return NULL;
	}
}

void ListaQuejas::guardar()
{
	ofstream c;
	c.open("quejas.txt", ios::app);
	actual = first;
	while (actual != NULL) {
		actual->getInfo()->guardar(c);
		actual = actual->getSig();
	}
	c.close();
}

ListaQuejas* ListaQuejas::Leer(string id)
{
	ifstream c;
	c.open("quejas.txt", ios::in);
	
	ListaQuejas* li = new ListaQuejas();
	Queja* C = NULL;
	while (c.good())
	{
		C = Queja::leer(c);
		if (C != NULL)
		{
			if (C->getId()==id)
			{
				li->agregarFinal(C);
				
			}
			
		}
	}


	c.close();
	return li;
}

ListaQuejas* ListaQuejas::Leersolo()
{
	ifstream c;
	c.open("quejas.txt", ios::in);

	ListaQuejas* li = new ListaQuejas();
	Queja* C = NULL;
	while (c.good())
	{
		C = Queja::leer(c);
		if (C != NULL)
		{
			
			
				li->agregarFinal(C);

			

		}
	}


	c.close();
	return li;
}

string ListaQuejas::toString() {
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->toStringNodo() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
void ListaQuejas::ordenarLista() {
	actual = first;
	nodoQueja* aux = NULL;
	Queja* q;
	while (actual->getSig() != NULL) {
		aux = actual->getSig();
		while (aux != NULL) {
			if (actual->getInfo()->getId() > aux->getInfo()->getId()) {
				q = aux->getInfo();
				aux->setInfo(actual->getInfo());
				actual->setInfo(q);
			}
			aux = aux->getSig();
		}
		actual = actual->getSig();
	}
}
