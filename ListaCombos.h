#pragma once
#include "nodoCombo.h"
#include<fstream>
class ListaCombos{
private:
    nodoCombo* first;
    nodoCombo* actual;
public:
    ListaCombos();
    ~ListaCombos();
    void agregarIni(combo*);
    void agregarFinal(combo*);
    string toString();
    bool estaVacia();
    bool eliminarEspecifico(int);
    void ordenarLista();
    bool eliminarIni();
    bool eliminaFinal();
    int cuentaNodos();
    bool busquedaid(int);
    combo* busquedaid2(int);
    //especial
    float calcSumaTOT();
    int getID_INIciO();
    bool opcion2_3(string);
    //arch
    void guardar();
    void guardar_enpedido(ofstream&);
	static ListaCombos* Leer();
};

