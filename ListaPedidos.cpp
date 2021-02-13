#include "ListaPedidos.h"
ListaPedidos::ListaPedidos() :first(NULL), actual(NULL) {}
ListaPedidos::~ListaPedidos() {}
bool ListaPedidos::estaVacia() {
	if (first == NULL) { return true; }
	return false;
}
void ListaPedidos::agregarIni(Pedido* dato) {
	first = new nodoPedido(dato, first);
}
int ListaPedidos::sacarModa() {
	int vec[50];
	int hora, cont = 0;
	for (int i = 0; i < 50 ; i++){
		vec[i] = 0;
	}
	actual = first;
	int i = 1;
	if (actual == NULL) {
		return -1;
	}
	else {
		while (actual != NULL) {
			vec[actual->getInfo()->gethora()]++;
			actual = actual->getSig();
		}
	}
	for (int i = 0; i < 50; i++){
		if (vec[i] > cont) {
			cont = vec[i];
			hora = i;
		}

	}
	return hora;
}
void ListaPedidos::agregarFinal(Pedido* p) {
	actual = first;
	if (estaVacia()) {
		first = new nodoPedido(p, NULL);
	}
	else {
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new nodoPedido(p, NULL));
	}
}

bool ListaPedidos::eliminarEspecifico(int  x) { //Busca por placa
	nodoPedido* panterior = NULL;
	actual = first;
	if (first == NULL) {
		return false;
	}
	if (first->getInfo()->getID() == x) {
		actual = actual->getSig();
		delete (first);
		first = actual;
		return true;
	}
	while (actual != NULL && actual->getInfo()->getID() != x) {
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
bool ListaPedidos::eliminarIni() {
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
bool ListaPedidos::eliminaFinal() {
	actual = first;
	nodoPedido* anterior = NULL;
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
int ListaPedidos::cuentaNodos() {
	int cont = 0;
	actual = first;
	while (first != NULL) {
		first = first->getSig();
		cont++;
	}
	return cont;
}
bool ListaPedidos::busquedaid(int id) {
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->getInfo()->getID() == id) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
Pedido* ListaPedidos::busquedaid2(int id2) {
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
string ListaPedidos::opcion2_2()
{
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->opcion2_2() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
bool ListaPedidos::estacliente(string x)
{
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->getInfo()->getClient()->getcedula() == x) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
string ListaPedidos::clienterep(string x){
	stringstream s;
	actual = first;
	while (actual!=NULL)
	{
		if (estacliente(x) != false) {
			s << actual->getInfo()->tostring2();
			s << "se encontro" << endl;
		}
		else
		{
			s << "no encontro" << endl;
		}
		actual = actual->getSig();
	}

	return s.str();
}
bool ListaPedidos::estarepartidor(string x){
	actual = first;
	if (estaVacia()){
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->getInfo()->getRepart()->getcedula() == x) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
string ListaPedidos::repartidorrep(string x){
	stringstream s;
	actual = first;
	while (actual!=NULL)
	{
		if (estarepartidor(x) != false) {
			s << actual->getInfo()->tostring2();
			s << "se encontro" << endl;
		}
		else
		{
			s << "no encontro" << endl;
		}
		actual = actual->getSig();
	}

	return s.str();
}
int ListaPedidos::getidinicio()
{
	return first->getInfo()->getComb()->getID_INIciO();
}
string ListaPedidos::opcion2_3(string c)
{
	actual = first;
	stringstream s;
	while (actual != NULL) {
		if (actual->getInfo()->getComb()->opcion2_3(c))
		{
			s <<"ID: "<< actual->getInfo()->getID() << "   " <<"Estado: "<< actual->getInfo()->getestado() << endl;
		}
		
		actual = actual->getSig();
	}
	if (esta2_3(c)==false)
	{
		s << "el restaurante no posee pedidos" << endl;
	}
	return s.str();
}
bool ListaPedidos::esta2_3(string c)
{
	actual = first;
	if (estaVacia()) {
		return false;
	}
	else {
		while (actual != NULL) {
			if (actual->getInfo()->getComb()->opcion2_3(c)) {
				return true;
			}
			actual = actual->getSig();
		}
		return false;
	}
}
void ListaPedidos::guardar(){
	actual = first;
	ofstream c;
	c.open("pedidos.txt", ios::app);
	
	while (actual != NULL) {
		actual->getInfo()->guardar(c);
		actual = actual->getSig();
	}
	c.close();
}
ListaPedidos* ListaPedidos::leer(){
	ifstream c;
	c.open("pedidos.txt", ios::in);
	ListaPedidos* li = new ListaPedidos();
	Pedido* C = NULL;
	while (c.good())
	{
		C = Pedido::Leer(c);
		if (C!=NULL)
		{

			li->agregarFinal(C);
		}
	}
	c.close();
	return li;
}
string ListaPedidos::toString() {
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->toStringnodoPedido() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
string ListaPedidos::toString2() {
	actual = first;
	stringstream s;
	while (actual != NULL) {
		s << actual->toStringnodoPedido2() << endl;
		actual = actual->getSig();
	}
	return s.str();
}
void ListaPedidos::ordenarLista() {
	actual = first;
	nodoPedido* aux = NULL;
	Pedido* p;
	while (actual->getSig() != NULL) {
		aux = actual->getSig();
		while (aux != NULL) {
			if (actual->getInfo()->getID() > aux->getInfo()->getID()) {
				p = aux->getInfo();
				aux->setInfo(actual->getInfo());
				actual->setInfo(p);
			}
			aux = aux->getSig();
		}
		actual = actual->getSig();
	}
}