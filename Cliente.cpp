#include "Cliente.h"
Cliente::Cliente(string ced, string nom,  string numTar, string numTel, string dirExac, string email):Persona(ced,nom,numTel,email) {
	numeroTargeta = numTar;
	direccionExacta = dirExac;
}
Cliente::~Cliente(){}
string Cliente::getnumeroTargeta() { return numeroTargeta; }
string Cliente::getdireccionExacta() { return direccionExacta; }
void Cliente::setnumeroTargeta(string numeroTargeta) { this->numeroTargeta = numeroTargeta; }
void Cliente::setdireccionExacta(string direccionExacta) { this->direccionExacta = direccionExacta; }
string Cliente::toStringCliente() {
	stringstream s;
	s << "-----------Cliente----------" << endl;
	s << Persona::toString();
	s << "Numero de Targeta :" << numeroTargeta << endl;
	s << "Direccion Exacta :" << direccionExacta <<endl;
	return s.str();
}

string Cliente::general()
{
	stringstream s;
	s <<" "<< "Nombre: " <<" "<< Persona::getnombre() <<" "<< "Id: " <<" "<< Persona::getcedula();
	return s.str();
}

Cliente* Cliente::leer(ifstream& estFile)
{
	string ced, nom, num, correo, tarjeta, direccion;
	if (!(getline(estFile, nom))) { return NULL; }
	if (!(getline(estFile, ced))) { return NULL; }
	if (!(getline(estFile, num))) { return NULL; }
	if (!(getline(estFile, correo))) { return NULL; }
	if (!(getline(estFile, tarjeta))) { return NULL; }
	if (!(getline(estFile, direccion))) { return NULL; }
	return new Cliente(ced, nom, tarjeta, num, direccion, correo);
	
}

void Cliente::guardar(ofstream& c)
{
	c << getnombre() << endl
		<< getcedula() << endl
		<< getnumeroTelefono() << endl
		<< getcorreoElectronico() << endl
		<< getnumeroTargeta() << endl
		<< getdireccionExacta() << endl;
}


 