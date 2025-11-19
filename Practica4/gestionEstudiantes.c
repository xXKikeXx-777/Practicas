#include <stdio.h>

typedef struct {
    char nombre[50];
} Estudiante;

int main(){
    Estudiante grupo[3];
		
	printf("=== SISTEMA DE GESTIÓN ACADÉMICA ===\n");
	
	// Capturar datos de 3 estudiantes
	for(int i = 0; i < 3; i++) {
		printf("\nEstudiante %d:\n", i+1);
		capturarEstudiante(&grupo[i]);
	}
	
	// Mostrar todos los estudiantes
	printf("\n=== LISTA COMPLETA DE ESTUDIANTES ===\n");
	
	
	// Encontrar el mejor promedio
	int mejorIndex = 0;
	
	
	printf("\n=== ESTUDIANTE CON MEJOR PROMEDIO ===\n");
	printf("Nombre: %s\n", grupo[mejorIndex].nombre);
	printf("Promedio: %.2f\n", grupo[mejorIndex].promedio);
	
	return 0;
}

void capturarEstudiante(Estudiante *est) {
}

void calcularPromedio(Estudiante *est) {
	// Calcular: suma de calificaciones / 4
}

void mostrarEstudiante(Estudiante est) {
	printf("\n--- Información del Estudiante ---\n");
	//nombre del estudiante
	//matricula del estudiante
	//calificaciones del estudiante
	//promedio del estudiante
}