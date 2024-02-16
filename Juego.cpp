#include <iostream>
#include "Juego.h"
#include<ctime>
#include<cstdlib>
using namespace std;
void Juego::InicializarEspacio(char**& _espacio)
{
	srand(time(NULL));
	_espacio = new char* [6];
	int sol = 0;
	int estrella = 0;
	int planeta = 0;
	int randomFila = 0;
	int randomColumna = 0;
	for (int i = 0; i < 6; i++)
	{
		_espacio[i] = new char[6];
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			_espacio[i][j] = ' ';
		}
	}
	_espacio[0][0] = 'H';
	randomFila = 1 + (rand() % 5);
	randomColumna = 1 + (rand() % 5);
	while (sol != 4 && estrella  != 3 && planeta != 3) {
		if (sol != 4)
		{
			if (_espacio[randomFila][randomColumna] != 'E' && _espacio[randomFila][randomColumna] != 'H' && _espacio[randomFila][randomColumna] != 'P' && _espacio[randomFila][randomColumna] != 'M')
			{
				_espacio[randomFila][randomColumna] = 'S';
				sol++;
				randomFila = 1 + (rand() % 5);
				randomColumna = 1 + (rand() % 5);
			}
		}
		if (estrella != 3)
		{
			if (_espacio[randomFila][randomColumna] != 'S' && _espacio[randomFila][randomColumna] != 'H' && _espacio[randomFila][randomColumna] != 'P' && _espacio[randomFila][randomColumna] != 'M')
			{
				_espacio[randomFila][randomColumna] = 'E';
				estrella++;
				randomFila = 1 + (rand() % 5);
				randomColumna = 1 + (rand() % 5);
			}
		}
		if (planeta != 3)
		{
			if (_espacio[randomFila][randomColumna] != 'E' && _espacio[randomFila][randomColumna] != 'H' && _espacio[randomFila][randomColumna] != 'S' && _espacio[randomFila][randomColumna] != 'M')
			{
				_espacio[randomFila][randomColumna] = 'P';
				planeta++;
				randomFila = 1 + (rand() % 5);
				randomColumna = 1 + (rand() % 5);
			}
		}
	}

}

void Juego::MostrarTablero(char**& _espacio)
{
	for (size_t i = 0; i < 6; i++)
	{
		cout << "[";
		for (size_t j = 0; j < 6; j++)
		{
			cout << _espacio[i][j] << " ";
		}
		cout << "]" << endl;
	}
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
Juego::Juego(char** espacioMatriz) :
	espacio(espacioMatriz)
{
}

Juego::~Juego()
{

}