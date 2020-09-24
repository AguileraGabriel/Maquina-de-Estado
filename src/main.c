#include "../libs/definiciones.h"
#include "../libs/utilidades.h"
#include "../libs/funciones.h"

int main(void){
    configs_t configs;
    datos_t datos;
    estado_t estado = INICIO;

    static const char direccionArchivoConfig[] = "../cfg/config.conf";

    printf("\n***Sistema de Riego Automatizado con Maquinas de Estados***\n");

    estado_t (*estados[])(configs_t *, datos_t *) = {estadoInicio,estadoConAgua,estadoErrorSinAgua,estadoRiego1,estadoRiego2};

    printf("Leyendo configuracion ...\n");

    leerConfiguracion(&configs, direccionArchivoConfig); 
    imprimirConfig(&configs);
    leerSensores(&datos);

    while(1) {
        imprimirDatos(&datos);
        estado = estados[estado](&configs,&datos);
    }

    return 0;
}