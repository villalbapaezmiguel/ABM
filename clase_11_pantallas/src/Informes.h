/*
 * Informes.h
 *
 *  Created on: 5 nov. 2021
 *      Author: miguel
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "string.h"
#include "Contratacion.h"
#include "Pantalla.h"


int imprimir_contratacionCuit(Contratacion* contratacion , int len , char* cuit);
int imprimir_Contratacion_Informe(Contratacion* contratacion , int lenContratacion , Pantalla* pantalla , int lenPantalla , char* auxiliar);
int listaImporte_A_Pagar_Informe(Contratacion* contratacion, int lenContratacion, Pantalla* pantalla , int lenPantalla , float* precioFinalPorDias , char* auxCuit);


int listar_Contratacion_Informe(Contratacion* contratacion , int lenContratacion , Pantalla* pantalla , int lenPantalla , char* auxiliar);
int listaDeCadaCliente (Contratacion* contratacion , int lenContratacion );

int info_ImprimirContratacionesImportePorCliente(Contratacion* contratacion , int lenContratacion , Pantalla* pantalla , int lenPantalla );
int info_calcularDeudaCliente(Contratacion* contratacion , int lenContratacion , Pantalla* pantalla , int lenPantalla , char* auxiliar , float* deuda);

#endif /* INFORMES_H_ */
