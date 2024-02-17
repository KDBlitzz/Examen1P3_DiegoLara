#include <iostream>
#include "Juego.h"
#include<ctime>
#include<cstdlib>
using namespace std;
void Juego::InicializarEspacio(char**& _espacio) // metodo para inicializar el espacio en memoria de la matriz y poner los objetos al azar
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
		if (_espacio[randomFila][randomColumna] != _espacio[0][0])
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
		if (_espacio[randomFila][randomColumna] != 'S' && _espacio[randomFila][randomColumna] != _espacio[0][0])
		{
			_espacio[randomFila][randomColumna] = 'E';
			estrella++;
		}
	}
	while (planeta != 3)
	{
		randomFila = (rand() % 5);
		randomColumna = (rand() % 5);
		if (_espacio[randomFila][randomColumna] != 'E' && _espacio[randomFila][randomColumna] != _espacio[0][0] && _espacio[randomFila][randomColumna] != 'S')
		{
			_espacio[randomFila][randomColumna] = 'P';
			planeta++;
		}
	}
	while (marte != 1) {
		randomFila = (rand() % 5);
		randomColumna = (rand() % 5);
		if (_espacio[randomFila][randomColumna] != 'E' && _espacio[randomFila][randomColumna] != _espacio[0][0] && _espacio[randomFila][randomColumna] != 'S' && _espacio[randomFila][randomColumna] != 'P')
		{
			_espacio[randomFila][randomColumna] = 'M';
			marte = 1;
		}
	}
	if (!terminado)
	{
		for (size_t i = 0; i < 6; i++)
		{
			delete[] _espacio[i];
		}
		delete _espacio;
	}
}

void Juego::MostrarTablero(char**& _espacio) // metodo para mostrar tablero
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
void Juego::JuegoTerminado() // Metodo para terminar el juego
{
	if (!terminado)
	{
		cout << "¡Felicidades, ha logrado llegar a Marte con " << cantidadPersonas << " pasajeros!" << endl;
		terminado = false;
	}
	if (cantidadCombustible == 0)
	{
		cout << "Se ha quedado sin combustible y se ha perdido en el espacio con " << cantidadPersonas << " pasajeros" << endl;
		terminado = false;
	}
	if (cantidadPersonas == 0)
	{
		cout << "Todos pasajeros han muerto antes de llegar a marte" << endl;
		terminado = false;
	}
}
void Juego::Aterrizar(char**& _espacio) // metodo para aterrizar el juego
{
	if (_espacio[navePosicionX][navePosicionY] == 'M')
	{
		terminado = false;
		JuegoTerminado();
	}
}
void Juego::VerificarColision(char**& _espacio) // metodo para verificiar colision
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
		if (cantidadPersonas <= 0)
		{
			cantidadPersonas = 0;
			cout << "Tiene " << cantidadPersonas << " de pasajeros restantes" << endl;
		}
		else {
			cout << "Tiene " << cantidadPersonas << " de pasajeros restantes" << endl;
		}
	}
	if (_espacio[navePosicionX][navePosicionY] == 'S')
	{
		cantidadPersonas -= 5;
		cout << "Oh no! Han matado a 3 pasajeros!" << endl;
		if (cantidadPersonas <= 0)
		{
			cantidadPersonas = 0;
			cout << "Tiene " << cantidadPersonas << " de pasajeros restantes" << endl;
		}
		else {
			cout << "Tiene " << cantidadPersonas << " de pasajeros restantes" << endl;
		}
	}
}
void Juego::MoverNave(int direccion, char**& _espacio) // Metodo para poder mover la nave
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
					navePosicionX = i - 1;
					navePosicionY = j;
					VerificarColision(_espacio);
					JuegoTerminado();
					Aterrizar(_espacio);
					_espacio[i][j] = ' ';
					_espacio[i - 1][j] = 'H';
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
		if (_espacio[navePosicionX][navePosicionY] == 'H' && navePosicionX != 5)
		{
			navePosicionX = navePosicionX + 1;
			navePosicionY = navePosicionY;
			VerificarColision(_espacio);
			JuegoTerminado();
			Aterrizar(_espacio);
			_espacio[navePosicionX - 1][navePosicionY] = ' ';
			_espacio[navePosicionX][navePosicionY] = 'H';
			break;
		}
		else if (_espacio[navePosicionX][navePosicionY] == 'H' && navePosicionX == 0) {
			cout << "Movimiento invalido" << endl;
			break;
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
					navePosicionX = i;
					navePosicionY = j + 1;
					VerificarColision(_espacio);
					JuegoTerminado();
					Aterrizar(_espacio);
					_espacio[i][j] = ' ';
					_espacio[i][j + 1] = 'H';
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
					navePosicionX = i;
					navePosicionY = j - 1;
					VerificarColision(_espacio);
					JuegoTerminado();
					Aterrizar(_espacio);
					_espacio[i][j] = ' ';
					_espacio[i][j - 1] = 'H';
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


Juego::Juego()
{
}


bool Juego::isTerminado()
{
	return terminado;
}

void Juego::setTerminado(bool terminar)
{
	terminado = terminar;
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
Juego::~Juego()
{
	for (int i = 0; i < 6; i++)
	{
		delete[] espacio[i];
	}
	delete espacio;
}