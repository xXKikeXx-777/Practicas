#include <stdio.h>

typedef struct {
    char nombre[50];
    int matricula;
    double calificaciones[4];
    double promedio;
} Estudiante;

// Prototipos de funciones
void capturarEstudiante(Estudiante *est);
void calcularPromedio(Estudiante *est);
void mostrarEstudiante(Estudiante est);

int main() {
    Estudiante grupo[4]; // Arreglo de 4 estudiantes

    printf("=== SISTEMA DE GESTIÓN ACADÉMICA ===\n");

    // Capturar datos de 4 estudiantes
    for(int i = 0; i < 4; i++) {
        printf("\nEstudiante %d:\n", i + 1);
        capturarEstudiante(&grupo[i]);
    }

    // Mostrar todos los estudiantes
    printf("\n=== LISTA COMPLETA DE ESTUDIANTES ===\n");
    for(int i = 0; i < 4; i++) {
        mostrarEstudiante(grupo[i]);
    }

    // Encontrar al estudiante con mejor promedio
    int mejorIndex = 0;
    for(int i = 1; i < 4; i++) {
        if(grupo[i].promedio > grupo[mejorIndex].promedio) {
            mejorIndex = i;
        }
    }

    printf("\n=== ESTUDIANTE CON MEJOR PROMEDIO ===\n");
    printf("Nombre: %s\n", grupo[mejorIndex].nombre);
    printf("Promedio: %.2f\n", grupo[mejorIndex].promedio);

    return 0;
}

// Función para capturar los datos de un estudiante
void capturarEstudiante(Estudiante *est) {
    printf("Ingrese nombre: ");
    scanf("%s", est->nombre);

    printf("Ingrese matrícula: ");
    scanf("%d", &est->matricula);

    printf("Ingrese 4 calificaciones:\n");
    for(int i = 0; i < 4; i++) {
        printf("Calificación %d: ", i + 1);
        scanf("%lf", &est->calificaciones[i]);
    }

    calcularPromedio(est);
}

// Función para calcular el promedio del estudiante
void calcularPromedio(Estudiante *est) {
    double suma = 0;
    for(int i = 0; i < 4; i++) {
        suma += est->calificaciones[i];
    }
    est->promedio = suma / 4.0;
}

// Función para mostrar los datos de un estudiante
void mostrarEstudiante(Estudiante est) {
    printf("\n--- Información del Estudiante ---\n");
    printf("Nombre: %s\n", est.nombre);
    printf("Matrícula: %d\n", est.matricula);
    printf("Calificaciones: ");
    for(int i = 0; i < 4; i++) {
        printf("%.2lf ", est.calificaciones[i]);
    }
    printf("\nPromedio: %.2lf\n", est.promedio);
}