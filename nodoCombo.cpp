#include "nodoCombo.h"

nodoCombo::nodoCombo(combo* C, nodoCombo* N){
	this->Combo = C;
	this->sig = N;
}
nodoCombo::~nodoCombo(){}
void nodoCombo::setInfo(combo* X){this->Combo = X;}
combo* nodoCombo::getInfo(){	return Combo;}
void nodoCombo::setSig(nodoCombo* X){this->sig = X;}
nodoCombo* nodoCombo::getSig(){return sig;}
string nodoCombo::toStringNodoCombo(){	return Combo->tostring();}

