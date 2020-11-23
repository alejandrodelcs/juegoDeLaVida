#include <iostream>
#include <cstring>
#include "consola.h"
#include "interacciones.h"
#include "requerimiento.h"



/*
 * Pre : Recibe un entero
 * Post: Devuelve la posicion correcta del tablero
 */
bool validacionCoordenada(int ingreso) {
	bool continuar = ((ingreso > ANCHO + 1) && (ingreso > LARGO + 1))
			|| (ingreso <= 0);
	if (continuar) {
		std::cout << "¡ERROR! de coordenada." << std::endl;
	}
	return (!continuar);
}


/*
 * pre: ingresar un entero
 * post: devuelve un entero en caso contrario muestra error de ingreso
 */
int esNumero() {
	int numeroValido;
	bool valido = false;

	std::cin >> numeroValido;
	while (!valido) {
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << std::endl;
			std::cout << "¡Error!" << std::endl;
			std::cout << std::endl;
			std::cout << "Ingrese nuevamente: ";
			std::cin >> numeroValido;
		} else {
			valido = true;
		}
	}
	return numeroValido;
}


int ingresoFila() {
	bool valido = false;
	int abscisa;

	while (valido == false) {
		std::cout << "Ingrese fila: ";
		abscisa = esNumero();
		valido = validacionCoordenada(abscisa);
	}
	return abscisa - 1;
}

int ingresoColumna() {
	bool valido = false;
	int ordenada;

	while (valido == false) {
		std::cout << "Ingrese columna: ";
		ordenada = esNumero();
		valido = validacionCoordenada(ordenada);
	}
	return ordenada - 1;
}


bool finalIngreso() {
	char ingreso[2];
	bool devolver;
	std::cin >> ingreso;
	return 	devolver = ((strcmp(ingreso, "si")) == 0);
}

/*
 * Pre : La matriz tiene que estar cargada con los caracteres que represente a una celula muerta
 * Post: Muestra las posiciones en la matriz cargadas por el usuario
 */
void ingresoCoordenada(int tabla[ANCHO][LARGO]) {
	int abscisa, ordenada;
	bool fin = true;
	while (fin) {
		abscisa = ingresoFila();
		ordenada = ingresoColumna();
		tabla[abscisa][ordenada] = VIVA;
		std::cout << "Usted Ingreso " << std::endl;
		mostrarMatriz(tabla);
		std::cout << "---------------------------------" << std::endl;
		std::cout << "¿desear cargar otra coordenada? si/no:  ";
		fin = finalIngreso();
	}
}

/*
 * Pre : el usuario tiene que ingresar un entero
 * Post: devuelve la opcion del menu a realizar en el juego
 */
int ingresoOpcion() {
	int opcion;
	std::cout << "1) Ejecutar un turno" << std::endl << "2) Reiniciar el juego"
			<< std::endl << "3) Terminar el juego" << std::endl;
	std::cout << "Ingrese opcion:  ";
	opcion = esNumero();
	return opcion;
}


/*
 * Pre : recibe dos matrices, una donde se carga coordenadas y otra de interacción con el juego
 * post : llama a la función que valida los alrededores de una celula vida o muerta
 */
void primerResultadoMatriz(int tabla[ANCHO][LARGO], int tablaTurno[ANCHO][LARGO],int contTurno) {

	mostrarMatriz(tabla);
	ingresoCoordenada(tabla);
	std::cout << std::endl;
	validarCelula(tabla, tablaTurno,contTurno);
	std::cout << "ESTADO ACTUAL DEL JUEGO" << std::endl;
	mostrarMatriz(tablaTurno);

}



/* pre : Crea una matriz con ANCHO-LARGO
 * post : Inicializa la matriz con el simbolo referido a una celula e invocar la función primer_resultado_matriz
 */
void reinicioJuego(int contTurno, int tablaTurno[ANCHO][LARGO], int tabla[ANCHO][LARGO]){
	primerResultadoMatriz(tabla, tablaTurno, contTurno);
}

bool primeraOpcionMenu(int tabla[ANCHO][LARGO], int tablaTurno[ANCHO][LARGO],
		int contTurno) {
	bool fin;
	if (contTurno == 1) {
		primerResultadoMatriz(tabla, tablaTurno, contTurno);
		fin = false;
	} else {
		validarCelula(tabla, tablaTurno, contTurno);
		std::cout << "ESTADO ACTUAL DEL JUEGO" << std::endl;
		mostrarMatriz(tablaTurno);
		std::cout << "---------------------------------" << std::endl;
		std::cout << std::endl;
		fin = false;
	}
	return fin;
}



/*
 * Pre  : generar el tablero  con el caracter que represente a celulas muertas
 * Post : el usuario debe ingresar una opcion correcta de modo que lo lleve en el proceso del juego.
 */
void decisionUsuario() {
	int tabla[ANCHO][LARGO], tablaTurno[ANCHO][LARGO];
	bool fin = false;
	int contTurno = 1;
	matrizPrincipal(tabla);
	matrizPrincipal(tablaTurno);
	while (!fin) {
		int opcion = ingresoOpcion();
		if (opcion == TURNO) {
			primeraOpcionMenu(tabla,tablaTurno,contTurno);
			contTurno++;
			fin = false;
		} else if (opcion == REINICIAR) {
			contTurno=1;
			matrizPrincipal(tabla);
			matrizPrincipal(tablaTurno);
			reinicioJuego(contTurno,tablaTurno,tabla);
			std::cout << std::endl;
			contTurno++;
			fin = false;
		} else if (opcion == FIN_JUEGO) {
			std::cout << std::endl;
			std::cout << "FIN DE JUEGO.HASTA LUEGO..." << std::endl;
			std::cout << std::endl;
			fin = true;
		} else {
			std::cout << std::endl;
			std::cout << "¡Error!.Opcion Incorrecta" << std::endl;
			std::cout << std::endl;
		}
	}
}
