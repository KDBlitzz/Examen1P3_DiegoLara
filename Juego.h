#pragma once
class Juego
{
private:
	char** espacio;
	int navePosicionX = 0;
	int navePosicionY = 0;
	int cantidadPersonas = 0;
	int cantidadCombustible = 0;
public:
	Juego();
	~Juego();
	void InicializarEspacio();
	void MostrarTablero();
	void MoverNave(int direccion);
	void VerificarColision();
	void Aterrizar();
	void JuegoTerminado();
};

