#pragma once
class Juego
{
private:
	char** espacio = nullptr;
	int navePosicionX = 0;
	int navePosicionY = 0;
	int cantidadPersonas = 0;
	int cantidadCombustible = 0;
public:
	Juego(char** espacioMatriz);
	~Juego();
	void InicializarEspacio(char** &_espacio);
	void MostrarTablero(char** &_espacio);
	void MoverNave(int direccion);
	void VerificarColision();
	void Aterrizar();
	void JuegoTerminado();
};

