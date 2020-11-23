#ifndef REQUERIMIENTO_H_
#define REQUERIMIENTO_H_
#include <iostream>
#include "reglas.h"
#include "consola.h"
#include "requerimiento.h"
#include "interacciones.h"
#include "reglas.h"

typedef struct EstadoCelulas
{
	int cantCelVivas;
	int cantCelMuertas;
	bool modificaciones;
} estadoCelulasT;



int estadoTabla(int tabla[ANCHO][LARGO], int fil, int col, int contCel);
bool juegoCongelado(int cantCelVivas, int cantCelMuertas, estadoCelulasT fase);
void resultadoJuegoCongelado(int cantCelVivas, int cantCelMuertas, estadoCelulasT fase);
void mostrarResultados(int contTurno, int cantCelVivas, int cantCelMuertas);



#endif /* REQUERIMIENTO_H_ */
