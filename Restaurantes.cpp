#include "Restaurantes.h"
Restaurantes::Restaurantes(string n, string c, string d, string t,ListaCombos*ListComb):nombre(n),cedulajurídica(c),dirección(d),tipodecomida(t),LC(ListComb) {}//falta lista de combos
Restaurantes::Restaurantes() : nombre("none"), cedulajurídica("none"),dirección("none"),tipodecomida("none"),LC(NULL) {}
Restaurantes::~Restaurantes() {}
string Restaurantes::getnombre() { return nombre; }
string Restaurantes::getcedulajurídica() { return cedulajurídica; }
string Restaurantes::getdirección() { return dirección; }
string Restaurantes::gettipodecomida() { return tipodecomida; }
ListaCombos* Restaurantes::getlistacombos()
{
	return LC;
}
void Restaurantes::setnombre(string nombre) { this->nombre = nombre; }
void Restaurantes::setcedulajuridica(string cedulaJuridica) { this->cedulajurídica = cedulaJuridica; }
void Restaurantes::setdireccion(string direccion) { this->dirección = direccion; }
void Restaurantes::settipodeComida(string tipodeComida) { this->tipodecomida = tipodeComida; }
void Restaurantes::setlistacombos(ListaCombos* c)
{
	this->LC = c;
}
string Restaurantes::toStringRestaurantes() {
	stringstream s;
	s << "Nombre: " << nombre << endl;
	s << "Cedula Juridica: " << cedulajurídica << endl;
	s << "Direccion: " << dirección<< endl;
	s << "Tipo de Comida: " << tipodecomida << endl;
	if (LC)
	{
		s << LC->toString();
	}
	else
	{
		s << "sin combos" << endl;
	}
	return s.str();
}
string Restaurantes::tostringNombre() {
	stringstream s;
	s << "Nombre: " << nombre << endl;
	s << "Cedula Juridica: " << cedulajurídica << endl;
	return s.str();
}

bool Restaurantes::encontrarComboID(int c)
{
	if (LC->busquedaid(c)==true)
	{
		return true;
	}
	return false;
}
void Restaurantes::guardar(ofstream& r) {
	r << getnombre() << endl
		<< getcedulajurídica() << endl
		<< getdirección() << endl
		<< gettipodecomida() << endl;
	LC->guardar();
}
Restaurantes* Restaurantes::leer(ifstream& estFile) {
	string ced, nom, direccion, tipoComida;
	if (!(getline(estFile, nom))) { return NULL; }
	if (!(getline(estFile, ced))) { return NULL; }
	if (!(getline(estFile, direccion))) { return NULL; }
	if (!(getline(estFile, tipoComida))) { return NULL; }
	return new Restaurantes(nom,ced,direccion,tipoComida);
}

