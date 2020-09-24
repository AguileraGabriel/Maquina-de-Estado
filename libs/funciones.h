#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "definiciones.h"

//Funciones básicas

void leerSensores(datos_t *);

//Funciones de Estados

estado_t estadoInicio (configs_t *, datos_t *);
estado_t estadoConAgua (configs_t *, datos_t *);
estado_t estadoErrorSinAgua (configs_t *, datos_t *);
estado_t estadoRiego1 (configs_t *, datos_t *);
estado_t estadoRiego2 (configs_t *, datos_t *);

#endif