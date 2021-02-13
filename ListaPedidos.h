#pragma once
#include "nodoPedido.h"
class ListaPedidos{
private:
    nodoPedido* first;
    nodoPedido* actual;
public:
    ListaPedidos();
    ~ListaPedidos();
    void agregarIni(Pedido*);
    void agregarFinal(Pedido*);
    string toString();
    string toString2();
    bool estaVacia();
    bool eliminarEspecifico(int);
    void ordenarLista();
    bool eliminarIni();
    bool eliminaFinal();
    int cuentaNodos();
    bool busquedaid(int);
    Pedido* busquedaid2(int);
    string opcion2_2();
    bool estacliente(string);
    string clienterep(string);
    bool estarepartidor(string);
    string repartidorrep(string);
    int getidinicio();
    string opcion2_3(string);
    bool esta2_3(string);
    void guardar();
    static ListaPedidos* leer();
    int sacarModa();
};

