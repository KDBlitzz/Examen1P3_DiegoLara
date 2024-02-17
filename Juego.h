#pragma once
class Juego
{
private: // Variables utilizadas
	char** espacio = nullptr;
	int navePosicionX = 0;
	int navePosicionY = 0;
	int cantidadPersonas = 0;
	int cantidadCombustible = 0;
	bool terminado = true;
public:
	Juego(); // metodos utilizados
	~Juego();
	bool isTerminado();
	void setTerminado(bool terminar);
	int getcantidadPersonas();
	void settcantidadPersonas(int cantidadPers);
	int getcantidadCombustible();
	void settcantidadCombustible(int cantidadCombust);
	void InicializarEspacio(char** &_espacio);
	void MostrarTablero(char** &_espacio);
	void MoverNave(int direccion, char** &_espacio);
	void VerificarColision(char**& _espacio);
	void Aterrizar(char** &_espacio);
	void JuegoTerminado();
};

