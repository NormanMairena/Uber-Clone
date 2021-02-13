#pragma once
#include "nodoRestaurante.h"
class ListaRestaurantes{
private:
    nodoRestaurante* first;
    nodoRestaurante* actual;
public:
    ListaRestaurantes();
    ~ListaRestaurantes();
    void agregarIni(Restaurantes*);
    void agregarFinal(Restaurantes*);
    string toString();
    string toString2();
    bool estaVacia();
    bool eliminarEspecifico(string);
    void ordenarLista();
    bool eliminarIni();
    bool eliminaFinal();
    int cuentaNodos();
    bool busquedaid(string);
    Restaurantes* busquedaid2(string);
    void guardar();
    static ListaRestaurantes* leer();
};

