#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Estados
typedef enum { 
    INICIO = 0,
    CON_AGUA,
    ERROR_SIN_AGUA,
    RIEGO_1,
    RIEGO_2,
    ERROR_FATAL
} estado_t;

//Datos 
typedef struct{
    unsigned int agua;
    unsigned int humedad;
    unsigned int temperatura;
    unsigned int hora;
} datos_t;

typedef struct{
    unsigned int SETagua;
    unsigned int SEThumedad1;
    unsigned int SEThumedad2;
    unsigned int SETtemperatura;
    unsigned int SEThoraMin;
    unsigned int SEThoraMax;
} configs_t;


//Funciones

char * obtenerClave (char* clave);
void leerSensores(datos_t * datos);


//Funciones de Estados

estado_t estadoInicio (configs_t * configs, datos_t * datos);
estado_t estadoConAgua (configs_t * configs, datos_t * datos);
estado_t estadoErrorSinAgua (configs_t * configs, datos_t * datos);
estado_t estadoRiego1 (configs_t * configs, datos_t * datos);
estado_t estadoRiego2 (configs_t * configs, datos_t * datos);

#endif