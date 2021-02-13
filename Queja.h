#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include<fstream>
using namespace std;
class Queja{
private:
	string descripcion;
	string id;
	int hora;
	int min;
	int dia;
	int mes;
public:
	Queja(string = "none", string = "none", int = 0,int = 0,int = 0,int = 0);
	~Queja();
	void setdescripcion(string);
	void setId(string);
	string getdescripcion();
	string getId();
	int getdia();
	int getmes();
	int gethora();
	int getmin();
	string tostring();
	static Queja* leer(ifstream&);
	void guardar(ofstream&);
};

