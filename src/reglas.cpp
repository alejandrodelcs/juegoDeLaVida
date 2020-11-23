#include <iostream>
#include <vector>
#include "interacciones.h"
#include "consola.h"
#include "reglas.h"
#include "requerimiento.h"



/*
 * pre: Recibe una matriz con coordenadas ingresadas
 * post: devuelve la cantidad de celulas que existe en el entorno de la posición
 */
int calcularCelulasVecinas(int tabla[ANCHO][LARGO], int fila, int col) {
	int vecinos = 0;
	for (int i = fila - 1; i < fila + 2; i++) {
		for (int j = col - 1; j < col + 2; j++) {
			if (i != fila || j != col) {
				if (!(i < 0 || i >= ANCHO || j < 0 || j >= LARGO)) {
					vecinos = vecinos + tabla[i][j];
				}
			}
		}
	}
	return vecinos;
}


/*
 * pre: recibe una matriz con datos actualizados del juego
 * Post: copia de una matriz a otra , actualizando valores
 */
void duplicar(int tabla[ANCHO][LARGO], int tablaTurno[ANCHO][LARGO]) {
	for (int i = 0; i < ANCHO; i++) {
		for (int j = 0; j < LARGO; j++) {
			tabla[i][j] = tablaTurno[i][j];
		}
	}
}


void validarCelula(int tabla[ANCHO][LARGO], int tablaTurno[ANCHO][LARGO],
		int turnos) {
	int cantCelulas = 0;
	estadoCelulasT fase;
	fase.cantCelVivas = 0;
	fase.cantCelMuertas = 0;
	for (int i = 0; i < ANCHO; i++) {
		for (int j = 0; j < LARGO; j++) {
			cantCelulas = calcularCelulasVecinas(tabla, i, j);
			tablaTurno[i][j] = estadoTabla(tabla, i, j, cantCelulas);
			if (cantCelulas != 0) {
				if ((cantCelulas < 2) && (tabla[i][j] == VIVA)) {
					fase.cantCelMuertas++;
				} else if ((cantCelulas > 3) && (tabla[i][j] == VIVA)) {
					fase.cantCelMuertas++;
				} else if ((cantCelulas == 3) && (tabla[i][j] == MUERTA)) {
					fase.cantCelVivas++;
				}
			}
		}
	}
	std::cout << ".............................................." << std::endl;
	mostrarResultados(turnos, fase.cantCelVivas, fase.cantCelMuertas);
	std::cout << ".............................................." << std::endl;
	duplicar(tabla, tablaTurno);
}


