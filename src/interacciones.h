#ifndef INTERACCIONES_H_
#define INTERACCIONES_H_
#include <iostream>
#include "consola.h"
#include "interacciones.h"
#include "requerimiento.h"
#include <cstring>

enum OpcionesMenu{
	TURNO = 1,
	REINICIAR,
	FIN_JUEGO
};
bool validacionCoordenada(int ingreso);
int esNumero();
int ingreso_fila();
int ingresoColumna();
bool final_ingreso();
void ingreso_coordenada(int tabla[ANCHO][LARGO]);
int ingreso_opcion();
void primerResultadoMatriz(int tabla[ANCHO][LARGO], int cont_turno);
void reinicioJuego(int contTurno, int tablaTurno[ANCHO][LARGO]);
bool primeraOpcionMenu(int tabla[ANCHO][LARGO], int tablaTurno[ANCHO][LARGO],
		int contTurno);
void decisionUsuario();



#endif /* INTERACCIONES_H_ */
