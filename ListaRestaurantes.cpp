#include "ListaRestaurantes.h"
ListaRestaurantes::ListaRestaurantes() :first(NULL), actual(NULL) {}
ListaRestaurantes::~ListaRestaurantes() {}
bool ListaRestaurantes::estaVacia() {
	if (first == NULL) { return true; }
	return false;
}
void ListaRestaurantes::agregarIni(Restaurantes* dato) {
	first = new nodoRestaurante(dato, first);
}
void ListaRestaurantes::agregarFinal(Restaurantes* r) {
	actual = first;
	if (estaVacia()) {
		first = new nodoRestaurante(r, NULL);
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new nodoRestaurante(r, NULL));
	}
}
bool ListaRestaurantes::eliminarEspecifico(string  x) { //Busca por placa
	nodoRestaurante* panterior = NULL;
	actual = first;
	if (first == NULL) {
		return false;
	}
	if (first->getInfo()->getcedulajurídica() == x) {
		actual = actual->getSig();
		delete (first);
		first = actual;
		return true;
	}
	while (actual != NULL && actual->getInfo()->getcedulajurídica() != x) {
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
bool ListaRestaurantes::eliminarIni() {
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
bool ListaRestaurantes::eliminaFinal() {
	actual = first;
	nodoRestaurante* anterior = NULL;
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
int ListaRestaurantes::cuentaNodos() {
	int cont = 0;
	actual = first;
	while (first != NULL) {
		first = first->getSig();
		cont++;
	}
	return cont;
}
bool ListaRestaurantes::busquedaid(string id) {
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->getInfo()->getcedulajurídica() == id) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
Restaurantes* ListaRestaurantes::busquedaid2(string id2) {
	if (estaVacia()) {
		return NULL;
	}
	else {
		if (busquedaid(id2) != false) {
			return actual->getInfo();
			cout << "se encontro" << endl;
		}
		return NULL;
		cout << "no encontro" << endl;
	}
}
void ListaRestaurantes::guardar() {
	ofstream salida;
	salida.open("Restaurantes.txt");
	actual = first;
	while (actual != NULL) {
		salida << actual->getInfo()->getcedulajurídica()<< endl;
		salida << actual->getInfo()->getdirección() << endl;
		salida << actual->getInfo()->gettipodecomida() << endl;
		salida << actual->getInfo()->getnombre() << endl;
		actual = actual->getSig();
	}
	salida.close();
}
ListaRestaurantes* ListaRestaurantes::leer() {
	ifstream entrada;
	entrada.open("Restaurantes.txt", ios::app);
	ListaRestaurantes* li = new ListaRestaurantes();
	Restaurantes* C = NULL;
	while (entrada.good()){
		C = Restaurantes::leer(entrada);
		if (C!=NULL)
		{

			li->agregarFinal(C);
		}
	}
	entrada.close();
	return li;
}
string ListaRestaurantes::toString() {
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->toStringNodoRestaurante() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
string ListaRestaurantes::toString2() {
	int i=0;
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s<< actual->toStringNodoRestaurante2() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
void ListaRestaurantes::ordenarLista() {
	actual = first;
	nodoRestaurante* aux = NULL;
	Restaurantes* r;
	while (actual->getSig() != NULL) {
		aux = actual->getSig();
		while (aux != NULL) {
			if (actual->getInfo()->getcedulajurídica() > aux->getInfo()->getcedulajurídica()) {
				r = aux->getInfo();
				aux->setInfo(actual->getInfo());
				actual->setInfo(r);
			}
			aux = aux->getSig();
		}
		actual = actual->getSig();
	}
}