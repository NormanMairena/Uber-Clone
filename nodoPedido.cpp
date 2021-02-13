#include "nodoPedido.h"
nodoPedido::nodoPedido(Pedido* P, nodoPedido* N){
	this->P = P;
	this->sig = N;
}
nodoPedido::~nodoPedido(){}
void nodoPedido::setInfo(Pedido* c){this->P = c;}
Pedido* nodoPedido::getInfo(){return P;}
void nodoPedido::setSig(nodoPedido* s){	this->sig = s;}
nodoPedido* nodoPedido::getSig(){return sig;}
string nodoPedido::toStringnodoPedido(){	return P->tostring();}
string nodoPedido::toStringnodoPedido2() { return P->tostring2(); }

string nodoPedido::opcion2_2()
{
	return P->opcion2_2();
}
