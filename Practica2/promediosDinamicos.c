#include <stdio.h>
#include <stdlib.h> // Necesario para malloc, realloc y free

void main(){
    printf("=== Calculadora de Promedio Dinámica ===\n\n");
    int opcion = 0;
    float *calificaciones = NULL; // Puntero para almacenar calificaciones dinámicamente
    int total_calificaciones = 0; // Contador del total de calificaciones ingresadas

    while(opcion != 2){
        printf("1) Ingresar calificaciones\n");
        printf("2) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%i",&opcion);

        switch(opcion){
        case 1:

        case 2:
            //se libera la memoria reservada

            //mensaje de despedida
            printf("\nMemoria liberada!!! Hasta luego.\n");
            break;
        default:
            //opcion del usuario invalida
            printf("\n=== Opcion invalida === \nPor favor seleccione una opcion del menu:\n");
        }
    }

}