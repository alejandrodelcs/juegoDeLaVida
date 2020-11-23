#include <iostream>
#include "consola.h"
#define LARGO 80
#define ANCHO 20

/*
 * Pre: recibe una matriz de un tamaño especifico
 * Post: Muestra el estado actual de la matriz.
 */
void mostrarMatriz(int tabla[ANCHO][LARGO]) {
	for (int i = 0; i < ANCHO; i++) {
		for (int j = 0; j < LARGO; j++) {
			std::cout << "┼" << tabla[i][j];
		}
		std::cout << std::endl;
	}
}


/*
 * Pre : recibe una matriz de un tamaño especifico
 * Post: carga a las posiciones elegidas por el usuario
 */
void matrizPrincipal(int tabla[ANCHO][LARGO]) {
	for (int i = 0; i < ANCHO; i++) {
		for (int j = 0; j < LARGO; j++) {
			tabla[i][j] = MUERTA;
		}
	}
}
