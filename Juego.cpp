#include "Juego.h"
#include<ctime>
#include<cstdlib>

void Juego::InicializarEspacio()
{
	srand(time(NULL));
	espacio = new char* [6];
	int sol = 0;
	int estrella = 0;
	int planeta = 0;
	int randomFila = 0;
	int randomColumna = 0;
	for (int i = 0; i < 6; i++)
	{
		randomFila =  1 + (rand() % 5);
		randomColumna = 1 + (rand() % 5);
		espacio[i] = new char[6];
		if (sol != 5)
		{
			espacio[randomFila][randomColumna] = 'S';
			sol++;
		}
		if (estrella != 4)
		{
			espacio[randomFila][randomColumna] = 'E';
			estrella++;
		}

	}
}

void Juego::MostrarTablero()
{
}

void Juego::MoverNave(int direccion)
{
}

void Juego::VerificarColision()
{
}

void Juego::Aterrizar()
{
}

void Juego::JuegoTerminado()
{
}
Juego::Juego()
{
	InicializarEspacio();
}

Juego::~Juego()
{

}