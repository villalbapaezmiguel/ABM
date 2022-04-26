/*
 * Arcade.h
 *
 *  Created on: 19 oct. 2021
 *      Author: miguel
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arcade.h"
#include "utn.h"

#define NACIONALIDAD 51;
typedef struct{

	char nacionalidad[63];
	int tipoSonido ;
	int cantidadJuagadores ;
	int capacidadFichas ;
	int idSalon ;
	char nombreJuego[63];
	int id;
	int isEmpty ;

}Arcade;
int inicializarArcade(Arcade* arcade , int len);
int eliminiarArcadeId(Arcade* arcade , int len , int* id);
int modidicarArcade(Arcade* arcade , int len , int id);
int buscarArcadePorId(Arcade* arcade , int len , int id , int* idEncontrado);
int imprimirArcade(Arcade* arcade , int len );
int imprimirJuegoSinRepeti(Arcade* arcade , int len );

#endif /* ARCADE_H_ */
