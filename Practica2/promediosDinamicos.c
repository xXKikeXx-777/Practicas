#include <stdio.h>
#include <stdlib.h>

// Declaración de funciones
int ingresarCalificaciones(float **calificaciones, int total);
void liberarMemoria(float *calificaciones);

void main(){
    printf("=== Calculadora de Promedio Dinámica ===\n\n");
    int opcion = 0;
    float *calificaciones = NULL;
    int total_calificaciones = 0;

    while(opcion != 2){
        printf("1) Ingresar calificaciones\n");
        printf("2) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%i",&opcion);

        switch(opcion){
        case 1:
            total_calificaciones = ingresarCalificaciones(&calificaciones, total_calificaciones);
            break;

        case 2:
            //se libera la memoria reservada
            liberarMemoria(calificaciones);

            //mensaje de despedida
            // ya está dentro de liberarMemoria
            break;

        default:
            //opcion del usuario invalida
            printf("\n=== Opcion invalida === \nPor favor seleccione una opcion del menu:\n");
        }
    }
}
