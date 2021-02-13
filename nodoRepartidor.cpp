#include "nodoRepartidor.h"
nodoRepartidor::nodoRepartidor(Repartidor* R, nodoRepartidor* N): deliver(R),sig(N){}
nodoRepartidor::~nodoRepartidor() {}
void nodoRepartidor::setInfo(Repartidor* deliver) { this->deliver = deliver; }
Repartidor* nodoRepartidor::getInfo() { return deliver; }
void nodoRepartidor::setSig(nodoRepartidor* sig) { this->sig = sig; }
nodoRepartidor* nodoRepartidor::getSig() { return sig; }
string nodoRepartidor::toStringNodoRepartidor() { return deliver->toStringRepartidores(); }