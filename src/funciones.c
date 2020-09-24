#include "../libs/funciones.h"
#include "../libs/definiciones.h"

/*
Esta función carga los valores de los sensores de agua, temperatura, humedad y hora.
*/
void leerSensores(datos_t * datos){
    int count = 0;

    printf("\nLectura de Sensores:\n");

    do {
        printf("Ingrese valor de Agua: ");
        count = scanf("%u", &(datos->agua));
        fflush(stdin);
    } while (count < 0);

    do {
        printf("Ingrese valor de Humedad: ");
        count = scanf("%u", &(datos->humedad));
        fflush(stdin);
    } while (count < 0);

    do {
        printf("Ingrese valor de Temperatura: ");
        count = scanf("%u", &(datos->temperatura));
        fflush(stdin);
    } while (count < 0);

    do {
        printf("Ingrese valor de Hora: ");
        count = scanf("%u", &(datos->hora));
        fflush(stdin);
    } while (count < 0);
    printf("\n");

}


//Funciones de Estados

/*
Funcion del estado Inicio, carga de datos del confing y primer lectura de sensores. 
*/
estado_t estadoInicio (configs_t * configs, datos_t * datos){
    printf("\n--> Ejecutando estado inicial <--\n\n");
    if(datos->agua >= configs->SETagua){
        return CON_AGUA; //C0
    }
    if(datos->agua < configs->SETagua){
        return ERROR_SIN_AGUA; //C1
    }
    exit(ERROR_STATUS);
}

/*
Funcion del estado Con Agua, lectura de sensores y determinacion de hacia que estado ir. 
*/
estado_t estadoConAgua (configs_t * configs, datos_t * datos){
    printf("\n--> Ejecutando estado con agua <--\n");
    leerSensores(datos);
    
    if((datos->agua >= configs->SETagua) && ((datos->hora < configs->SEThoraMin) || (datos->hora > configs->SEThoraMax))){
        return CON_AGUA; //C2
    }
    if((datos->agua >= configs->SETagua) && (datos->humedad <= configs->SEThumedad1) && (datos->temperatura < configs->SETtemperatura) && ((configs->SEThoraMin <= datos->hora) && (datos->hora <= configs->SEThoraMax))){
        return RIEGO_1; //C4
    }
    if((datos->agua >= configs->SETagua) && (datos->humedad <= configs->SEThumedad2) && (datos->temperatura >= configs->SETtemperatura) && ((configs->SEThoraMin <= datos->hora) && (datos->hora <= configs->SEThoraMax))){
        return RIEGO_2; //C3
    }
    exit(ERROR_STATUS);
}

/*
Funcion del estado Error Sin Agua, lectura de sensores e impresion de aviso. Espero hasta verificar valores y poder volver a con agua. 
*/
estado_t estadoErrorSinAgua (configs_t * configs, datos_t * datos){
    printf("\n--> Ejecutando estado de error sin agua <--\n");
    printf("--> No hay agua, verificar reservorio <--\n");
    leerSensores(datos);
    if((datos->agua < configs->SETagua)){ //C11
        return ERROR_SIN_AGUA;
    }
    if((datos->agua >= configs->SETagua)){ //C12
        return CON_AGUA;
    }
    exit(ERROR_STATUS);
}

/*
Funcion del estado Riego 1, lectura de sensores y envio de señal de riego. 
*/
estado_t estadoRiego1 (configs_t * configs, datos_t * datos){
    printf("\n--> Ejecutando estado de riego 1 <--\n");
    printf("--> Regando <--\n");
    leerSensores(datos);
    if((datos->agua >= configs->SETagua) && (datos->humedad <= configs->SEThumedad1) && (datos->temperatura < configs->SETtemperatura) && (datos->hora >= configs->SEThoraMin) && (datos->hora <= configs->SEThoraMax)){
        return RIEGO_1; //C6
    }
    if((datos->agua < configs->SETagua)){
        return ERROR_SIN_AGUA; //C7
    }
    if((datos->agua >= configs->SETagua) && ((datos->humedad > configs->SEThumedad1) || ((datos->hora < configs->SEThoraMin) || (datos->hora > configs->SEThoraMax)))){
        return CON_AGUA; //C5
    }
    exit(ERROR_STATUS);
}

/*
Funcion del estado Riego 2, lectura de sensores y envio de señal de riego. 
*/
estado_t estadoRiego2 (configs_t * configs, datos_t * datos){
    printf("\n--> Ejecutando estado de riego 2 <--\n");
    printf("--> Regando <--\n");
    leerSensores(datos);
    if((datos->agua >= configs->SETagua) && (datos->humedad <= configs->SEThumedad2) && (datos->temperatura >= configs->SETtemperatura) && ((datos->hora >= configs->SEThoraMin) && (datos->hora <= configs->SEThoraMax))){
        return RIEGO_2; //C8
    }
    if((datos->agua < configs->SETagua)){
        return ERROR_SIN_AGUA; //C10
    }
    if((datos->agua >= configs->SETagua) && ((datos->humedad > configs->SEThumedad2) || ((datos->hora < configs->SEThoraMin) || (datos->hora > configs->SEThoraMax)))){
        return CON_AGUA; //C9
    }
    exit(ERROR_STATUS);
}