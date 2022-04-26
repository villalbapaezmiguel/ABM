/*
 * unt.h
 *
 *  Created on: 14 sep. 2021
 *      Author: miguel
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
int utn_getNumeroCaracter(char *pResultado, char *mensaje, char *mensajeError,char minimo, char maximo, int reintentos);

int getChar(char *pLetra , char *mensaje , char *mensajeError, char minimo , char maximo , int repeticiones);
float getFloat(float *pNumero , char *mensaje , char *mensajeError, float minimo , float maximo , int repeticiones);
//int getInt(int *pNumero , char *mensaje , char *mensajeError, int minimo , int maximo , int repeticiones);


int get_Int(char mensaje[]);
float get_Float(char mensaje[]);
float get_Char(char mensaje[]);


int esNumericos(char str[]);
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);

int calcularMayor(int numUno , int numDos , int *numeroMayor);
int pedirTexto(char* pResultado ,int leng, char* mensaje , char* mensajeError , int reintentos);

#endif /* UTN_H_ */
