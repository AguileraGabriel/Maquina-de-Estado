# Maquina de Estado

## Sistema de Riego

### Memoria Descriptiva

Mi sistema representa un sistema de riego automatizado con valores de humedad, temperatura y horario configurable. Dichos datos serán utilizados para saber en qué momento se podrá regar y en cuales no será posible. Los valores de humedad, temperatura y cantidad de agua regada serán leídos por sensores, pero para este caso, se emulará con los datos que cargue el usuario.

Para comenzar, se parte del estado “Inicio”, donde se cargarán los valores seteados en el archivo de configuración y se realizara la medición del agua, para comparar y saber en qué estado debe de arrancar el sistema. Una vez posicionado en “Con Agua”, se realizará las mediciones de temperatura, humedad y hora, de esta forma se sabrá si hay que esperar en dicho estado o avanzar hacia “Riego 1” o “Riego 2” según corresponda. En dichos estados es cuando se realiza el riego y se continúa verificando la humedad del suelo, la hora y si aún hay agua, una vez que termina de regar, si tiene agua volverá al estado “Con Agua”, al igual que si se termina el margen de horario y no se logró la humedad esperada, pero se tiene agua. En caso de quedarse sin agua, independientemente de haber terminado o no, se desplazará al estado “Error Sin Agua” en donde solo se medirá los valores de agua y se enviará un aviso al usuario hasta que no se solucione. Cuando el mismo detecte agua, irá hacia “Con Agua” y comenzará nuevamente.

### Maquina de Estados de Sistema de Riego

![./recursos/Diagrama de estados.jpg](https://github.com/AguileraGabriel/Maquina-de-Estado/blob/master/recursos/Diagrama%20de%20estados.jpg)

### Condiciones

Cada condición __(“C”)__ hace referencia a que debe de pasar para realizar la transición entre los estados.

- __C0:__ el valor del agua es mayor al seteado   
- __C1:__ el valor del agua es menor al seteado
- __C2:__ no estoy en horario para regar o la humedad del suelo es menor a la seteada
- __C3:__ estoy en horario de riego, la humedad es inferior a la seteada y mi temperatura es superior a la establecida, por lo tanto, voy a realizar un riego intenso.
- __C4:__ estoy en horario de riego, la humedad es inferior a la seteada y mi temperatura es inferior a la establecida, por lo tanto, voy a realizar un riego normal.
- __C5 y C9:__ la humedad del suelo supero la seteada, aun tengo agua y finalizo el riego o en su defecto, no estoy en horario de riego, pero sigo con agua.
- __C6 y C8:__ la humedad del suelo es menor a la seteada, sigo en horario de riego y aún tengo agua.
- __C7 y C10:__ sin importar mi nivel de humedad y que este en horario, si me quedo sin agua, procedo al estado de error.
- __C11:__ no tengo agua y no me importan las demás variables.
- __C12:__ tengo agua y salgo del estado de error.


