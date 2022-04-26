/*
 * Cliente.h
 *
 *  Created on: 28 oct. 2021
 *      Author: miguel
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define NOMBRE_LEN 50
#define DIRECCION_LEN 50
#define OCUPADO 0
#define VACIO 1
#define TIPO_LCD 1
#define TIPO_LED 2


typedef struct{

	char nombre[NOMBRE_LEN];
	char direccion[DIRECCION_LEN];
	float precio ;
	int isEmpty ;
	int id;
	int tipo ;
}Pantalla;

#endif /* CLIENTE_H_ */

int inicializar(Pantalla* pantalla , int len);
int buscarLugarLIbre(Pantalla* pantalla , int len , int* lugarLibre);
int pedirDatos(Pantalla* pantalla , int len , int lugarLibre);
int buscarPorId(Pantalla* pantalla , int len , int id , int* idPosicion);
int baja(Pantalla* pantalla , int len , int* idBaja);
int modificar(Pantalla* pantalla , int len , int idModificar , int posicionModificar);
int imprimir(Pantalla* pantalla , int len );
int ordenarPorNombre_o_Precio(Pantalla* pantalla , int len);
int ordenarPorNombre(Pantalla* pantalla , int len);

int pedirDatosForzada(Pantalla* pantalla , int len , int lugarLibre , char* nombre, char* direccion, float precio ,int tipo );


