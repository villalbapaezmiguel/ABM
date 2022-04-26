/*
 * Informes.h
 *
 *  Created on: May 5, 2020
 *      Author: Mauro
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int info_imprimirPantallasContratadasByCuit(Contratacion* arrayContrataciones,int limiteContrataciones,Pantalla* arrayPantallas,int limitePantallas,char* auxiliarCuit);
int info_imprimirContratacionesConImporte(Contratacion* arrayContrataciones,int limiteContrataciones,Pantalla* arrayPantallas,int limitePantallas,char* auxiliarCuit);
int info_imprimirContratacionesConImportePorCliente(Contratacion* arrayContrataciones,int limiteContrataciones,Pantalla* arrayPantallas,int limitePantallas);
int info_calcularDeudaCliente(Contratacion* arrayContrataciones,int limiteContrataciones,Pantalla* arrayPantallas,int limitePantallas,char* auxiliarCuit, float* deuda);
#endif /* INFORMES_H_ */
 