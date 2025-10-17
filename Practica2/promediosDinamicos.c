#include <stdio.h>  
#include <stdlib.h> 


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
            
            liberarMemoria(calificaciones);
            break;

        default:
            printf("\n=== Opcion invalida === \n");
        }
    }
}
 
int ingresarCalificaciones(float **calificaciones, int total) {
    int n;           
    char resp = 's'; 

    while(resp == 's' || resp == 'S'){                      
        printf("\n¿Cuántas calificaciones desea ingresar? ");
        scanf("%d", &n);

        *calificaciones = (float *)realloc(*calificaciones, (total + n) * sizeof(float));

        for(int i = total; i < total + n; i++){
            printf("Ingrese la calificación %d: ", i + 1);
            scanf("%f", &(*calificaciones)[i]); 
        }

        total += n;

        float suma = 0;
        for(int i = 0; i < total; i++){
            suma += (*calificaciones)[i]; 
        }
        float promedio = suma / total;  

        printf("\nPromedio : %.2f\n", promedio);                     
        printf("Estado : %s\n", (promedio >= 6.0) ? "APROBADO" : "REPROBADO"); 

        printf("\n¿Desea agregar más calificaciones ? ( s / n ) ");
        scanf(" %c", &resp); 
    }

    return total; 
}

void liberarMemoria(float *calificaciones){
    free(calificaciones); 
    printf("\n¡Memoria liberada!.\n");
}