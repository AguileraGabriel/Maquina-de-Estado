#include "../libs/utilidades.h"
#include <string.h>

/*
    Esta función me permite separar el nombre de la constante y su valor 
*/ 
char * obtenerClave (char* clave){
	char i=0; 
	while (*(clave+i)!=' '){
		i++;
	}
	*(clave+i)=0;
	return clave+i+1;
}


/*
    Esta función me permite extraer los datos del archivo config
*/
void leerConfiguracion(configs_t * configs, const char * nombreArchivoConfig) {
    FILE * archivo;
    char cadena[MAX_CADENA_LONG],*clave,*valor;
    char variables[][MAX_NOMBRE_VARIABLE_LONG]={"SETagua","SEThumedad1","SEThumedad2","SETtemperatura","SEThoraMin","SEThoraMax"};
    int num;

    if ((archivo = fopen (nombreArchivoConfig,"rt")) == NULL){
		printf ("Error en la apertura archivo configuracion : %s \n", nombreArchivoConfig);
	}else{
		fgets(cadena,MAX_CADENA_LONG,archivo);
        
        if (feof(archivo)) {
            return;
        }

		do {
			clave = cadena;
            //printf("clave: {%s}\n", clave);
			if (*clave != '#' && *clave != '\n' && strlen(clave)>0){
				valor = obtenerClave (clave);
                //printf("clave: {%s}\n", clave);
                //printf("valor: {%s}\n", valor);
				for (unsigned int i = 0; i < sizeof(variables)/sizeof(variables[0]); i++){
					if (strcmp(clave,variables[i]) == 0){
                        num = atoi(valor);
						switch(i){
                            case 0:
                                configs->SETagua = num;
                                break;
                            case 1:
                                configs->SEThumedad1 = num;
                                break;
                            case 2:
                                configs->SEThumedad2 = num;
                                break;
                            case 3:
                                configs->SETtemperatura = num;
                                break;
                            case 4:
                                configs->SEThoraMin = num;
                                break;
                            case 5:
                                configs->SEThoraMax = num;
                                break;                                                                                                
						}
					}
				}
			}

			fgets(cadena,MAX_CADENA_LONG,archivo);
        } while(!feof(archivo));
	}
}


//Funciones didacticas

/*
    Esta funcion imprime los datos cargados por el usuario al momento de simular la lectrua de los sensores
*/
void imprimirDatos(datos_t * datos) {
    printf("\n------> DATOS <------\n");
    printf("Agua:            %u\n", datos->agua);
    printf("Humedad:         %u\n", datos->humedad);
    printf("Temperatura:     %u\n", datos->temperatura);
    printf("Hora:            %u\n", datos->hora);
    printf("---------------------\n");
}

/*
    Esta funcion imprime los datos del archivo de configuracion
*/
void imprimirConfig(configs_t * configs) {
    printf("\n------> CONFIG <------\n");
    printf("SETAgua:         %u\n", configs->SETagua);
    printf("SETTemperatura:  %u\n", configs->SETtemperatura);
    printf("SETHumedad1:     %u\n", configs->SEThumedad1);
    printf("SETHumedad2:     %u\n", configs->SEThumedad2);
    printf("SETHoraMin:      %u\n", configs->SEThoraMin);
    printf("SETHoraMax:      %u\n", configs->SEThoraMax);
    printf("----------------------\n");
}
