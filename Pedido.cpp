#include "Pedido.h"

Pedido::Pedido(int id, char est, float km, float tot, float pago,int h, Repartidor* R, ListaCombos* C, Cliente* CLT){
	this->id = id;
	this->estado = 'P';
	this->KM = km;
	this->total = tot;
	this->pagoRep = pago;
	this->Repart = R;
	this->Comb = C;
	this->Client = CLT;
	this->hora = h;
}
Pedido::Pedido():id(0),estado('P'),KM(0.0),total(0.0),pagoRep(0.0),hora(0),Repart(NULL),Comb(NULL),Client(NULL) {}
Pedido::~Pedido(){}
void Pedido::setid(int c){
	this->id = c;
}
void Pedido::setestado(char c){
	this->estado = c;
}
void Pedido::setKM(float c){
	this->KM = c;
}
void Pedido::settotal(float c){
	this->total = c;
}
void Pedido::setPagorep(float c){
	this->pagoRep = c;
}
void Pedido::setRepartidor(Repartidor* c){
	this->Repart = c;
}
void Pedido::setCombo(ListaCombos* c){
	this->Comb = c;
}
void Pedido::setCliente(Cliente* c){
	this->Client = c;
}
int Pedido::getID(){
	return id;
}
char Pedido::getestado(){
	return estado;
}
float Pedido::getKM(){
	return KM;
}
float Pedido::gettotal(){
	return total;
}
float Pedido::getpagoRep(){
	return pagoRep;
}
Repartidor* Pedido::getRepart(){
	return Repart;
}
ListaCombos* Pedido::getComb(){
	return Comb;
}
Cliente* Pedido::getClient(){
	return Client;
}
int Pedido::gethora() {
	return hora;
}
void Pedido::sethora(int hora) {
	this->hora = hora;
}
void Pedido::actualizarKM(float k){
	float x = getRepart()->getnumKilometrosRecorridos();
	getRepart()->setnumKilometrosRecorridos(x + k);
}
string Pedido::tostring(){
	stringstream s;
	s << "--Info del pedido--" << endl << endl
		<< Comb->toString()//
		<< "Subtot--------------------------"<<"("<< Comb->calcSumaTOT() + pagoRep <<")"<< endl
		<< "IVA: (13)------------------------"<<"("<< total * 0.13 <<")"<< endl
		<< "Costo de Envio-------------------" <<"("<< pagoRep <<")"<<endl
		<< "Total----------------------------"<<"("<< total +(total*0.13) <<")"<< endl;
	return s.str();
}
//tostring especifico para la opcion donde solo se muestra esto
string Pedido::tostring2() {
	stringstream s;
	s << "--Info del pedido--" << endl;
	s << "Numero de pedido: " << id <<" "<< "Estado:" << estado <<"  "<< endl;
	return s.str();
}
string Pedido::opcion2_2(){
		stringstream s;
	s << "--Info del pedido--" << endl;
	s << "Numero de pedido: "<< id <<"  "<< "Repartidor: " <<getRepart()->getnombre()<<"   "<< "Cliente: "<< getClient()->getnombre()<<"  "<< endl;
	return s.str();
}
int Pedido::getnumcombo()
{
	return Comb->getID_INIciO();
}

void Pedido::guardar(ofstream& c)
{
	
	c << getID() << '\t'
		<< getestado() << '\t'
		<< getKM() << '\t'
		<< gettotal() << '\t'
		<< getpagoRep() << '\t'
		<< gethora() << '\t';
	
	Comb->guardar_enpedido(c);
	

}

Pedido* Pedido::Leer(ifstream& c)
{
	int id; char est; float km; float tot; float pago; int h;
	if (!(c>>id)) { return NULL; }
	if (!(c>>est)) { return NULL; }
	if (!(c>>km)) { return NULL; }
	if (!(c>>tot)) { return NULL; }
	if (!(c>>pago)) { return NULL; }
	if (!(c>>h)) { return NULL; }
	return new Pedido(id, est, km, tot,pago,h);
}





