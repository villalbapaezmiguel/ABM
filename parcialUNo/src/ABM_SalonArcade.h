/*
 * ABM_SalonArcade.h
 *
 *  Created on: 20 oct. 2021
 *      Author: miguel
 */

#ifndef ABM_SALONARCADE_H_
#define ABM_SALONARCADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Salon.h"
#include "Arcade.h"

int crearNuevoUsuario(Arcade* arcade , int lenArcade , Salones* salon , int lenSalon);
int eliminarSalon(Salones* salones , int lenSalon , Arcade* arcade , int lenArcade, int id );
//falta los informes

#endif /* ABM_SALONARCADE_H_ */
