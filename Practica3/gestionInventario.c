#include <stdio.h>
#include <stdlib.h>

// Punteros dobles globales para el inventario
char **nombresProductos = NULL;   // Nombres de los productos
int *cantidades = NULL;           // Cantidades de cada producto
float *precios = NULL;            // Precios de cada producto
int totalP = 0;                   // Total de productos en el inventario

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
    char nombreTemp[100];
    int cantidadTemp;
    float precioTemp;

    printf("\n=== AGREGAR PRODUCTO ===\n");
    printf("Nombre del producto: ");
    scanf(" %[^\n]", nombreTemp); // Leer cadena con espacios
    printf("Cantidad: ");
    scanf("%d", &cantidadTemp);
    printf("Precio: ");
    scanf("%f", &precioTemp);

    int nuevoTotal = totalP + 1;

    // Reasignar memoria para los arreglos globales
    char **tempNombres = realloc(nombresProductos, nuevoTotal * sizeof(char *));
    int *tempCantidades = realloc(cantidades, nuevoTotal * sizeof(int));
    float *tempPrecios = realloc(precios, nuevoTotal * sizeof(float));

    // Verificar que no haya error de memoria
    if (!tempNombres || !tempCantidades || !tempPrecios) {
        printf("Error al asignar memoria.\n");
        free(tempNombres);
        free(tempCantidades);
        free(tempPrecios);
        return 0;
    }

    nombresProductos = tempNombres;
    cantidades = tempCantidades;
    precios = tempPrecios;

    // Asignar memoria exacta para el nombre del nuevo producto
    nombresProductos[totalP] = malloc((strlen(nombreTemp) + 1) * sizeof(char));
    if (!nombresProductos[totalP]) {
        printf("Error al asignar memoria para el nombre.\n");
        return 0;
    }

    strcpy(nombresProductos[totalP], nombreTemp);
    cantidades[totalP] = cantidadTemp;
    precios[totalP] = precioTemp;

    totalP = nuevoTotal;

    printf("Producto agregado correctamente.\n");
    return 1;
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
