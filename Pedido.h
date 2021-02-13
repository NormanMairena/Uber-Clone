#pragma once
#include"ListaCombos.h"
#include"Cliente.h"
#include"Repartidor.h"
#include<fstream>

class Pedido
{
private:
	int id;//puede ser de rando, puesto que necesitamos un numero dif
	char estado;
	float KM;
	float total;
	float pagoRep;
	int hora;
	Repartidor* Repart;//validar si el repartidor tiene quejs
	ListaCombos* Comb;
	Cliente* Client;
public:
	Pedido(int=0, char='X', float=0, float=0, float=0,int= 0, Repartidor* =nullptr, ListaCombos* =nullptr, Cliente* =nullptr);
	Pedido();
	~Pedido();
	//sets
	void setid(int);
	void setestado(char);
	void setKM(float);
	void settotal(float);
	void setPagorep(float);
	void setRepartidor(Repartidor*);
	void setCombo(ListaCombos*);
	void setCliente(Cliente*);
	void sethora(int);

	//gets
	int getID();
	char getestado();
	float getKM();
	float gettotal();
	float getpagoRep();
	int gethora();
	Repartidor* getRepart();
	ListaCombos* getComb();
	Cliente* getClient();
	
	void actualizarKM(float);
	string tostring();
	string tostring2();
	string opcion2_2();
	int getnumcombo();

	void guardar(ofstream&);
	static Pedido* Leer(ifstream&);
	

	

};

