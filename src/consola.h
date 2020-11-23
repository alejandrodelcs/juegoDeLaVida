#ifndef CONSOLA_H_
#define CONSOLA_H_
#define LARGO 80
#define ANCHO 20

enum estadoCelula {
	MUERTA,
	VIVA
};

void mostrarMatriz(int tabla[ANCHO][LARGO]);
void matrizPrincipal(int tabla[ANCHO][LARGO]);


#endif /* CONSOLA_H_ */
