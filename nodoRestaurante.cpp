#include "nodoRestaurante.h"

nodoRestaurante::nodoRestaurante(Restaurantes* R, nodoRestaurante* M){
	this->R = R;
	this->sig = M;
}
nodoRestaurante::~nodoRestaurante(){}
void nodoRestaurante::setInfo(Restaurantes* c){this->R = c;}
Restaurantes* nodoRestaurante::getInfo() { return R; }
void nodoRestaurante::setSig(nodoRestaurante* c){this->sig = c;}
nodoRestaurante* nodoRestaurante::getSig(){return sig;}
string nodoRestaurante::toStringNodoRestaurante(){return R->toStringRestaurantes();}
string nodoRestaurante::toStringNodoRestaurante2() { return R->tostringNombre(); }