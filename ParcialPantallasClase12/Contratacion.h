#ifndef CONTRATACION_H_
#define CONTRATACION_H_

#define CUIT_LEN 20
#define ARCHIVO_LEN 256

typedef struct
{
	char archivo[ARCHIVO_LEN];
	char cuit[CUIT_LEN];
	int isEmpty;
	int id;
	int idPantalla;
	int dias;
}Contratacion;

int cont_imprimir(Contratacion* auxProducto);
int cont_inicializarArray(Contratacion* array,int limite);
int cont_altaArray(Contratacion* array,int limite, int indice, int* idContratacion, int idPantalla);
int cont_getEmptyIndex(Contratacion* array,int limite);
int cont_imprimirArray(Contratacion* array,int limite);
int cont_buscarId(Contratacion array[], int limite, int valorBuscado);
int cont_modificarArray(Contratacion* array,int limite, int indice);
int cont_bajaArray(Contratacion* array,int limite, int indice);
int cont_ordenarPorNombre(Contratacion* array,int limite);

int cont_altaForzadaArray(Contratacion* array,int limite, int indice, int* idContratacion, int idPantalla,char* archivo,char* cuit,int dias);

#endif /* CONTRATACION_H_ */
