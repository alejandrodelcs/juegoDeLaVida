#include <iostream>
#include "reglas.h"
#include "consola.h"
#include "requerimiento.h"
#include "interacciones.h"
#include "reglas.h"


/*
 * Pre : fila, columna, cont son enteros positivos.
 * Post : devuelve el estado de la celula 0 si esta muerta, 1 si esta viva.
 */
int estadoTabla(int tabla[ANCHO][LARGO], int fil, int col, int contCel){
	int estado;
	if (tabla[fil][col] == VIVA) {
		if (contCel < 2) {
			estado = MUERTA;
		} else if (contCel > 3) {
			estado = MUERTA;
		} else {
			estado = VIVA;
		}

	} else {
		if (contCel == 3) {
			estado = VIVA;
		} else {
			estado = MUERTA;
		}
	}
	return estado;
}



/*
 * Pre : -
 * Post : valida el metodo modificaciones del structs, si es verdadero el juego esta congelado caso contrario no lo esta.
 */
bool juegoCongelado(int cantCelVivas, int cantCelMuertas, estadoCelulasT fase) {
	return fase.modificaciones = ((cantCelVivas == 0) && (cantCelMuertas == 0));
}


/*
 * Pre : invoca a la funcion juego_congelado
 * Post: valida la variable que devuelve, verdadero o falso.
 */
void resultadoJuegoCongelado(int cantCelVivas, int cantCelMuertas,
		estadoCelulasT fase, int conTurno) {

	bool modificaciones = juegoCongelado(cantCelVivas, cantCelMuertas, fase);

	if ((modificaciones == true) && (conTurno >=2)) {
		std::cout << "Juego Congelado" << std::endl;
	} else {
		std::cout << "Juego NO Congelado" << std::endl;
	}
}


/*
 * Pre : llama a los metodos del struct
 * Post: Muestra al usuario el estado del turno
 */
void mostrarResultados(int contTurno, int cantCelulasVivas,
		int cantCelulasMuertas) {
	estadoCelulasT fase;

	std::cout << "Cantidad de celulas que nacieron: " << cantCelulasVivas
			<< std::endl;
	std::cout << "Cantidad de celulas que murieron: " << cantCelulasMuertas
			<< std::endl;
	std::cout << "Promedio Nacimientos: " << ((float)cantCelulasVivas / (float)contTurno)
			<< std::endl;
	std::cout << "Promedio Muertes: " << ((float)cantCelulasMuertas / (float)contTurno)
			<< std::endl;
	resultadoJuegoCongelado(cantCelulasVivas, cantCelulasMuertas, fase,
			contTurno);
}






