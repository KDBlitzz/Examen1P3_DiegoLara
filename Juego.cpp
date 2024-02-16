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
	int marte = 0;
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
	randomFila = (rand() % 5);
	randomColumna = (rand() % 5);
	while (sol != 4)
	{
		if (_espacio[randomFila][randomColumna] != 'H')
		{
			randomFila = (rand() % 5);
			randomColumna = (rand() % 5);
			_espacio[randomFila][randomColumna] = 'S';
			sol++;
		}
	}
	while (estrella != 3)
	{
		randomFila = (rand() % 5);
		randomColumna = (rand() % 5);
		if (_espacio[randomFila][randomColumna] != 'S' && _espacio[randomFila][randomColumna] != 'H')
		{
			_espacio[randomFila][randomColumna] = 'E';
			estrella++;
		}
	}
	while (planeta != 3)
	{
		randomFila = (rand() % 5);
		randomColumna = (rand() % 5);
		if (_espacio[randomFila][randomColumna] != 'E' && _espacio[randomFila][randomColumna] != 'H' && _espacio[randomFila][randomColumna] != 'S')
		{
			_espacio[randomFila][randomColumna] = 'P';
			planeta++;
		}
	}
	while (marte != 1) {
		randomFila = (rand() % 5);
		randomColumna = (rand() % 5);
		if (_espacio[randomFila][randomColumna] != 'E' && _espacio[randomFila][randomColumna] != 'H' && _espacio[randomFila][randomColumna] != 'S' && _espacio[randomFila][randomColumna] != 'P')
		{
			_espacio[randomFila][randomColumna] = 'M';
			marte = 1;
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
void Juego::VerificarColision(char**& _espacio)
{
	if (_espacio[navePosicionX][navePosicionY] == 'P')
	{
		cantidadCombustible += 20;
		cout << "Ha ganado 20 de combustible!" << endl;
		cout << "Tiene " << cantidadCombustible << " de combustible restante" << endl;
	}
	if (_espacio[navePosicionX][navePosicionY] == 'E')
	{
		cantidadPersonas -= 3;
		cout << "Oh no! Han matado a 3 pasajeros!" << endl;
		cout << "Tiene " << cantidadPersonas << " de pasajeros restantes" << endl;
	}
	if (_espacio[navePosicionX][navePosicionY] == 'S')
	{
		cantidadPersonas -= 5;
		cout << "Oh no! Han matado a 3 pasajeros!" << endl;
		cout << "Tiene " << cantidadPersonas << " de pasajeros restantes" << endl;
	}
}
void Juego::MoverNave(int direccion, char**& _espacio)
{
	switch (direccion) {
	case 1:
		cantidadCombustible -= 10;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (_espacio[i][j] == 'H' && i != 0)
				{
					_espacio[i][j] = ' ';
					_espacio[i - 1][j] = 'H';
					navePosicionX = i;
					navePosicionY = j;
					VerificarColision(_espacio);
					break;
				}
				else if (_espacio[i][j] == 'H' && i == 0) {
					cout << "Movimiento invalido" << endl;
					break;
				}
			}
		}
		break;
	case 2:
		cantidadCombustible -= 10;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (_espacio[i][j] == 'H' && i != 5)
				{
					_espacio[i][j] = ' ';
					_espacio[i + 1][j] = 'H';
					navePosicionX = i;
					navePosicionY = j;
					VerificarColision(_espacio);
					break;
				}
				else if (_espacio[i][j] == 'H' && i == 5) {
					cout << "Movimiento invalido" << endl;
					break;
				}
			}
		}
		break;
	case 3:
		cantidadCombustible -= 10;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (_espacio[i][j] == 'H' && j != 5)
				{
					_espacio[i][j] = ' ';
					_espacio[i][j + 1] = 'H';
					navePosicionX = i;
					navePosicionY = j;
					VerificarColision(_espacio);
					break;
				}
				else if (_espacio[i][j] == 'H' && j == 5) {
					cout << "Movimiento invalido" << endl;
					break;
				}
			}
		}
		break;
	case 4:
		cantidadCombustible -= 10;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (_espacio[i][j] == 'H' && j != 0)
				{
					_espacio[i][j] = ' ';
					_espacio[i][j - 1] = 'H';
					navePosicionX = i;
					navePosicionY = j;
					VerificarColision(_espacio);
					break;
				}
				else if (_espacio[i][j] == 'H' && j == 0) {
					cout << "Movimiento invalido" << endl;
					break;
				}
			}
		}
		break;
	}
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
	for (int i = 0; i < 6; i++)
	{
		delete[] espacio[i];
	}
	delete espacio;
}

int Juego::getcantidadPersonas()
{
	return cantidadPersonas;
}

void Juego::settcantidadPersonas(int cantidadPers)
{
	cantidadPersonas = cantidadPers;
}

int Juego::getcantidadCombustible()
{
	return cantidadCombustible;
}

void Juego::settcantidadCombustible(int cantidadCombust)
{
	cantidadCombustible = cantidadCombust;
}
