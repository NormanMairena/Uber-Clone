#include "ListaCombos.h"
ListaCombos::ListaCombos() :first(NULL), actual(NULL) {}
ListaCombos::~ListaCombos() {}
bool ListaCombos::estaVacia() {
	if (first == NULL) { return true; }
	return false;
}
void ListaCombos::agregarIni(combo* dato) {
	first = new nodoCombo(dato, first);
}
void ListaCombos::agregarFinal(combo* C) {
	actual = first;
	if (estaVacia()) {
		first = new nodoCombo(C, NULL);
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new nodoCombo(C, NULL));
	}
}
bool ListaCombos::eliminarEspecifico(int  x) { //Busca por placa
	nodoCombo* panterior = NULL;
	actual = first;
	if (first == NULL) {
		return false;
	}
	if (first->getInfo()->getnum() == x) {
		actual = actual->getSig();
		delete (first);
		first = actual;
		return true;
	}
	while (actual != NULL && actual->getInfo()->getnum() != x) {
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
bool ListaCombos::eliminarIni() {
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
bool ListaCombos::eliminaFinal() {
	actual = first;
	nodoCombo* anterior = NULL;
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
int ListaCombos::cuentaNodos() {
	int cont = 0;
	actual = first;
	while (first != NULL) {
		first = first->getSig();
		cont++;
	}
	return cont;
}
bool ListaCombos::busquedaid(int id) {
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->getInfo()->getnum() == id) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
combo* ListaCombos::busquedaid2(int id2) {
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
float ListaCombos::calcSumaTOT()
{
	float cont = 0;
	actual = first;
	while (actual != NULL) {
		cont = cont + actual->getInfo()->getprecio();
		actual = actual->getSig();
	}
	return cont;
}
int ListaCombos::getID_INIciO()
{
	return first->getInfo()->getnum();
}
bool ListaCombos::opcion2_3(string c)
{
	actual = first;
	
	while (actual != NULL) {
		if (actual->getInfo()->getidrest()==c)
		{
			return true;
			break;
		}
		actual = actual->getSig();
	}
	return false;
	
}
void ListaCombos::guardar() {
	ofstream salida;
	salida.open("combos.txt", ios::app);
	actual = first;
	while (actual != NULL) {
		actual->getInfo()->guardar(salida);
		actual = actual->getSig();
	}
	salida.close();
}

void ListaCombos::guardar_enpedido(ofstream& salida)
{
	actual = first;
	while (actual != NULL) {
		actual->getInfo()->guardar(salida);
		actual = actual->getSig();
	}
}

ListaCombos* ListaCombos::Leer()
{
	ifstream c;
	c.open("combos.txt", ios::in);
	ListaCombos* li = new ListaCombos();
	combo* C = NULL;
	while (c.good())
	{
		C = combo::leer(c);
		if (C != NULL)
		{

			li->agregarFinal(C);
		}
	}
	c.close();
	return li;
}

string ListaCombos::toString() {
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->toStringNodoCombo() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
void ListaCombos::ordenarLista() {
	actual = first;
	nodoCombo* aux = NULL;
	combo* c;
	while (actual->getSig() != NULL) {
		aux = actual->getSig();
		while (aux != NULL) {
			if (actual->getInfo()->getnum() > aux->getInfo()->getnum()) {
				c = aux->getInfo();
				aux->setInfo(actual->getInfo());
				actual->setInfo(c);
			}
			aux = aux->getSig();
		}
		actual = actual->getSig();
	}
}