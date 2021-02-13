#pragma once
#include"combo.h"
class nodoCombo
{
private:
	combo* Combo;
	nodoCombo* sig;
public:
	nodoCombo(combo *, nodoCombo*);
	~nodoCombo();
	void setInfo(combo*);
	combo *getInfo();
	void setSig(nodoCombo*);
	nodoCombo* getSig();
	string toStringNodoCombo();
	
	
};

