#include "Control.h"
Control::Control(Empresa* emp) :E(emp) {}
int Control::ValidarEntero() {
	int	Respuesta;
	bool validar = true;
	while (validar) {
		if (cin >> Respuesta) {
			return Respuesta;
		}
		else {
			cout << "Respuesta invalida, digite un numero entero(Ej.1, 2 ,3 ...)" << endl;
			cin >> Respuesta;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}
bool Control::validarEstadoRepartidor(char i) {
	if (i == 'L' || i == 'F' || i == 'S') {
		return true;
	}
	else {
		cout << "Valores invalidos, digite (L.Libre, F.Fuera de Servicio, S. suspendido)" << endl;
		cin >> i;
		return false;
	}
}
void Control::validarEntradaMenuPrincipal(int opcion, int parametro1, int parametro2) {
	if (opcion<parametro1 || opcion>parametro2) {
		cout << "Opcion invalida" << endl;
		cout << "Digite nuevamente el numero que desea" << endl;
		opcion = ValidarEntero();
	}
}
void Control::validarSalida(int opcion2) {
	cout << "Desea realizar otra accion" << endl;
	opcion2 = ValidarEntero();
	validarEntradaMenuPrincipal(opcion2, 1, 2);
	if (opcion2 == 2) {
		exit(0);
	}
	cout << "Digite <ENTER> para continuar" << endl;
	cin.get();
	cin.get();
	system("cls");
}
void Control::menu() {
	int opcionInicio = 1;
	int opcionMenu = 5;
	while (opcionInicio == 1) {
		cout << "-------Menu Principal-------" << endl;
		cout << "Cleta Eats" << endl;
		cout << "1.SubMenu registros basicos" << endl;
		cout << "2.SubMenu Pedidos" << endl;
		cout << "3.SubMenu Quejas y Reportes" << endl;
		cout << "4.SubMenu Archivos " << endl;
		cout << "5.Salir y guardar" << endl;
		opcionMenu = ValidarEntero();
		validarEntradaMenuPrincipal(opcionMenu, 1, 5);
		cout << "Digite <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		switch (opcionMenu) {
		case 1:
			SubMenuRegistros();
			break;
		case 2:
			SubMenuPedidos();
			break;
		case 3:
			SubMenuQuejasReportes();
			break;
		case 4:
			opcion4();
			break;
		case 5:
			if (E->getclientes()->estaVacia()==false)
			{
				E->getclientes()->guardar();
			}
			if (E->getpedidos()->estaVacia()==false)
			{
				E->getpedidos()->guardar();
				
			}
			if (E->getrepartidores()->estaVacia()==false)
			{
				E->getrepartidores()->guardar();
			}
			if (E->getrestaurante()->estaVacia()==false)
			{
				E->getrestaurante()->guardar();
			}
			E->getcombos()->guardar();
			
			exit(0);
			break;
		}
		validarSalida(opcionInicio);
	}
}
void Control::SubMenuRegistros() {
	int opcionInicio1 = 0;
	int opcionMenu1;
	string nombreRestaurantes, cedulaRestaurantes, direccionRestaurantes, tipodecomida;
	do {
		cout << "-----------Submenu Registros basicos----------" << endl;
		cout << "\t1.Incluir Clientes" << endl;
		cout << "\t2.Mostrar Clientes" << endl;
		cout << "\t3.Incluir Repartidor" << endl;
		cout << "\t4. Mostrar Repartidores" << endl;
		cout << "\t5.Incluir Restaurantes" << endl;
		cout << "\t6.Mostrar Restaurantes y Menus" << endl;
		cout << "\t7.Incluir Combo  a Restaurante Especifico" << endl;
		cout << "\t8. Regresar Menu Principal" << endl;
		opcionMenu1 = ValidarEntero();
		validarEntradaMenuPrincipal(opcionMenu1, 1, 8);
		cout << "Digite <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		switch (opcionMenu1) {
		case 1:
			opcion1_1();
			break;
		case 2:
			opcion1_2();
			break;
		case 3:
			opcion1_3();
			break;
		case 4:
			opcion1_4();
			break;
		case 5:
			opcion1_5();
			break;
		case 6:
			opcion1_6();
			break;
		case 7:
			opcion1_7();
			break;
		case 8:
			menu();
			break;
		}
	} while (opcionInicio1);
}
void Control::SubMenuQuejasReportes() {
	int opcionInicio1 = 0;
	int opcionMenu1;
	do {
		cout << "\t1.Reportar quejas por parte del cliente" << endl;
		cout << "\t2.Detalle quejas por reaprtidor" << endl;
		cout << "\t3.Hora pico" << endl;
		cout << "\t4. Regresar menu principal" << endl;
		opcionMenu1 = ValidarEntero();
		validarEntradaMenuPrincipal(opcionMenu1, 1, 4);
		cout << "Digite <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		switch (opcionMenu1) {
		case 1:
			opcion3_1();
			break;
		case 2:
			opcion3_2();
			break;
		case 3:
			opcion3_3();
			break;
		case 4:
			menu();
			break;
		}
	} while (opcionInicio1);
}
void Control::SubMenuPedidos() {
	int opcionInicio1 = 0;
	int opcionMenu1;
	do {
		cout << "\t1.Realizar Pedido" << endl;
		cout << "\t2. Detalle General de Pedidos " << endl;
		cout << "\t3. Detalle Pedidos por Restaurante" << endl;
		cout << "\t4. Detalle Pedidos por Cliente" << endl;
		cout << "\t5. Detalle Pedidos por Repartidor" << endl;
		cout << "\t6. Cambiar Estado de Pedido" << endl;
		cout << "\t7. Reportar entrega y disponibilidad del repartidor" << endl;
		cout << "\t8. Regresar Menu Principal" << endl;
		opcionMenu1 = ValidarEntero();
		validarEntradaMenuPrincipal(opcionMenu1, 1, 8);
		cout << "Digite <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		switch (opcionMenu1) {
		case 1:
			opcion2_1();
			break;
		case 2:
			opcion2_2();
			break;
		case 3:
			opcion2_3();
			break;
		case 4:
			opcion2_4();
			break;
		case 5:
			opcion2_5();
			break;
		case 6:
			opcion2_6();
			break;
		case 7:
			opcion2_7();
			break;
		case 8:
			menu();
			break;
		}
	} while (opcionInicio1);
}
//--------------Metodos 1---------------------
void Control::opcion1_1() {

	string nombreCliente, cedulaCliente, targetaCliente, direccionCliente, correoCliente, celularCliente;
	cout << "1.1 - Incluir Clientes" << endl;
	cout << "Digite cedula :" << endl;
	cin >> cedulaCliente;
	if (E->getclientes()->busquedaid(cedulaCliente) == false) {
		cout << "Digite numero de tarjeta:" << endl;
		cin >> targetaCliente;
		cout << "Digite correo:" << endl;
		cin >> correoCliente;
		cout << "Digite celular:" << endl;
		cin >> celularCliente;
		cin.get();
		cout << "Digite direccion:" << endl;
		getline(cin, direccionCliente);
		cout << "Digite el nombre :" << endl;
		getline(cin, nombreCliente);
		Cliente* c = new Cliente(cedulaCliente, nombreCliente, targetaCliente, celularCliente, direccionCliente, correoCliente);
		E->getclientes()->agregarFinal(c);
		
	}
	else {
		cout << "Ese cliente ya se encuentra registrado" << endl;
		cout << "Digite <ENTER> para registrar un cliente valido" << endl;
		cin.get();
		cin.get();
		system("cls");
		opcion1_1();
	}
}
void Control::opcion1_2() {
	if (E->getclientes()->estaVacia() == false) {
		string x;
		cout << endl << "-------Lista de Clientes---------" << endl << endl;
		cout << E->getclientes()->general() << endl;
		cout << "Que cliente desea visualizar(ID)" << endl;
		cin >> x;
		cout << "Digite <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		if (E->getclientes()->busquedaid(x)) {
			cout << E->getclientes()->busquedaid2(x)->toStringCliente();
		}
		else {
			while (E->getclientes()->busquedaid(x) == false) {
				cout << E->getclientes()->general() << endl;
				cout << "El cliente no existe ingrese uno de los existentes o si quiere salir presione(0)" << endl;
				cin >> x;
				cout << "Digite <ENTER> para continuar" << endl;
				cin.get();
				cin.get();
				system("cls");
				if (E->getclientes()->busquedaid(x)) {
					cout << E->getclientes()->busquedaid2(x)->toStringCliente(); break;
				}
				if (x == "0") {
					break;
				}

			}
		}
	}
	else {
		cout << "No existen clientes actualmente ingresados" << endl;
		cout << "Digite <ENTER> para ingresar un cliente en el sistema" << endl;
		cin.get();
		cin.get();
		system("cls");
		SubMenuRegistros();
	}
}
void Control::opcion1_3() {

	string nombreRepartidor, cedulaRepartidor, correoRepartidor, celularRepartidor;
	char estado;
	cout << " --Incluir Repartidor--" << endl;
	cout << "Digite cedula : " << endl;
	cin >> cedulaRepartidor;
	if (E->getrepartidores()->busquedaid(cedulaRepartidor) == false) {
		cout << "Estado: " << endl;
		cin >> estado;
		validarEstadoRepartidor(estado);
		cout << "Digite correo:" << endl;
		cin >> correoRepartidor;
		cout << "Digite celular:" << endl;
		cin >> celularRepartidor;
		cin.get();
		cout << "Digite el nombre: " << endl;
		getline(cin, nombreRepartidor);
		ListaQuejas* q = new ListaQuejas();
		Repartidor* R = new Repartidor(cedulaRepartidor, nombreRepartidor, celularRepartidor, correoRepartidor, estado, 0, 0, q);
		E->getrepartidores()->agregarFinal(R);
		cin.get();
	}
	else {
		cout << "El usuario ya existe" << endl;
		cout << "Digite <ENTER> para registrar un usuario valido" << endl;
		cin.get();
		cin.get();
		system("cls");
		opcion1_3();
	}
}
void Control::opcion1_4() {
	if (E->getrepartidores()->estaVacia() == false) {
		string x;
		cout << endl << "-------Lista de Repartidores---------" << endl << endl;
		cout << E->getrepartidores()->general() << endl;
		cout << "Que Repartidor desea visualizar(ID)" << endl;
		cin >> x;
		cout << "Digite <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		if (E->getrepartidores()->busquedaid(x)) {
			cout << E->getrepartidores()->busquedaid2(x)->toStringRepartidores();
		}
		else {
			while (E->getclientes()->busquedaid(x) == false) {
				cout << E->getrepartidores()->general() << endl;
				cout << "El repartidor no existe ingrese uno de los existentes o si quiere salir ponga (0)" << endl;
				cin >> x;
				if (E->getrepartidores()->busquedaid(x)) {
					cout << E->getrepartidores()->busquedaid2(x)->toStringRepartidores(); break;
				}
				if (x == "0") {
					break;
				}
			}
		}
	}
	else {
		cout << "No existen repartidores actualmente ingresados" << endl;
		cout << "Digite <ENTER> para ingresar un repartidor en el sistema" << endl;
		cin.get();
		cin.get();
		system("cls");
		SubMenuRegistros();
	}
}
void Control::opcion1_5() {
	string nombreRestaurantes, cedulaRestaurantes, direccionRestaurantes, tipodecomida;
	cout << " --Incluir Restaurante--" << endl;
	cout << "Digite cedula : " << endl;
	cin >> cedulaRestaurantes;
	if (E->getrestaurante()->busquedaid(cedulaRestaurantes) == false) {
		cout << "Digite el nombre : " << endl;
		cin.get();
		getline(cin, nombreRestaurantes);
		cout << "Direccion: " << endl;
		getline(cin, direccionRestaurantes);
		cout << "Tipo de comida:" << endl;
		cin >> tipodecomida;
		ListaCombos* l = new ListaCombos();
		Restaurantes* Re = new Restaurantes(nombreRestaurantes, cedulaRestaurantes, direccionRestaurantes, tipodecomida, l);
		E->getrestaurante()->agregarFinal(Re);
	}
	else {
		cout << "el restaurante ya existe, intente con una cedula juridica valida" << endl;
		cout << "Digite <ENTER> para registrar un restaurante valido" << endl;
		cin.get();
		cin.get();
		system("cls");
		opcion1_5();
	}
}
void Control::opcion1_6() {
	if (E->getrestaurante()->estaVacia() == false) {
		cout << endl << "-------Lista de Restaurantes con sus menus---------" << endl << endl;
		string x;
		cout << E->getrestaurante()->toString2() << endl;
		cout << "Que Restaurante desea visualizar(ID)" << endl;
		cin >> x;
		cout << "Digite <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		if (E->getrestaurante()->busquedaid(x)) {
			cout << E->getrestaurante()->busquedaid2(x)->toStringRestaurantes();
		}
		else {
			while (E->getrestaurante()->busquedaid(x) == false) {
				cout << E->getrestaurante()->toString2() << endl;
				cout << "el restaurante no existe, ingrese uno de los existentes o si quiere salir presione(0)" << endl;
				cin >> x;
				if (E->getrestaurante()->busquedaid(x)) {
					cout << E->getrestaurante()->busquedaid2(x)->toStringRestaurantes(); break;
				}
				if (x == "0") {
					break;
				}

			}
		}
	}
	else {
		cout << "No existen restaurantes actualmente ingresados" << endl;
		cout << "Digite <ENTER> para ingresar un restaurante en el sistema" << endl;
		cin.get();
		cin.get();
		system("cls");
		SubMenuRegistros();
	}
}
void Control::opcion1_7() {
	string id;
	if (E->getrestaurante()->estaVacia() == false) {
		cout << "------Insertar combo a restaurante-------" << endl << endl;
		cout << "Lista de restaurantes" << endl;
		cout << E->getrestaurante()->toString2() << endl;
		cout << "Ingrese la identificacion del restaurante" << endl;
		cin >> id;
		cout << "Digite <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		if (E->getrestaurante()->busquedaid(id)) {
			cout << E->getrestaurante()->busquedaid2(id)->toStringRestaurantes() << endl;
			int numCombo;
			float precio;
			string principal, bebida, acomp, postre;
			cout << "Digite el numero del nuevo combo" << endl;
			numCombo = ValidarEntero();
			if (E->getrestaurante()->busquedaid2(id)->getlistacombos()->busquedaid(numCombo) == false) {
				cin.get();
				cout << "Ingrese el plato principal del combo:" << endl;
				getline(cin, principal);
				cout << "Ingrese la bebida del combo:" << endl;
				getline(cin, bebida);
				cout << "Ingrese el acompannamiento del combo:" << endl;
				getline(cin, acomp);
				cout << "Ingrese el postre del combo:" << endl;
				cout << "|Recuerda, si no sedeas poner postre rellena con un (no)|:" << endl;
				getline(cin, postre);//too
				cout << "Precio:" << endl;
				cin >> precio;
				combo* C = new combo(numCombo, principal, bebida, acomp, postre, precio, id);
				E->getrestaurante()->busquedaid2(id)->getlistacombos()->agregarFinal(C);
			}
			else {
				while (E->getrestaurante()->busquedaid2(id)->getlistacombos()->busquedaid(numCombo) && numCombo != -1) {
					cout << "Codigo de combo existente, ingrese un codigo diferente" << endl;
					cin >> numCombo;
					cin.get();
					if (E->getrestaurante()->busquedaid2(id)->getlistacombos()->busquedaid(numCombo) == false) {
						cout << "Ingrese el plato principal del combo:" << endl;
						getline(cin, principal);
						cout << "Ingrese la bebida del combo:" << endl;
						getline(cin, bebida);
						cout << "Ingrese el acompannamiento del combo:" << endl;
						getline(cin, acomp);
						cout << "Ingrese el postre del combo:" << endl;
						cout << "|Recuerda, si no sedeas poner postre rellena con un (no)|:" << endl;
						getline(cin, postre);//too
						cout << "Precio:" << endl;
						cin >> precio;
						cin.get();
						combo* C = new combo(numCombo, principal, bebida, acomp, postre, precio);
						E->getrestaurante()->busquedaid2(id)->getlistacombos()->agregarFinal(C);
						break;
					}
				}
			}
		}
		else {
			cout << "El restaurante con ese id no existe" << endl;
			opcion1_7();
		}
	}
	else {
		cout << "No existen restaurantes actualmente ingresados" << endl;
		cout << "Digite <ENTER> para ingresar un restaurante en el sistema" << endl;
		cin.get();
		cin.get();
		system("cls");
		SubMenuRegistros();
	}
}
//--------------Metodos 2---------------------
void Control::opcion2_1() {
	if (E->listoparapedir()) {
		if (E->getrepartidores()->repartidordisponible() == true)
		{
			srand(time(NULL));
			ListaCombos* LC = new ListaCombos();
			cout << "Realice su pedido AQUI!!" << endl;
			cout << E->getclientes()->general();
			cout << "Digite el ID del cliente para realizar el pedido" << endl;
			string id;
			cin >> id;
			cout << "Digite <ENTER> para continuar" << endl;
			cin.get();
			cin.get();
			system("cls");
			if (E->getclientes()->busquedaid(id) == true) {
				cout << "Bienvenido " << E->getclientes()->busquedaid2(id)->getnombre() << "!!!!" << endl << endl << endl;
				cout << "Le ofrecemos los siguientes restaurantes" << endl << endl;
				cout << E->getrestaurante()->toString2() << endl;
				string idrest;
				cout << "Elija el restaurante de su preferencia(ID)" << endl;
				cin >> idrest;
				cout << "Digite <ENTER> para continuar" << endl;
				cin.get();
				cin.get();
				system("cls");
				if (E->getrestaurante()->busquedaid(idrest) == true) {
					cout << "Usted ha elegido el restaurante: " << E->getrestaurante()->busquedaid2(idrest)->getnombre() << endl << endl << endl;
					int i;
					int i2 = 1;
					int i3;
					int num_orden;
					float KM;
					while (i2 == 1) {
						num_orden = rand() % 4000;
						cout << "LISTA DE COMBOS" << endl;
						cout << E->getrestaurante()->busquedaid2(idrest)->getlistacombos()->toString() << endl;
						cout << "Digite el numero de combo que desea incluir en su orden" << endl;
						cin >> i;
						if (E->getrestaurante()->busquedaid2(idrest)->getlistacombos()->busquedaid(i) == true) {
							cout << "Cantidad";
							cin >> i3;
							if (E->getpedidos()->busquedaid(num_orden) == false) {
								for (int k = 0; k < i3; k++) {
									LC->agregarFinal(E->getrestaurante()->busquedaid2(idrest)->getlistacombos()->busquedaid2(i));
								}
							}
							else {
								cout << "Id del pedido existente, ingrese uno diferente" << endl;
								opcion2_1();
							}
							if (E->getpedidos()->busquedaid(num_orden) == false) {
								cout << "Desea pedir otro combo 1.Si, 2.No: " << endl;
								cin >> i2;
							}
						}
						else {
							cout << "el combo no existe" << endl;
							opcion2_1();
						}
					}
					cout << "Ingrese la cantidad de Km de su envio" << endl;
					cin >> KM;
					float pk = KM;
					if (KM < 1)
					{
						pk = 1;
					}
					cout << "Ingrese la hora de realizacion del pedido" << endl;
					int hora;
					cin >> hora;
					cout << "Digite <ENTER> para continuar" << endl;
					cin.get();
					cin.get();
					system("cls");
					cout << "Detalle de pedido :" << endl;
					cout << "Repartidor Asignado :" << E->getrepartidores()->getinicial()->general();
					cout << "Restaurante :" << E->getrestaurante()->busquedaid2(idrest)->getnombre() << endl;
					cout << "Cliente: " << E->getclientes()->busquedaid2(id)->general() << endl;
					cout << "Direccion : " << E->getclientes()->busquedaid2(id)->getdireccionExacta() << endl;
					cout << "Kilometros: " << KM << endl;
					cout << "Estado : en preparacion" << endl << endl;
					Pedido* P = new Pedido(num_orden, 'P', KM, 0, (pk * 1000), hora, E->getrepartidores()->getinicial(), LC, E->getclientes()->busquedaid2(id));
					E->getrepartidores()->getinicial()->actualizar(KM);
					E->getpedidos()->agregarFinal(P);
					E->getpedidos()->busquedaid2(num_orden)->settotal(E->getpedidos()->busquedaid2(num_orden)->getComb()->calcSumaTOT() + E->getpedidos()->busquedaid2(num_orden)->getpagoRep());//suma los precios de combos
					cout << E->getpedidos()->busquedaid2(num_orden)->tostring();
				}
				else {
					cout << "El restaurante no existe" << endl;
				}

			}
			else {
				cout << "Cliente no existente, ingrese un usuario valido" << endl;
				cout << "Digite <ENTER> para continuar" << endl;
				cin.get();
				cin.get();
				system("cls");
				opcion2_1();
			}
		}
		else
		{
			cout << "Lo sentimos, no tenemos repartidores disponibles en este momento" << endl;
		}
	}
	else {
		cout << "Sistema fuera de servicio, redirigiendo al inicio" << endl;
	}
	cout << "Digite <ENTER> para continuar" << endl;
	cin.get();
	cin.get();
	system("cls");
	menu();
}
void Control::opcion2_2() {
	if (E->getpedidos()->estaVacia() == false) {
		cout << "Lista de pedidos " << endl;
		cout << E->getpedidos()->opcion2_2();
		cout << "Cual pedido desea visualizar" << endl;
		int numPedido;
		cin >> numPedido;
		cout << "Digite <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		if (E->getpedidos()->busquedaid(numPedido) == true) {
			cout << E->getpedidos()->busquedaid2(numPedido)->tostring();
		}
		else {
			cout << "!!!!No se encontro el pedido¡¡¡¡¡¡" << endl << endl << endl;
			cout << "Digite <ENTER> para continuar" << endl;
			cin.get();
			cin.get();
			system("cls");
			opcion2_2();
		}
	}
	else {
		cout << "!!!!No se encontro el pedido¡¡¡¡¡¡" << endl << endl << endl;
		cout << "Digite <ENTER> para ingresar un pedido en el sistema" << endl;
		cin.get();
		cin.get();
		system("cls");
		SubMenuPedidos();
	}
}
void Control::opcion2_3() {
	string idR;
	if (E->getrestaurante()->estaVacia() == false) {
		cout << "Lista de restaurantes" << endl;
		cout << E->getrestaurante()->toString2();
		cout << "Digite el ID  del restaurante del que desea visualiza sus pedidos: ";
		cin >> idR;
		cout << "Digite <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		if (E->getrestaurante()->busquedaid(idR) == true) {

			cout << E->getpedidos()->opcion2_3(idR);
		}
		else
		{
			cout << "El restaurante no existe" << endl;
			cout << "Digite <ENTER> para continuar" << endl;
			cin.get();
			cin.get();
			system("cls");
			opcion2_3();
		}
	}
	else {
		cout << "--No hay restaurantes registrados--" << endl;
		cout << "Digite <ENTER> para registrar un restaurante" << endl;
		cin.get();
		cin.get();
		system("cls");
		SubMenuRegistros();
	}
}
void Control::opcion2_4() {
	string idC;
	if (E->getclientes()->estaVacia() == false) {
		cout << "Lista de Clientes" << endl;
		cout << E->getclientes()->toString() << endl;
		cout << "Digite la cedula del cliente";
		cin >> idC;
		cout << "Digite <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		if (E->getpedidos()->estacliente(idC) == true) {
			cout << E->getpedidos()->clienterep(idC);
		}
		else {
			cout << "No encontro cliente con pedido" << endl;
			cout << "Digite <ENTER> para continuar" << endl;
			cin.get();
			cin.get();
			system("cls");
			opcion2_4();

		}
	}
	else
	{
		cout << "No hay clientes registrados" << endl;
		cout << "Digite <ENTER> para registrar un cliente" << endl;
		cin.get();
		cin.get();
		system("cls");
		SubMenuRegistros();
	}
}
void Control::opcion2_5() {
	string idR;
	if (E->getrepartidores()->estaVacia() == false) {
		cout << "Lista de Repartidores" << endl;
		cout << E->getrepartidores()->toString() << endl;
		cout << "Digite la cedula del repartidor";
		cin >> idR;
		if (E->getpedidos()->estarepartidor(idR) == true) {
			cout << E->getpedidos()->repartidorrep(idR);
		}
		else {
			cout << "No se ha asignado ese repartidor " << endl;
			cout << "Digite <ENTER> para continuar" << endl;
			cin.get();
			cin.get();
			system("cls");
			opcion2_5();
		}
	}
	else
	{
		cout << "No hay repartidores" << endl;
		cout << "Digite <ENTER> para registrar un repartidor" << endl;
		cin.get();
		cin.get();
		system("cls");
		SubMenuRegistros();
	}
}
void Control::opcion2_6() {
	if (E->getpedidos()->estaVacia() == false) {
		cout << "Digite el numero del pedido" << endl;
		int numeroP;
		cin >> numeroP;
		cout << "Digite <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		if (E->getpedidos()->busquedaid(numeroP) == true) {
			cout << "Estado actual del pedido" << E->getpedidos()->busquedaid2(numeroP)->getestado() << endl << endl;
			cout << "A cual estado desea cambiar el pedido('P'=En preparacion)('C'=En camino)('E'=Entregado)('S'=Suspendido)" << endl;
			char opcion;
			cin >> opcion;
			if (opcion == 'C') {
				E->getpedidos()->busquedaid2(numeroP)->setestado('C');
			}
			else if (opcion == 'E') {
				E->getpedidos()->busquedaid2(numeroP)->setestado('E');
			}
			else if (opcion == 'P') {
				E->getpedidos()->busquedaid2(numeroP)->setestado('P');
			}
			else if (opcion == 'S') {
				E->getpedidos()->busquedaid2(numeroP)->setestado('S');
			}
		}
	}
	else {
		cout << "No se han realizado pedidos" << endl;
		cout << "Digite <ENTER> para realizar un pedido" << endl;
		cin.get();
		cin.get();
		system("cls");
		SubMenuPedidos();
	}
}
void Control::opcion2_7() {
	if (E->getpedidos()->estaVacia() == false) {
		int num;
		int num2;
		cout << "Digite el numero de pedido " << endl;
		cin >> num;
		cout << "Digite <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		if (E->getrepartidores()->estaVacia() == false) {
			if (E->getpedidos()->busquedaid(num) == true) {
				cout << "Hola  " << E->getpedidos()->busquedaid2(num)->getRepart()->getnombre() << "que ha pasado con la orden:" << "[" << num << "]" << endl;
				cout << "(1)  Ya lo entregue satisfactoriamente" << endl;
				cout << "(2)  Estoy demorado" << endl;
				string entregado = "entregado";
				string demorado = "demorado";
				cin >> num2;
				if (num2 == 1) {
					cout << entregado << endl;
				}
				else {
					cout << demorado << endl;
				}
				cout << "Deseas:  (1) Quedar disponible para otra entrega  (2) quedar fuera de servicio por hoy" << endl;
				int opcionM;
				cin >> opcionM;
				if (opcionM == 1) {
					E->getpedidos()->busquedaid2(num)->getRepart()->setestado('L');
				}
				else {
					E->getpedidos()->busquedaid2(num)->getRepart()->setestado('F');
				}
			}
		}
		else
		{
			cout << "No hay repartidores registrados" << endl;
			cout << "Digite <ENTER> para registrar un reaprtidor" << endl;
			cin.get();
			cin.get();
			system("cls");
			SubMenuRegistros();
		}
	}
	else {
		cout << "No hay pedidos registrados" << endl;
		cout << "Digite <ENTER> para registrar un pedido" << endl;
		cin.get();
		cin.get();
		system("cls");
		SubMenuPedidos();
	}
}
//--------------Metodos 3----------------------
void Control::opcion3_1() {
	if (E->listoparapedir() && E->getpedidos()->estaVacia() == false) {
		string cedC;
		int dia, mes, hora, minu, año = 2020, num2;
		string descripcion;
		cout << "Digite su ced : " << endl << endl;
		cin >> cedC;
		if (E->getclientes()->busquedaid(cedC) == true)
		{

			cout << "Bienvenido: " << E->getclientes()->busquedaid2(cedC)->getnombre() << endl;
			cout << "Digite el día :" << endl;
			cin >> dia;
			cout << "Digite el mes :" << endl;
			cin >> mes;
			cout << "Digite la hora(18, 19, 1, 2) :" << endl;
			cin >> hora;
			cout << "Digite los minutos(20, 30, 45, 12) :" << endl;
			cin >> minu;
			cin.get();
			cin.get();
			system("cls");
			cout << "Digite ENTER para continuar con su queja" << endl << endl;
			cout << "Fecha: " << dia << "/" << mes << "/" << año << endl;
			cout << "Hora: " << hora << ":" << minu << endl;
			cout << "Numeros de orden existentes" << endl;
			cout << E->getpedidos()->toString2();
			cout << "Digite el numero de orden :" << endl;
			cin >> num2;
			cout << "Digite <ENTER> para continuar" << endl;
			cin.get();
			cin.get();
			system("cls");
			if (E->getpedidos()->busquedaid(num2) == true) {
				cout << "PEDIDO ENCONTRADO PROCEDEMOS A REALIZAR LA DESCRIPCION DE LA QUEJA" << endl << endl;
				cout << "El repartido asignado fue : " << E->getpedidos()->busquedaid2(num2)->getRepart()->getnombre() << endl;
			
				string num;
				string numrep = E->getpedidos()->busquedaid2(num2)->getRepart()->getcedula();
			
				cin.get();
				cout << "Detalle de la queja : " << endl;
				getline(cin, descripcion);
				Queja* q = new Queja(descripcion, numrep, dia, mes, hora, minu);
				E->getrepartidores()->busquedaid2(numrep)->nuevaqueja(q);
			}
			else
			{
				cout << "No existe ese numero de orden porfavor intentenlo de nuevo" << endl;
			}

		}
		else
		{
			cout << "No existe ese cliente de orden porfavor intentenlo de nuevo" << endl;
		}
	}
	else {
		cout << "Datos faltantes, presione <ENTER> para volver al menu principal" << endl;
		cin.get();
		cin.get();
		system("cls");
		menu();
	}
}
void Control::opcion3_2() {
	if (E->getrepartidores()->estaVacia() == false) {
		cout << "Lista de repartidores" << endl;
		cout << E->getrepartidores()->general();
		cout << "Digite  ced del repartidor:" << endl;
		string id;
		cin >> id;
		cout << "Digite <ENTER> para continuar" << endl;
		cin.get();
		cin.get();
		system("cls");
		if (E->getrepartidores()->busquedaid(id) == true) {
			if (E->getrepartidores()->busquedaid2(id)->getQuejas()->estaVacia() == false) {
				cout << E->getrepartidores()->busquedaid2(id)->getQuejas()->toString();
			}
			else {
				cout << "Este repartidor no presenta quejas" << endl;
				cout << "Digite <ENTER> para volver a intentarlo" << endl;
				cin.get();
				cin.get();
				system("cls");

			}

		}
		else {
			cout << "No se encontro repartidor con ese id" << endl;
			cout << "Digite <ENTER> para volver a intentarlo" << endl;
			cin.get();
			cin.get();
			system("cls");
			opcion3_2();
		}
	}
	else {
		cout << "No se encontro repartidor" << endl;
		cout << "Digite <ENTER> para registrar un repartidor" << endl;
		cin.get();
		cin.get();
		system("cls");
		menu();
	}

}
void Control::opcion3_3() {
	cout << "la hora con mas concurrencia es: ";
	cout<<E->getpedidos()->sacarModa()<<endl;
}
void Control::opcion4() {
	int opcion;
	cout << "\tMenu de archivos" << endl;
	cout << "1.Leer archivos de clientes" << endl;
	cout << "2.Leer archivos de repartidores" << endl;
	/*cout << "3.Leer archivos de pedidos" << endl;*/
	cout << "4.Leer archivos de restaurantes" << endl;
	cout << "5.Leer archivos de quejas" << endl;
	/*cout << "6.Leer archivos de combos" << endl;*/
	cout << "7.Volver al menu Principal" << endl;
	opcion = ValidarEntero();
	validarEntradaMenuPrincipal(opcion, 1, 7);
	switch (opcion) {
	case 1:
		cout<<E->getclientes()->Leer()->toString();break;
	case 2:
		cout << E->getrepartidores()->Leer()->toString();break;
	case 3:
		
		cout<<E->getpedidos()->leer()->toString();
		break;
	case 4:
		cout << E->getrestaurante()->leer()->toString();
		break;
	case 5:
		cout << E->getquejas()->Leersolo()->toString();
	case 6:
		cout << E->getcombos()->Leer()->toString();break;
	case 7:
		menu(); break;
	}
}


