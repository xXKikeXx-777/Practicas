#include <stdio.h>  
#include <stdlib.h> // Librería para manejo de memoria  (malloc, realloc, free)

// Declaración de funciones antes de main
int ingresarCalificaciones(float **calificaciones, int total); // Función para ingresar calificaciones y calcular promedio
void liberarMemoria(float *calificaciones);                   // Función para liberar la memoria dinámica

void main(){
    printf("=== Calculadora de Promedio Dinámica ===\n\n"); 
    int opcion = 0;                                        
    float *calificaciones = NULL;                          // Puntero dinámico para almacenar calificaciones
    int total_calificaciones = 0;                           

    while(opcion != 2){
        printf("1) Ingresar calificaciones\n");           
        printf("2) Salir\n");                               
        printf("Seleccione una opcion: ");                 
        scanf("%i",&opcion);                               

        switch(opcion){                                    
        case 1:
            // Llamar a la función que permite ingresar calificaciones
            // y actualizar el total de calificaciones
            total_calificaciones = ingresarCalificaciones(&calificaciones, total_calificaciones);
            break;

        case 2:
            // Llamar a la función para liberar memoria antes de salir
            liberarMemoria(calificaciones);
            break;

        default:
            printf("\n=== Opcion invalida === \n");
        }
    }
}

// Función para ingresar calificaciones 
int ingresarCalificaciones(float **calificaciones, int total) {
    int n;           // Número de calificaciones a agregar
    char resp = 's'; // Variable para decidir si agregar más calificaciones

    while(resp == 's' || resp == 'S'){                      
        printf("\n¿Cuántas calificaciones desea ingresar? ");
        scanf("%d", &n);

        // Redimensionar el arreglo dinámico para agregar nuevas calificaciones
        *calificaciones = (float *)realloc(*calificaciones, (total + n) * sizeof(float));

        // Ingresar las nuevas calificaciones
        for(int i = total; i < total + n; i++){
            printf("Ingrese la calificación %d: ", i + 1);
            scanf("%f", &(*calificaciones)[i]); // Permite ingresar números con decimales
        }

        total += n; // Actualizar el total de calificaciones

        // Calcular promedio
        float suma = 0;
        for(int i = 0; i < total; i++){
            suma += (*calificaciones)[i]; // Sumar todas las calificaciones
        }
        float promedio = suma / total;   // Promedio total

        printf("\nPromedio : %.2f\n", promedio);                     
        printf("Estado : %s\n", (promedio >= 6.0) ? "APROBADO" : "REPROBADO"); // Mostrar si aprobó o reprobó

        printf("\n¿Desea agregar más calificaciones ? ( s / n ) ");
        scanf(" %c", &resp); 
    }

    return total; // Devolver el total actualizado de calificaciones
}

// Función para liberar memoria dinámica
void liberarMemoria(float *calificaciones){
    free(calificaciones); // Liberar memoria reservada con malloc/realloc
    printf("\n¡Memoria liberada!.\n");
}