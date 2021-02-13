#include "Persona.h"
Persona::Persona(string ced,string nom,string numTel,string email){
	cedula = ced;
	nombre = nom;
	numeroTelefono = numTel;
	correoElectronico = email;
}

string Persona::getcedula() { return cedula; }
string Persona::getnombre() { return nombre; }
string Persona::getnumeroTelefono() { return numeroTelefono; }
string Persona::getcorreoElectronico() { return correoElectronico; }
void Persona::setcedula(string cedula) { this->cedula = cedula; }
void Persona::setnombre(string nombre) { this->nombre = nombre; }
void Persona::setnumeroTelefono(string numeroTelefono) { this->numeroTelefono = numeroTelefono; }
void Persona::setcorreoElectronico(string correoElectronico) { this->correoElectronico = correoElectronico; }
string Persona::toString() {
	stringstream s;
	s << "Nombre: " << nombre <<endl;
	s << "Cedula de identificacion: " << cedula << endl;
	s << "Numero de telefono: " << numeroTelefono << endl;
	s << "Correo Electronico: " << correoElectronico << endl;
	return s.str();
}

