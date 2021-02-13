#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include<fstream>
using namespace std;
class combo {
private:
	int numeroCombo;
	string principal;
	string beida;
	string acompanamiento;
	string postre;
	float precio;
	string idRestaurante;


public:
	combo(int=0, string="principal",string="beb",string="acomp",string="postre", float=0, string ="idrest");
	~combo();
	string getprincipal();
	string getbebida();
	string getacompanna();
	string getpostre();
	int getnum();
	float getprecio();
	void setprincipal(string);
	void setbebida(string);
	void setacompanna(string);
	void setpostre(string);
	void setnumero(int);
	void setprecio(float);
	string tostring();
	void setidrest(string);
	string getidrest();
	//---------------------
	static combo* leer(ifstream&);
	void guardar(ofstream&);
};

