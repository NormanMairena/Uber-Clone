#include "ListaRepartidores.h"
ListaRepartidores::ListaRepartidores():first(NULL), actual(NULL) {}
ListaRepartidores::~ListaRepartidores(){}
bool ListaRepartidores::estaVacia() {
	if (first == NULL) { return true; }
	return false;
}
void ListaRepartidores::agregarIni(Repartidor* dato) {
	first = new nodoRepartidor(dato, first);
}
void ListaRepartidores::agregarFinal(Repartidor* C) {
	actual = first;
	if (estaVacia()) {
		first = new nodoRepartidor(C, NULL);
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new nodoRepartidor(C, NULL));
	}
}
bool ListaRepartidores::eliminarEspecifico(int  x) { //Busca por placa
	nodoRepartidor* panterior = NULL;
	actual = first;
	if (first == NULL) {
		return false;
	}
	if (first->getInfo()->getnumKilometrosRecorridos() == x) {
		actual = actual->getSig();
		delete (first);
		first = actual;
		return true;
	}
	while (actual != NULL && actual->getInfo()->getnumKilometrosRecorridos() != x) {
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
bool ListaRepartidores::eliminarIni() {
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
bool ListaRepartidores::eliminaFinal() {
	actual = first;
	nodoRepartidor* anterior = NULL;
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
int ListaRepartidores::cuentaNodos() {
	int cont = 0;
	actual = first;
	while (first != NULL) {
		first = first->getSig();
		cont++;
	}
	return cont;
}
bool ListaRepartidores::busquedaid(string id) {
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->getInfo()->getcedula() == id) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
Repartidor* ListaRepartidores::busquedaid2(string id2) {
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
Repartidor* ListaRepartidores::getinicial(){
	actual = first;
	while (actual != NULL) {
		if (actual->getInfo()->getestado()=='L'&&actual->getInfo()->getquejas()<4){
			return actual->getInfo();
			break;
		}
		actual = actual->getSig();
	}
}
bool ListaRepartidores::repartidordisponible()
{
	actual = first;

	while (actual != NULL) {
		if (actual->getInfo()->getestado() == 'L' && actual->getInfo()->getquejas() < 4)
		{
			return true;
			break;
		}
		actual = actual->getSig();
	}
	return false;
}

void ListaRepartidores::guardar()
{actual = first;
	ofstream c;
	c.open("Repartidores.txt", ios::app);
	
	while (actual != NULL) {
		actual->getInfo()->guardar(c);
		actual = actual->getSig();
	}
	c.close();
}

ListaRepartidores* ListaRepartidores::Leer()
{
	ifstream entrada, entrada2;
	entrada.open("Repartidores.txt", ios::in);
	entrada2.open("quejas.txt", ios::in);
	
	ListaRepartidores* li = new ListaRepartidores();
	Repartidor* C = NULL;
	ListaQuejas* L = NULL;
	while (entrada.good())
	{
		
		C = Repartidor::leer(entrada);
		if (C!=NULL)
		{
			
			
			L = ListaQuejas::Leer(C->getcedula());
			C->setQuejas(L);	
			li->agregarFinal(C);
			entrada2.seekg(0);

		}
	}
	entrada.close();
	entrada2.close();
	return li;
}

string ListaRepartidores::toString() {
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->toStringNodoRepartidor() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
string ListaRepartidores::general()
{
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->getInfo()->general() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
void ListaRepartidores::ordenarLista() {
	actual = first;
	nodoRepartidor* aux = NULL;
	Repartidor* r;
	while (actual->getSig() != NULL) {
		aux = actual->getSig();
		while (aux != NULL) {
			if (actual->getInfo()->getnumKilometrosRecorridos() > aux->getInfo()->getnumKilometrosRecorridos()) {
				r = aux->getInfo();
				aux->setInfo(actual->getInfo());
				actual->setInfo(r);
			}
			aux = aux->getSig();
		}
		actual = actual->getSig();
	}
}
