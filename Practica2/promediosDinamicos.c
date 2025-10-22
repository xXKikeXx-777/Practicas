#include <stdio.h>
#include <stdlib.h>

void main(){
    printf("=== Calculadora de Promedio Dinámica ===\n\n");
    int opcion = 0;

    float *calificaciones = NULL;        // Puntero para guardar calificaciones en memoria dinámica
    int total_calificaciones = 0;        // Contador total de calificaciones
    float suma = 0.0;                    // Acumula las calificaciones para calcular el promedio

    while(opcion != 2){                  // Menú principal, se repite hasta elegir salir
        printf("1) Ingresar calificaciones\n");
        printf("2) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%i", &opcion);

        switch(opcion){
        case 1:{
            int n = 0;
            printf("\n¿Cuántas calificaciones desea ingresar? ");
            scanf("%d", &n);

            if(n <= 0){                  // Valida número positivo
                printf("Número no válido. Intente nuevamente.\n");
                break;
            }

            // Asigna o amplía memoria con realloc según sea necesario
            float *nuevo_bloque = realloc(calificaciones, (total_calificaciones + n) * sizeof(float));
            if(nuevo_bloque == NULL){    // Verifica que la memoria se haya asignado correctamente
                printf("Error: no se pudo asignar memoria.\n");
                free(calificaciones);     // Libera si hubo error
                return;                   // Termina el programa
            }
            calificaciones = nuevo_bloque; // Actualiza el puntero a la nueva memoria

            // Captura las nuevas calificaciones
            for(int i = 0; i < n; i++){
                float valor = 0.0;
                int valido = 0;
                while(!valido){           // Ciclo para asegurar que la calificación esté entre 0 y 10
                    printf("Ingrese la calificación %d: ", total_calificaciones + i + 1);
                    scanf("%f", &valor);
                    if(valor >= 0 && valor <= 10){
                        *(calificaciones + total_calificaciones + i) = valor; // Guarda usando aritmética de punteros
                        valido = 1;
                    } else {
                        printf("Valor no válido. Ingrese una calificación entre 0 y 10.\n");
                    }
                }
            }

            total_calificaciones += n;    // Actualiza el total de calificaciones

            // Calcula el promedio
            suma = 0.0;
            for(int i = 0; i < total_calificaciones; i++)
                suma += *(calificaciones + i); // Suma todas las calificaciones

            float promedio = suma / total_calificaciones;
            printf("\nPromedio: %.2f\n", promedio);

            // Muestra si aprobó o reprobó
            if(promedio >= 7.0)
                printf("Estado: APROBADO\n");
            else
                printf("Estado: REPROBADO\n");

            // Pregunta si quiere agregar más calificaciones
            char respuesta;
            printf("\n¿Desea agregar más calificaciones? (s/n): ");
            scanf(" %c", &respuesta);

            while(respuesta != 's' && respuesta != 'n'){  // Valida respuesta
                printf("Respuesta no válida. Ingrese 's' o 'n': ");
                scanf(" %c", &respuesta);
            }

            if(respuesta == 'n'){          // Si elige 'n', regresa al menú principal
                printf("\nRegresando al menú principal...\n\n");
                break;
            }

            // Si responde 's', repite el ciclo principal automáticamente
            break;
        }

        case 2:
            free(calificaciones);           // Libera la memoria dinámica al salir
            calificaciones = NULL;          // Evita puntero colgante
            printf("\nMemoria liberada!!! Hasta luego.\n");  // Mensaje final
            break;

        default:
            printf("\n=== Opcion invalida === \nPor favor seleccione una opcion del menu:\n");
        }
    }
}