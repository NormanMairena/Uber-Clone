#pragma once
#include "nodoQueja.h"
class ListaQuejas{
private:
    nodoQueja* first;
    nodoQueja* actual;
public:
    ListaQuejas();
    ~ListaQuejas();
    void agregarIni(Queja*);
    void agregarFinal(Queja*);
    string toString();
    bool estaVacia();
    bool eliminarEspecifico(string);
    void ordenarLista();
    bool eliminarIni();
    bool eliminaFinal();
    int cuentaNodos();
    bool busquedaid(string);
    Queja* busquedaid2(string);
    void guardar();
	static ListaQuejas* Leer(string);
	static ListaQuejas* Leersolo();
	
};

