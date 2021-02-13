#include "Empresa.h"
Empresa::Empresa(ListaClientes* CL, ListaCombos* COM, ListaPedidos* P, ListaRepartidores* R, ListaRestaurantes* REST,ListaQuejas* Que)
{
	this->clientes = CL;
	this->combos = COM;
	this->pedidos = P;
	this->repartidores = R;
	this->restaurantes = REST;
	this->quejas= Que;
}

void Empresa::setclientes(ListaClientes* c)
{
	this->clientes = c;
}

void Empresa::setcombos(ListaCombos* c)
{
	this->combos = c;
}

void Empresa::setpedidos(ListaPedidos* c)
{
	this->pedidos = c;
}

void Empresa::setrepartidores(ListaRepartidores* c)
{
	this->repartidores = c;
}

void Empresa::setrestaurantes(ListaRestaurantes* c)
{
	this->restaurantes = c;
}
void Empresa::setQuejas(ListaQuejas* q)
{
	this->quejas = q;
}
ListaClientes* Empresa::getclientes()
{
	return clientes;
}


ListaCombos* Empresa::getcombos()
{
	return combos;
}
ListaPedidos* Empresa::getpedidos()
{
	return pedidos;
}
ListaRepartidores* Empresa::getrepartidores()
{
	return repartidores;
}
ListaRestaurantes* Empresa::getrestaurante()
{
	return restaurantes;
}
ListaQuejas* Empresa::getquejas()
{
	return quejas;
}
void Empresa::opcion1_1(string ced, string nom, string tar, string cel, string dir, string correo)
{
	Cliente *c = new Cliente(ced, nom, tar, cel, dir, correo);
	getclientes()->agregarFinal(c);
}
bool Empresa::estaRestaurante(string id) {
		if (restaurantes->busquedaid2(id)->encontrarComboID(pedidos->getidinicio()))
		{
			return true;
		}
	
	return false;
}

string Empresa::Listapedidos2_3(string c)
{
	stringstream s;
	if (estaRestaurante(c)) {
		s << pedidos->toString2() << endl;
	}
	return s.str();
}

bool Empresa::listoparapedir(){
	getrepartidores()->estaVacia() && clientes->estaVacia() && restaurantes->estaVacia() ? false : true;
	return true;
}

