#include"../libs/mylib.h"
#include"funciones.c"

int main(void){
    configs_t configs;
    datos_t datos;
    estado_t estado = INICIO;

    static const char nombreArchivoConfig[] = "config.conf";

    printf("\n***Sistema de Riego Automatizado con Maquinas de Estados***\n");

    estado_t (*estados[])(configs_t *, datos_t *) = {estadoInicio,estadoConAgua,estadoErrorSinAgua,estadoRiego1,estadoRiego2};

    printf("Leyendo configuracion ...\n");

    while(1) {
        estado = estados[estado](&configs,&datos);
    }

    return 0;
}