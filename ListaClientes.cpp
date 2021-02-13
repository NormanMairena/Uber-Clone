#include "ListaClientes.h"
ListaClientes::ListaClientes():first(NULL), actual(NULL) {}
ListaClientes::~ListaClientes() {}
bool ListaClientes::estaVacia() {
	if (first == NULL) { return true; }
	return false;
}
void ListaClientes::agregarIni(Cliente* dato) {
	first = new nodoCliente(dato, first);
}
void ListaClientes::agregarFinal(Cliente* C) {
	actual = first;
	if (estaVacia()) {
		first = new nodoCliente(C, NULL);
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new nodoCliente(C, NULL));
	}
}
bool ListaClientes::eliminarEspecifico(string  x) { //Busca por placa
	nodoCliente* panterior = NULL;
	actual = first;
	if (first == NULL) {
		return false;
	}
	if (first->getCliente()->getcedula() == x) {
		actual = actual->getSig();
		delete (first);
		first = actual;
		return true;
	}
	while (actual != NULL && actual->getCliente()->getcedula() != x) {
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
bool ListaClientes::eliminarIni() {
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
bool ListaClientes::eliminaFinal() {
	actual = first;
	nodoCliente* anterior = NULL;
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
int ListaClientes::cuentaNodos() {
	int cont = 0;
	actual = first;
	while (first != NULL) {
		first = first->getSig();
		cont++;
	}
	return cont;
}
bool ListaClientes::busquedaid(string id) {
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->getCliente()->getcedula() == id) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
Cliente* ListaClientes::busquedaid2(string id2) {
	if (estaVacia()) {
		return NULL;
	}
	else {
		if (busquedaid(id2) != false) {
			return actual->getCliente();
		}
		return NULL;
	}
}
string ListaClientes::general()
{
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->getCliente()->general() << endl;
		actual = actual->getSig();
	}
	return s.str();
}

string ListaClientes::toString() {
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->toStringnodoCliente() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
void ListaClientes::ordenarLista() {
	actual = first;
	nodoCliente* aux = NULL;
	Cliente* c;
	while (actual->getSig() != NULL) {
		aux = actual->getSig();
		while (aux != NULL) {
			if (actual->getCliente()->getcedula() > aux->getCliente()->getcedula()) {
				c = aux->getCliente();
				aux->setCliente(actual->getCliente());
				actual->setCliente(c);
			}
			aux = aux->getSig();
		}
		actual = actual->getSig();
	}
}

void ListaClientes::guardar()
{
	actual = first;
	ofstream c;
	c.open("Clientes.txt", ios::app);
	
	while (actual != NULL) {
		actual->getCliente()->guardar(c);
		actual = actual->getSig();
	}
	c.close();
}
ListaClientes* ListaClientes::Leer()
{
	ifstream c;
	c.open("Clientes.txt", ios::in);
	ListaClientes* li = new ListaClientes();
	Cliente* C = NULL;
	while (c.good())
	{
		C = Cliente::leer(c);
		if (C!=NULL)
		{

			li->agregarFinal(C);
		}
	}
	c.close();
	return li;
}