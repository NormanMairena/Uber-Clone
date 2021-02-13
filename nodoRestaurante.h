#pragma once
#include "Restaurantes.h"
class nodoRestaurante{
	private:
	Restaurantes* R;
	nodoRestaurante* sig;
public:
	nodoRestaurante(Restaurantes *, nodoRestaurante*);
	~nodoRestaurante();
	void setInfo(Restaurantes*);
	Restaurantes *getInfo();
	void setSig(nodoRestaurante*);
	nodoRestaurante* getSig();
	string toStringNodoRestaurante();
	string toStringNodoRestaurante2();
};

