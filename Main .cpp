#include "Control.h"
#include "Empresa.h"
#include<time.h>

int main() {
	
	ListaClientes* clientes = new ListaClientes();
	ListaCombos* combos= new ListaCombos();
	ListaPedidos* pedidos= new ListaPedidos();
	ListaRepartidores* repartidores= new ListaRepartidores();
	ListaRestaurantes* restaurantes= new ListaRestaurantes();
	Empresa* E = new Empresa(clientes, combos, pedidos, repartidores, restaurantes);
	Control* c = new Control(E);
	c->menu();
	cin.get();
	cin.get();
	return 0;
}