#pragma once
#include "Cliente.h"
class nodoCliente{
private:
	Cliente* C;
	nodoCliente* sig;
public:
	nodoCliente(Cliente*, nodoCliente*);
	~nodoCliente();
	void setCliente(Cliente*);
	Cliente* getCliente();
	void setSig(nodoCliente*);
	nodoCliente* getSig();
	string toStringnodoCliente();
};

