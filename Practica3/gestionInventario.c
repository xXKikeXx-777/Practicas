#include <stdio.h>
#include <stdlib.h>

// Punteros dobles globales para el inventario
char **nombresProductos;

int main() {
    int opcion;

    printf("=== SISTEMA DE INVENTARIO ===\n");

    // Llenar inventario con datos de ejemplo (usar la tabla proporcionada)

    // Menú interactivo
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Calcular valor total del inventario\n");
        printf("4. Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
            //agregar producto
            break;
            case 2:
            //muestra todo el inventario
            break;
            case 3:
            //calcula el valor total del inventario
            break;
            case 4:
            printf("Saliendo del sistema...\n");
            break;
            default:
            printf("Opcion invalida.\n");
        }
    } while(opcion != 4);

    // Liberar memoria antes de salir
    liberarInventario();
    return 0;
}

int agregarProducto() {
    // Re-Asignar memoria exacta para el nombre y copiarlo
	// Re-Asignar cantidad y precio en las matrices correspondientes
	// Pedir los datos del producto
}

void mostrarProductos() {
	printf("=== Productos %d ===\n", numProductos);
	// Recorrer todos los productos he imprimirlos
	// Mostrar: Posición, Nombre, Cantidad, Precio, Valor total
}

double calcularValorTotalInventario() {
	double total = 0;
	// Recorrer todos los productos de la categoría
	// Sumar: cantidad * precio para cada producto
	return total;
}

void liberarInventario() {
	// Liberar memoria en orden inverso
	// Primero liberar cada array interno
	// Luego liberar los arrays principales
}
