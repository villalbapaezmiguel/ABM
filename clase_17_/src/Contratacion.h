/*
 * Cliente.h
 *
 *  Created on: 28 oct. 2021
 *      Author: miguel
 */

#ifndef CONTRATACION_H_
#define CONTRATACION_H_
#define NOMBRE_LEN 50
#define CUIT_LEN 50
#define OCUPADO 0
#define VACIO 1
#include "Pantalla.h"

typedef struct{

	char archivo[NOMBRE_LEN];
	char cuit[CUIT_LEN];
	int isEmpty ;
	int id;
	int idPantallas;
	int dias ;
}Contratacion;

#endif /* CLIENTE_H_ */

int inicializar_contratacion(Contratacion* contratacion , int len);
int buscarLugarLIbre_contratacion(Contratacion* clientes , int len , int* lugarLibre);
int pedirDatos_contratacion(Contratacion* clientes , int len , int lugarLibre , int idPantalla);
int buscarPorId_contratacion(Contratacion* clientes , int len , int id , int* idPosicion );
int baja_contratacion(Contratacion* clientes , int len , int* idBaja);
int modificar_contratacion(Contratacion* clientes , int len , int idModificar , int posicionModificar , Pantalla* pantalla , int lenPantalla);
int imprimir_contratacion(Contratacion* clientes , int len );
int ordenarPorNombre_o_Dias_contratacion(Contratacion* clientes , int len);
int ordenarPorNombre_contratacion(Contratacion* clientes , int len);

int pedirDatos_contratacionForzada(Contratacion* contratacion , int len , int lugarLibre ,int* idPantallaContratacion,int idPantalla ,char* archivo,char* cuit, int dias);

//memoria dinamica
Contratacion* cli_new(void);
int cli_inicializarArrayPunteros(Contratacion* punterosContratacion[] , int lenContratacion);
int cli_getEmptyIndexConArrayPunteros(Contratacion* clientes [], int len , int* lugarLibre);
