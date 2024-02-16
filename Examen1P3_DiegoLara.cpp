#include "Juego.h"
#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void ejercicio_1() {
	Juego *juego = new Juego();
	juego->InicializarEspacio();
}
void menu() {
}
int main()
{
	srand(time(NULL));
    menu();
}