#include "combo.h"

combo::combo(int num, string prin, string bebi,string acom, string pos, float p , string idrest)
{
	this->numeroCombo = num;
	this->principal = prin;
	this->beida = bebi;
	this->acompanamiento = acom;
	this->postre = pos;
	this->precio = p;
	this->idRestaurante = idrest;
}

combo::~combo()
{
}

string combo::getprincipal()
{
	return principal;
}

string combo::getbebida()
{
	return beida;
}

string combo::getacompanna()
{
	return acompanamiento;
}

string combo::getpostre()
{
	return postre;
}

int combo::getnum()
{
	return numeroCombo;
}

float combo::getprecio()
{
	return precio;
}

void combo::setprincipal(string c)
{
	this->principal = c;
}

void combo::setbebida(string c)
{
	this->beida = c;
}

void combo::setacompanna(string c)
{
	this->acompanamiento = c;
}

void combo::setpostre(string c)
{
	this->postre = c;
}

void combo::setnumero(int c)
{
	this->numeroCombo = c;
}

void combo::setprecio(float c)
{
	this->precio = c;
}



string combo::tostring()
{
	stringstream s;
	s << "--Informacion del combo--" << endl
		<< "Plato principal: " << principal << endl
		<< "Refresco: " << beida << endl
		<< "Acompannamiento: " << acompanamiento << endl;
		if (postre!="no")
		{
			s << "Postre: " << postre << endl;
		}
		s<< "Precio: " << precio << endl
		<< "codigo: " << numeroCombo << endl;
	return s.str();
}

void combo::setidrest(string c) 
{
	this->idRestaurante = c;
}

string combo::getidrest()
{
	return idRestaurante;
}

combo* combo::leer(ifstream& file)
{
	int num ; string pri, bebi, acom, pos, idrest; float p;
	if (!(file >> num)) { return NULL; }
	if (!(getline(file,pri ))) { return NULL; }
	if (!(getline(file,bebi ))) { return NULL; }
	if (!(getline(file,acom ))) { return NULL; }
	if (!(getline(file,pos ))) { return NULL; }
	if (!(file >> p)) { return NULL; }
	if (!(getline(file,idrest ))) { return NULL; }
	
	return new combo(num, pri, bebi, acom, pos,p, idrest);
}

void combo::guardar(ofstream& c)
{
	c << getnum() << endl
		<< getprincipal() << endl
		<< getbebida() << endl
		<< getacompanna() << endl
		<< getpostre() << endl
		<< getprecio() << endl
		<< getidrest() << endl;
}



