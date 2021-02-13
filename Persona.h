#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include<fstream>
using namespace std;
class Persona {
public:
	Persona(string = "indef", string = "indet", string = "indet", string ="indet");
	string toString();
	//metodosGet
	string getcedula();
	string getnombre();
	string getnumeroTelefono();
	string getcorreoElectronico();
	//metodosSet
	void setcedula(string);
	void setnombre(string);
	void setnumeroTelefono(string);
	void setcorreoElectronico(string);
private:
	string cedula;
	string nombre;
	string numeroTelefono;
	string correoElectronico;




};

