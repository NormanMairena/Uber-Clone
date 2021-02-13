#pragma once
#include"Pedido.h"
class nodoPedido{
private:
	Pedido* P;
	nodoPedido* sig;
public:
	nodoPedido(Pedido *, nodoPedido*);
	~nodoPedido();
	void setInfo(Pedido*);
	Pedido *getInfo();
	void setSig(nodoPedido*);
	nodoPedido* getSig();
	string toStringnodoPedido();
	string toStringnodoPedido2();
	string opcion2_2();
};

