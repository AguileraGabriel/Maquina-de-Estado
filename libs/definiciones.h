#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#include <stdlib.h>
#include <stdio.h>

#define MAX_CADENA_LONG 40
#define MAX_NOMBRE_VARIABLE_LONG 30

#define ERROR_STATUS -1

//Estados
typedef enum { 
    INICIO = 0,
    CON_AGUA,
    ERROR_SIN_AGUA,
    RIEGO_1,
    RIEGO_2,
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


#endif