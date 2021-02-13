#pragma once
#include "nodoRepartidor.h"
#include<fstream>
class ListaRepartidores{
private:
    nodoRepartidor* first;
    nodoRepartidor* actual;
public:
    ListaRepartidores();
    ~ListaRepartidores();
    void agregarIni(Repartidor*);
    void agregarFinal(Repartidor*);
    string toString();
    string general();
    bool estaVacia();
    bool eliminarEspecifico(int);
    void ordenarLista();
    bool eliminarIni();
    bool eliminaFinal();
    int cuentaNodos();
    bool busquedaid(string);
    Repartidor* busquedaid2(string);
    Repartidor* getinicial();
    bool repartidordisponible();
    void guardar();
	static ListaRepartidores* Leer();

};

