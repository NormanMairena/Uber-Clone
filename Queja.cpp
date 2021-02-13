#include "Queja.h"
Queja::Queja(string d, string i,int d2 ,int m,int h ,int mi){
	this->descripcion = d;
	this->id =i;
	this->hora = h;
	this->min = mi;
	this->dia = d2;
	this->mes = m;
}
Queja::~Queja(){}
void Queja::setdescripcion(string c){
	this->descripcion = c;
}
void Queja::setId(string c){
	this->id = c;
}
string Queja::getdescripcion(){
	return descripcion;
}
string Queja::getId(){
	return id;
}
int Queja::getdia(){
	return dia;
}
int Queja::getmes(){
	return mes;
}
int Queja::gethora(){
	return hora;
}
int Queja::getmin(){
	return min;
}
string Queja::tostring()
{
	stringstream s;
	s << "queja numero: " << id << endl
		<< descripcion << endl
		<< "Fecha: " << dia << "/" << mes << "/"<<2020 << endl
		<< "Hora: " << "(" << hora << ")" << ":" << "(" << min << ")" << endl;
	return s.str();
}

Queja* Queja::leer(ifstream& c)
{
	
	string d, i; int hora, min, dia, mes; 
	if (!(getline(c, d))) { return NULL; }
	if (!(getline(c, i))) { return NULL; }
	if (!(c>>hora)) { return NULL; }
	if (!(c>>min)) { return NULL; }
	if (!(c>>dia)) { return NULL; }
	if (!(c>>mes)) { return NULL; }
	
	return new Queja(d,i,hora,min,dia,mes);

}

void Queja::guardar(ofstream& c)
{
	
	c << getdescripcion() << endl
		<< getId() << endl
		<< gethora() << endl
		<< getmin() << endl
		<< getdia() << endl
		<< getmes() << endl;
		
}


