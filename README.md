# Maquina de Estado

## Sistema de Riego

### Memoria Descriptiva

Mi sistema representa un sistema de riego automatizado con valores de humedad, temperatura y horario configurable. Dichos datos serán utilizados para saber en qué momento se podrá regar y en cuales no será posible. Los valores de humedad, temperatura y cantidad de agua regada serán leídos por sensores, pero para este caso, se emulará con los datos que cargue el usuario.

Para comenzar, se cargarán los valores de seteo y luego se comenzará con la medición del horario, si no se encuentra en el horario permitido seguirá esperando hasta que lo sea y en ese momento procederá a revisar si hay agua para poder funcionar, en caso de no haber se enviara un aviso y se volverá a verificar el horario hasta que se solucione el problema. En caso de haber agua, se medirá la temperatura del ambiente y se la comparará con los valores seteados, de esta forma, se ingresará a un estado de medición de humedad en específico (según intensidad de riego), en el cual cada uno posee distintos valores a comparar (h1 y h2), para saber si regar o no. En caso de ser necesario regar se lo hará por 50 mL (v1) o 100 mL (v2) según corresponda en cada estado y se volverá al inicio para verificar todos los parámetros nuevamente.

### Maquina de Estados de Sistema de Riego

![./recursos/Diagrama de estados.jpg](https://github.com/AguileraGabriel/Maquina-de-Estado/blob/master/recursos/Diagrama%20de%20estados.jpg)

### Variables

- __t:__ temperatura leída
- __ts:__ temperatura seteada
- __h:__ humedad leida
- __h1:__ humedad seteada para baja frecuencia de riego
- __h2:__ humedad seteada para alta frecuencia de riego
- __v:__ volumen de agua medido	
- __v1:__ volumen seteado para baja frecuencia de riego
- __v2:__ volumen seteado para alta frecuencia de riego
