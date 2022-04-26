/*
 ============================================================================
 Name        : clase_11_pantallas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "string.h"
#include "Pantalla.h"
#include "Menu.h"

#define PANTALLA_LEN 100
#define CONTRATACION_LEN 1000
int main(void) {

	Pantalla pantallas[PANTALLA_LEN];
	Contratacion contratacion [CONTRATACION_LEN];

	menu(pantallas, PANTALLA_LEN , contratacion , CONTRATACION_LEN);

	return EXIT_SUCCESS;
}
