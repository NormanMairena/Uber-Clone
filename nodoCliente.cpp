#include "nodoCliente.h"
nodoCliente::nodoCliente(Cliente* c, nodoCliente* N) {
	C = c;
	sig = N;
}
nodoCliente:: ~nodoCliente(){}
void nodoCliente::setCliente(Cliente* C) { this->C = C; }
Cliente* nodoCliente::getCliente() { return C; }
void nodoCliente::setSig(nodoCliente* sig) { this->sig = sig; }
nodoCliente* nodoCliente::getSig() { return sig; }
string nodoCliente::toStringnodoCliente() { return C->toStringCliente(); }