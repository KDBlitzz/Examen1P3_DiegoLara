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
}
void menu() {
	ejercicio_1();
}
int main()
{
	srand(time(NULL));
    menu();
}