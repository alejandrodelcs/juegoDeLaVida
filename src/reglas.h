#ifndef REGLAS_H_
#define REGLAS_H_
#include <iostream>
#include <vector>
#include "consola.h"
#include "interacciones.h"
#include "requerimiento.h"

int calcularCelulasVecinas(int tabla[ANCHO][LARGO], int fila, int col);
void validarCelula(int tabla[ANCHO][LARGO], int tablaTurno[ANCHO][LARGO],
		int turnos);


#endif /* REGLAS_H_ */
