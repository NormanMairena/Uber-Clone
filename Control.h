#pragma once
#include<conio.h>
#include<string>
#include<time.h>
#include"Empresa.h"
#include<fstream>
using namespace std;
class Control{
private:
	Empresa* E;
public:
	Control(Empresa*);
	int ValidarEntero();
	void validarEntradaMenuPrincipal(int opcion, int parametro1, int parametro2);
	void validarSalida(int opcion2);
	bool validarEstadoRepartidor(char);
	void menu();
	void SubMenuRegistros();
	void SubMenuQuejasReportes();
	void SubMenuPedidos();
	//--------------Metodos 1---------------------
	void opcion1_1();
	void opcion1_2();
	void opcion1_3();
	void opcion1_4();
	void opcion1_5();
	void opcion1_6();
	void opcion1_7();
	//--------------Metodos 2---------------------
	void opcion2_1();
	void opcion2_2();
	void opcion2_3();
	void opcion2_4();
	void opcion2_5();
	void opcion2_6();
	void opcion2_7();
	//--------------Metodos 3----------------------
	void opcion3_1();
	void opcion3_2();
	void opcion3_3();
	//--------------4----------------------
	void opcion4();
};

