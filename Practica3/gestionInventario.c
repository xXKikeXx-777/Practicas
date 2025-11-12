#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Punteros dobles globales para el inventario
char **nombresProductos = NULL;   // Guarda los nombres de los productos
int *cantidades = NULL;           // Guarda las cantidades
float *precios = NULL;            // Guarda los precios
int totalP = 0;                   // Número total de productos

// Prototipos de funciones
int agregarProducto();             // Agrega un nuevo producto
void mostrarProductos();           // Muestra el inventario
double calcularValorTotalInventario(); // Calcula el valor total
void liberarInventario();          // Libera la memoria usada
void llenarInventarioInicial();    // Llena el inventario base
void buscarProductoPorNombre(); // buscar el producto por nobre

int main() {
    int opcion;

    printf("=== SISTEMA DE INVENTARIO ===\n");

    llenarInventarioInicial(); // Carga productos iniciales

    // Menú interactivo
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Calcular valor total del inventario\n");
        printf("4. Buscar producto\n");
        printf("5. Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                agregarProducto(); // Llama para agregar un producto
                break;
            case 2:
                mostrarProductos(); // Llama para mostrar inventario
                break;
            case 3:
                // Muestra el valor total del inventario
                printf("Valor total del inventario: $%.2f\n", calcularValorTotalInventario());
                break;
            case 4:
                buscarProductoPorNombre();
                break;
            case 5:
                printf("Saliendo del sistema...\n"); // Sale del programa
            default:
                printf("Opcion invalida.\n"); // Error si elige mal
        }
    } while(opcion != 4);

    liberarInventario(); // Libera memoria al final
    return 0;
}

int agregarProducto() {
    char nombreTemp[100];  // Guarda nombre temporal
    int cantidadTemp;      // Guarda cantidad temporal
    float precioTemp;      // Guarda precio temporal

    printf("\n=== AGREGAR PRODUCTO ===\n");
    printf("Nombre del producto: ");
    scanf(" %[^\n]", nombreTemp); // Lee nombre con espacios
    printf("Cantidad: ");
    scanf("%d", &cantidadTemp);
    printf("Precio: ");
    scanf("%f", &precioTemp);

    int nuevoTotal = totalP + 1; // Aumenta el contador

    // Reasignar memoria para nuevos datos
    char **tempNombres = realloc(nombresProductos, nuevoTotal * sizeof(char *));
    int *tempCantidades = realloc(cantidades, nuevoTotal * sizeof(int));
    float *tempPrecios = realloc(precios, nuevoTotal * sizeof(float));

    // Verifica errores de memoria
    if (!tempNombres || !tempCantidades || !tempPrecios) {
        printf("Error al asignar memoria.\n");
        free(tempNombres);
        free(tempCantidades);
        free(tempPrecios);
        return 0;
    }

    // Actualiza los punteros globales
    nombresProductos = tempNombres;
    cantidades = tempCantidades;
    precios = tempPrecios;

    // Reserva espacio exacto para el nombre
    nombresProductos[totalP] = malloc((strlen(nombreTemp) + 1) * sizeof(char));
    if (!nombresProductos[totalP]) {
        printf("Error al asignar memoria para el nombre.\n");
        return 0;
    }

    // Copia los datos en el inventario
    strcpy(nombresProductos[totalP], nombreTemp);
    cantidades[totalP] = cantidadTemp;
    precios[totalP] = precioTemp;

    totalP = nuevoTotal; // Actualiza el total

    printf("Producto agregado correctamente.\n");
    return 1;
}

void mostrarProductos() { 
    if (totalP == 0) { // Si no hay productos
        printf("No hay productos en el inventario.\n");
        return;
    }

    printf("\n=== Productos %d ===\n", totalP);
    printf("Pos\tNombre\t\t\tCantidad\tPrecio\t\tValor\n");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < totalP; i++) { // Recorre todo el inventario
        float valor = cantidades[i] * precios[i]; // Calcula valor individual
        printf("Pos %d: %s - Cant: %d - Precio: $%.2f - Valor: $%.2f\n",
               i, nombresProductos[i], cantidades[i], precios[i], valor);
    }
}

double calcularValorTotalInventario() {
    double total = 0;

    if (totalP == 0) { // Si no hay productos
        printf("No hay productos en el inventario.\n");
        return 0;
    }

    for (int i = 0; i < totalP; i++) { // Suma cantidad * precio
        total += cantidades[i] * precios[i];
    }

    return total; // Devuelve total
}

void liberarInventario() {
    if (totalP == 0) return; // Si no hay nada, sale

    for (int i = 0; i < totalP; i++) {
        free(nombresProductos[i]); // Libera cada nombre
    }

    free(nombresProductos); // Libera arreglo principal de nombres
    free(cantidades);       // Libera arreglo de cantidades
    free(precios);          // Libera arreglo de precios

    // Reinicia valores globales
    nombresProductos = NULL;
    cantidades = NULL;
    precios = NULL;
    totalP = 0;

    printf("Memoria liberada correctamente.\n");
}

// 🔹 PASO 6: Llena el inventario inicial con productos base
void llenarInventarioInicial() {
    char *nombresBase[] = { // Nombres iniciales
        "Laptop HP", "Mouse Inalambrico", "Teclado Mecanico", "Camisa Casual",
        "Jeans", "Zapatos Deportivos", "Arroz", "Frijol", "Aceite"
    };
    int cantidadesBase[] = {5, 15, 8, 20, 12, 10, 50, 40, 30}; // Cantidades base
    float preciosBase[] = {1200.00, 25.50, 75.00, 35.00, 45.00, 60.00, 2.50, 3.00, 4.50}; // Precios base

    for (int i = 0; i < 9; i++) { // Agrega los 9 productos base
        int nuevoTotal = totalP + 1;

        // Reasigna espacio para cada producto nuevo
        nombresProductos = realloc(nombresProductos, nuevoTotal * sizeof(char *));
        cantidades = realloc(cantidades, nuevoTotal * sizeof(int));
        precios = realloc(precios, nuevoTotal * sizeof(float));

        // Copia los datos del producto
        nombresProductos[totalP] = malloc(strlen(nombresBase[i]) + 1);
        strcpy(nombresProductos[totalP], nombresBase[i]);
        cantidades[totalP] = cantidadesBase[i];
        precios[totalP] = preciosBase[i];
        totalP = nuevoTotal;
    }

    printf("Inventario inicial cargado con %d productos.\n", totalP); // Confirma carga
}
void buscarProductoPorNombre() {
    if (totalP == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    char nombreBuscado[100];
    printf("\n=== BUSCAR PRODUCTO POR NOMBRE ===\n");
    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nombreBuscado);

    int encontrado = 0;

    // Recorre usando notación de punteros
    for (int i = 0; i < totalP; i++) {
        char *nombreActual = *(nombresProductos + i);

        if (strcasecmp(nombreActual, nombreBuscado) == 0) { // Comparación sin importar mayúsculas/minúsculas
            printf("\nProducto encontrado:\n");
            printf("Nombre: %s\n", nombreActual);
            printf("Cantidad: %d\n", *(cantidades + i));
            printf("Precio: $%.2f\n", *(precios + i));
            printf("Valor total: $%.2f\n", ((cantidades + i)) * ((precios + i)));
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró ningún producto con ese nombre.\n");
    }
}