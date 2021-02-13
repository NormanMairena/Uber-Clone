#pragma once
#include"Queja.h"
class nodoQueja
{
private:
	Queja * info;
	nodoQueja * sig;
public:
	nodoQueja(Queja *, nodoQueja*);
	~nodoQueja();
	void setInfo(Queja*);
	Queja *getInfo();
	void setSig(nodoQueja*);
	nodoQueja* getSig();
	string toStringNodo();
};

