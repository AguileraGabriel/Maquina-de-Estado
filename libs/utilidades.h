#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "definiciones.h"

//Funciones

char * obtenerClave (char*);
void leerConfiguracion(configs_t *, const char *);

void presentacion();

void imprimirEstado(estado_t *);
void imprimirDatos(datos_t *);
void imprimirConfig(configs_t *);

#endif