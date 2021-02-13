#pragma once
#include "Repartidor.h"
class nodoRepartidor{
private:
	Repartidor* deliver;
	nodoRepartidor* sig;
public:
	nodoRepartidor(Repartidor*, nodoRepartidor*);
	~nodoRepartidor();
	void setInfo(Repartidor*);
	Repartidor* getInfo();
	void setSig(nodoRepartidor*);
	nodoRepartidor* getSig();
	string toStringNodoRepartidor();
};

