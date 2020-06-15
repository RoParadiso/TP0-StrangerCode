#include "demogorgon.h"

#define MSJ_ENFRENTAMIENTO "\n\nEl enfrentamiento esta por comenzar\n"

#define MSJ_MAL_INGRESO "Ingreso no valido\n"
#define MSJ_ANIMO "Ingrese el animo de El(Eleven) en un rango del 1 al 100 inclusive\n"

const int DEF_ANIMO = 0;
const int MIN_ANIMO = 1;
const int MAX_ANIMO = 100;

const bool ANIMO_VERIFICADO = true;
const bool ANIMO_NO_VERIFICADO = false;

#define MSJ_CONFIANZA "Ingrese el nivel de confianza que tiene El(Eleven) con sus amigos\nBajo [b] - Medio [m] - Alto [a]\n"

const char DEF_NIVEL_CONFIANZA = 'z';
#define CONFIANZA_BAJA 'b'
#define CONFIANZA_MEDIA 'm'
#define CONFIANZA_ALTA 'a'

const bool NIVEL_CONFIANZA_VERF = true;
const bool NIVEL_CONFIANZA_NO_VERF = false;

const float DEF_FUERZA_PSQUICA = -0.1F;
const float MULTIP_CONF_BAJO = 0.7F;
const float MULTIP_CONF_MEDIO = 1.3F;
const float MULTIP_CONF_ALTO = 3.7F;

const char DEF_RESULTADO = 'w';
#define GANO 'g'
#define GANO_JUSTO 'h'
#define RESULT_DESCONOCIDO 'd'
const float MIN_GANO = 67.0F;
const float MAX_GANO = 370.0F;
const float VALOR_GANO_JUSTO = 65.0F;

#define MSJ_ERROR_CALCULAR_FUERZA "Algo malio sal"


#define MSJ_GANO "\n\n\n\n\tEleven conto con su mayor animo y con la confianza de sus amigos\n\tpor lo que logro vencer al Demogorgon con su fuerza psquica!!!\n\n\n\t \n"

#define MSJ_GANO_JUSTO "\n\n\n\n\tEleven conto con la fuerza psiquica justa para poder vencer al Demogorgon\n\tpor lo que quedo realmente debil luego del enfrentamiento!\n\n\n"

#define MSJ_RESULT_DESC "\n\n\n\n\tEleven enfrento al Demogorgon pero no parecia que lo pudiera vencer\n\thasta que una luz cubrio todo el lugar desapareciendo al Demogorgon junto a Eleven\n\n\tFin.. ?\n\n"



void comenzar_enfrentamiento(){
		printf(MSJ_ENFRENTAMIENTO);
}

int recibir_animo(){
	int nivel_animo = DEF_ANIMO;
	printf(MSJ_ANIMO);
	scanf("%i", &nivel_animo);
	if((nivel_animo < MIN_ANIMO) && (nivel_animo > MAX_ANIMO)){
		printf(MSJ_MAL_INGRESO);
		printf(MSJ_ANIMO);
		scanf("%i", &nivel_animo);
	}
	return nivel_animo;
}

char recibir_confianza(){
	char nivel_confianza = DEF_NIVEL_CONFIANZA;
	printf(MSJ_CONFIANZA);
	scanf(" %c", &nivel_confianza);
	if((nivel_confianza != CONFIANZA_BAJA) || (nivel_confianza != CONFIANZA_MEDIA) || (nivel_confianza != CONFIANZA_ALTA)){
		printf(MSJ_CONFIANZA);
		scanf(" %c", &nivel_confianza);
	}
	return nivel_confianza;
}


float recibir_fuerza_psiquica(int nivel_animo, char nivel_confianza){
	float fuerza_psiquica = DEF_FUERZA_PSQUICA;
	if((nivel_confianza = CONFIANZA_BAJA)){
		fuerza_psiquica = (nivel_animo * MULTIP_CONF_BAJO);
	}else if((nivel_confianza = CONFIANZA_MEDIA)){
		fuerza_psiquica = (nivel_animo * MULTIP_CONF_MEDIO);
	}else if((nivel_confianza = CONFIANZA_ALTA)){
		fuerza_psiquica = (nivel_animo * MULTIP_CONF_ALTO);
	}

	return fuerza_psiquica;
}


void resultado_enfrentamiento(float fuerza_psiquica){
	if (fuerza_psiquica < VALOR_GANO_JUSTO){
		printf(MSJ_RESULT_DESC);
	}else if((fuerza_psiquica >= VALOR_GANO_JUSTO) && (fuerza_psiquica < MIN_GANO)){
		printf(MSJ_GANO_JUSTO);
	}else if((fuerza_psiquica >= MIN_GANO) && (fuerza_psiquica <= MAX_GANO)){
		printf(MSJ_GANO);
	}
}
