#pragma once
#include "Persona.h"
class Cliente:public Persona{
private:
	string numeroTargeta;
	string direccionExacta;
public:
	Cliente( string="indet", string ="indet", string ="indet", string ="indet", string ="indet",string ="indet");
	~Cliente();
	string getnumeroTargeta();
	string getdireccionExacta();
	void setnumeroTargeta(string);
	void setdireccionExacta(string);
	string toStringCliente();
	string general();
	static Cliente* leer(ifstream&);
	void guardar(ofstream&);
};

