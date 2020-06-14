#include <stdio.h>
#include "demogorgon.h"

const int DEF_ANIMO_JUGADOR = 0;
const char DEF_NIVEL_CONFIANZA_JUGADOR = 'w';
const float DEF_FUERZA_PSIQUICA = -1.0F;


int main(){

	int animo = DEF_ANIMO_JUGADOR;
	char confianza = DEF_NIVEL_CONFIANZA_JUGADOR;
	float fuerza_psiquica = DEF_FUERZA_PSIQUICA;


	comenzar_enfrentamiento();
	animo = recibir_animo();
	printf("Animo: %i\n", &animo);

	confianza = recibir_confianza();
	printf("Confianza:  %c\n", &confianza);

	fuerza_psiquica = recibir_fuerza_psiquica();
	printf("fuerza_psiquica = %f\n", &fuerza_psiquica);

	resultado_enfrentamiento();
	
	return 0;
}