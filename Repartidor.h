#pragma once
#include "Persona.h"
#include"ListaQuejas.h"
class Repartidor:public Persona{
private:
	char estado;
	float numKilometrosRecorridos;
	int quejas;
	ListaQuejas* listaquejas;
public:
	Repartidor( string ="indet", string ="indet", string ="indet", string ="indet", char='X',float=0,int =0, ListaQuejas* = nullptr);
	~Repartidor();
	char getestado();
	float getnumKilometrosRecorridos();
	int getquejas();
	void setestado(char);
	void setnumKilometrosRecorridos(float);
	void setquejas(int);
	string toStringRepartidores();
	ListaQuejas* getQuejas();
	string general();
	void actualizar(float);
	static Repartidor* leer(ifstream&);
	void guardar(ofstream&);
	void nuevaqueja(Queja*);
	int cuentacantquejas();
	void setQuejas(ListaQuejas*);

};

