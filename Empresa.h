#pragma once
#include"ListaClientes.h"
#include"ListaCombos.h"
#include"ListaPedidos.h"
#include"ListaRepartidores.h"
#include"ListaRestaurantes.h"
#include "ListaQuejas.h"
class Empresa
{
private:
	ListaClientes* clientes;
	ListaCombos* combos;
	ListaPedidos* pedidos;
	ListaRepartidores* repartidores;
	ListaRestaurantes* restaurantes;
	ListaQuejas* quejas;
public:
	Empresa(ListaClientes* =NULL, ListaCombos* =NULL, ListaPedidos* =NULL, ListaRepartidores* =NULL, ListaRestaurantes* =NULL,ListaQuejas* = NULL);
	void setclientes(ListaClientes*);
	void setcombos(ListaCombos*);
	void setpedidos(ListaPedidos*);
	void setrepartidores(ListaRepartidores*);
	void setrestaurantes(ListaRestaurantes*);
	void setQuejas(ListaQuejas*);
	ListaClientes* getclientes();
	ListaCombos* getcombos();
	ListaPedidos* getpedidos();
	ListaRepartidores* getrepartidores();
	ListaRestaurantes* getrestaurante();
	ListaQuejas* getquejas();

	//submen 1
	void opcion1_1(string,string,string,string,string, string);
	bool estaRestaurante(string); 
	string Listapedidos2_3(string);

	bool listoparapedir();

};

