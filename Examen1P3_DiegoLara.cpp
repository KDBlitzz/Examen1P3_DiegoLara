#include "Juego.h"
#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void ejercicio_1() {
	char** espacio = nullptr;
	Juego *juego = new Juego(espacio);
	juego->InicializarEspacio(espacio);
	juego->MostrarTablero(espacio);
	bool terminar = true;
	int moverse = 0;
	while (terminar) {
		cout << "Direccion a moverse" << endl;
		cout << "1. Arriba" << endl;
		cout << "2. Abajo" << endl;
		cout << "3. Derecha" << endl;
		cout << "4. Izquierda" << endl;
		cin >> moverse;
		switch (moverse) {
		case 1:
			juego->MoverNave(moverse, espacio);
			juego->MostrarTablero(espacio);
			break;
		case 2:
			juego->MoverNave(moverse, espacio);
			juego->MostrarTablero(espacio);
			break;
		case 3:
			juego->MoverNave(moverse, espacio);
			juego->MostrarTablero(espacio);
			break;
		case 4:
			juego->MoverNave(moverse, espacio);
			juego->MostrarTablero(espacio);
			break;
		default:
			cout << "Opcion Invalida" << endl;
		}
	}
}
void menu() {
	int option = 0;
	bool menu = true;
	while (menu) {
		cout << "Ejercicio Práctico 1 – Viaje a Marte" << endl;
		cout << "2. Salir" << endl;
		cin >> option;
		switch (option) {
		case 1:
			ejercicio_1();
			break;
		case 2:
			menu = false;
			break;
		default:
			cout << "Opcion Invalida" << endl;
		}
	}
}
int main()
{
	srand(time(NULL));
    menu();
}