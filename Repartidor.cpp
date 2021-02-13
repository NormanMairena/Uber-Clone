#include "Repartidor.h"
Repartidor::Repartidor(string ced, string nom, string numtel, string email,char est, float numKilRer, int quej, ListaQuejas* c):Persona(ced,nom,numtel,email){
	estado = est;
	numKilometrosRecorridos = numKilRer;
	quejas = quej;
	listaquejas = c;
}

Repartidor::~Repartidor() {}
char Repartidor::getestado() { return estado; }
float Repartidor::getnumKilometrosRecorridos() { return numKilometrosRecorridos; }
int Repartidor::getquejas() { return quejas; }
void Repartidor::setestado(char estado) { this->estado = estado; }
void Repartidor::setnumKilometrosRecorridos(float numKilometrosRecorridos) { this->numKilometrosRecorridos = numKilometrosRecorridos; }
void Repartidor::setquejas(int qeujas) { this->quejas = qeujas; }
string Repartidor::toStringRepartidores() {
	stringstream s;
	s << "-----------Repartidor----------" << endl;
	s << Persona::toString();
	s << "Estado :" << estado << endl;
	s << "Numero de kilometros recorridos :" << numKilometrosRecorridos << endl;
	s << "Quejas :" << quejas << endl;
	if (listaquejas)
	{
		s << listaquejas->toString();
	}
	return s.str();
}

ListaQuejas* Repartidor::getQuejas()
{
	return listaquejas;
}

string Repartidor::general()
{
	stringstream s;
	s <<" "<< "nombre: "<<" "<< Persona::getnombre()<<" "<< "identificacion: " <<" "<< Persona::getcedula();
	return s.str();
}

void Repartidor::actualizar(float c)
{
	numKilometrosRecorridos = numKilometrosRecorridos + c;
}

Repartidor* Repartidor::leer(ifstream& estFile)
{
	string ced, nom, numtel, email; char est; float numKilRer; int quej;
	if (!(getline(estFile, ced))) { return NULL; }
	if (!(getline(estFile, nom))) { return NULL; }
	if (!(getline(estFile, numtel))) { return NULL; }
	if (!(getline(estFile, email))) { return NULL; }
	if (!(estFile>>est)) { return NULL; }
	if (!(estFile>>numKilRer)) { return NULL; }
	if (!(estFile>>quej)) { return NULL; }
	return new Repartidor(ced, nom, numtel, email, est, numKilRer, quej);
}

void Repartidor::guardar(ofstream& c)
{
	c << getcedula() << endl
		<< getnombre() << endl
		<< getnumeroTelefono() << endl
		<< getcorreoElectronico() << endl
		<< getestado() << endl
		<< getnumKilometrosRecorridos() << endl
		<< getquejas()<<'\t';
	if (listaquejas->estaVacia()==false)
	{
		listaquejas->guardar();
	}
}

void Repartidor::nuevaqueja(Queja* c)
{
	quejas++;
	listaquejas->agregarFinal(c);
}

int Repartidor::cuentacantquejas()
{
	
	return listaquejas->cuentaNodos();
}

 void Repartidor::setQuejas(ListaQuejas* c)
{
	 this->listaquejas = c;
}

