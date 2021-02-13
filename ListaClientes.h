#pragma once
#include "nodoCliente.h"
class ListaClientes{
private:
    nodoCliente* first;
    nodoCliente* actual;
public:
    ListaClientes();
    ~ListaClientes();
    void agregarIni(Cliente*);
    void agregarFinal(Cliente*);
    string toString();
    bool estaVacia();
    bool eliminarEspecifico(string);
    void ordenarLista();
    bool eliminarIni();
    bool eliminaFinal();
    int cuentaNodos();
    bool busquedaid(string);
    Cliente* busquedaid2(string);
    string general();
    void guardar();
	static ListaClientes* Leer();
};

