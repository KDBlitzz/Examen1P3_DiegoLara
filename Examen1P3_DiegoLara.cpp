#include "Juego.h"
#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void ejercicio_1() {
	char** espacio = nullptr;
	Juego *juego = new Juego(espacio);
	bool terminar = true;
	int moverse = 0;
	int tripulante = 0;
	int combustible = 0;
	cout << "Ingrese el numero de pasajeros(entre 15 y 28) " << endl;
	cin >> tripulante;
	while (tripulante < 15 || tripulante >= 29) {
		cout << "Ingrese una cantidad de pasajeros entre 15 y 28 " << endl;
		cin >> tripulante;
	}
	juego->settcantidadPersonas(tripulante);
	cout << "Ingrese el numero combustible(entre 100 y 500) " << endl;
	cin >> combustible;
	while (combustible < 100 || combustible >= 501) {
		cout << "Ingrese una cantidad de combustible entre 100 y 500 " << endl;
		cin >> combustible;
	}
	juego->settcantidadCombustible(combustible);
	juego->InicializarEspacio(espacio);
	juego->MostrarTablero(espacio);
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