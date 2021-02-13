#include "nodoQueja.h"
nodoQueja::nodoQueja(Queja * e, nodoQueja* s) {
	info = e;
	sig = s;
}
nodoQueja:: ~nodoQueja() { delete info;}
void nodoQueja::setInfo(Queja* e) { info = e; }
Queja *  nodoQueja::getInfo() { return info; }
void nodoQueja::setSig(nodoQueja* s) { sig = s; }
nodoQueja* nodoQueja::getSig() { return sig; }
string nodoQueja::toStringNodo(){return info->tostring();}


