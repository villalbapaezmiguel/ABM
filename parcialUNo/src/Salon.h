/*
 * Salon.h
 *
 *  Created on: 19 oct. 2021
 *      Author: miguel
 */

#ifndef SALON_H_
#define SALON_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Salon.h"
#include "utn.h"


typedef struct{

	char nombre [51];
	char direccion [51];
	int tipo ;
	int id ;
	int flagEmpty ;
}Salones;

int inicializarSalon(Salones* salon , int len);
int cargaDeSalon(Salones* salon, int len);
int imprimirSalon(Salones* salon , int len );
int borrarPorId(Salones* salon , int len , int salonId);
int buscarPorId(Salones* salon , int len , int salonId , int* posicionId);


#endif /* SALON_H_ */
