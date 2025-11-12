#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> //  Para usar strcasecmp (comparar sin mayúsculas/minúsculas)

// Punteros dobles globales para el inventario
char **nombresProductos = NULL;   // Guarda los nombres de los productos
int *cantidades = NULL;           // Guarda las cantidades
float *precios = NULL;            // Guarda los precios
int totalP = 0;                   // Número total de productos

// Prototipos de funciones
int agregarProducto();             
void mostrarProductos();           
double calcularValorTotalInventario(); 
void liberarInventario();          
void llenarInventarioInicial();    
void buscarProductoPorNombre();    
void actualizarStock(); // 🔹 Nueva función para modificar cantidades

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
        printf("5. Actualizar stock\n"); //  Nueva opción
        printf("6. Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                agregarProducto();
                break;
            case 2:
                mostrarProductos();
                break;
            case 3:
                printf("Valor total del inventario: $%.2f\n", calcularValorTotalInventario());
                break;
            case 4:
                buscarProductoPorNombre();
                break;
            case 5:
                actualizarStock(); //  Llama a la nueva función
                break;
            case 6:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while(opcion != 6);

    liberarInventario(); 
    return 0;
}

int agregarProducto() {
    char nombreTemp[100];
    int cantidadTemp;
    float precioTemp;

    printf("\n=== AGREGAR PRODUCTO ===\n");
    printf("Nombre del producto: ");
    scanf(" %[^\n]", nombreTemp);
    printf("Cantidad: ");
    scanf("%d", &cantidadTemp);
    printf("Precio: ");
    scanf("%f", &precioTemp);

    int nuevoTotal = totalP + 1;

    // Reasignar memoria para nuevos datos
    char **tempNombres = realloc(nombresProductos, nuevoTotal * sizeof(char *));
    int *tempCantidades = realloc(cantidades, nuevoTotal * sizeof(int));
    float *tempPrecios = realloc(precios, nuevoTotal * sizeof(float));

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
    if (totalP == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    printf("\n=== Productos %d ===\n", totalP);
    printf("Pos\tNombre\t\t\tCantidad\tPrecio\t\tValor\n");
    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < totalP; i++) {
        float valor = cantidades[i] * precios[i];
        printf("Pos %d: %s - Cant: %d - Precio: $%.2f - Valor: $%.2f\n",
               i, nombresProductos[i], cantidades[i], precios[i], valor);
    }
}

double calcularValorTotalInventario() {
    double total = 0;

    if (totalP == 0) {
        printf("No hay productos en el inventario.\n");
        return 0;
    }

    for (int i = 0; i < totalP; i++) {
        total += cantidades[i] * precios[i];
    }

    return total;
}

void liberarInventario() {
    if (totalP == 0) return;

    for (int i = 0; i < totalP; i++) {
        free(nombresProductos[i]);
    }

    free(nombresProductos);
    free(cantidades);
    free(precios);

    nombresProductos = NULL;
    cantidades = NULL;
    precios = NULL;
    totalP = 0;

    printf("Memoria liberada correctamente.\n");
}

void llenarInventarioInicial() {
    char *nombresBase[] = {
        "Laptop HP", "Mouse Inalambrico", "Teclado Mecanico", "Camisa Casual",
        "Jeans", "Zapatos Deportivos", "Arroz", "Frijol", "Aceite"
    };
    int cantidadesBase[] = {5, 15, 8, 20, 12, 10, 50, 40, 30};
    float preciosBase[] = {1200.00, 25.50, 75.00, 35.00, 45.00, 60.00, 2.50, 3.00, 4.50};

    for (int i = 0; i < 9; i++) {
        int nuevoTotal = totalP + 1;

        nombresProductos = realloc(nombresProductos, nuevoTotal * sizeof(char *));
        cantidades = realloc(cantidades, nuevoTotal * sizeof(int));
        precios = realloc(precios, nuevoTotal * sizeof(float));

        nombresProductos[totalP] = malloc(strlen(nombresBase[i]) + 1);
        strcpy(nombresProductos[totalP], nombresBase[i]);
        cantidades[totalP] = cantidadesBase[i];
        precios[totalP] = preciosBase[i];
        totalP = nuevoTotal;
    }

    printf("Inventario inicial cargado con %d productos.\n", totalP);
}

void buscarProductoPorNombre() {
    if (totalP == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    char nombreBuscado[100];
    printf("\n=== BUSCAR PRODUCTO ===\n");
    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nombreBuscado);

    int encontrado = 0;

    for (int i = 0; i < totalP; i++) {
        char *nombreActual = *(nombresProductos + i);

        if (strcasecmp(nombreActual, nombreBuscado) == 0) {
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

// 🔹 NUEVA FUNCIÓN: ACTUALIZAR STOCK
void actualizarStock() {
    if (totalP == 0) { 
        printf("No hay productos en el inventario.\n");
        return;
    }

    int posicion;
    printf("\n=== ACTUALIZAR STOCK ===\n");
    printf("Ingrese la posición del producto a actualizar (0 - %d): ", totalP - 1);
    scanf("%d", &posicion);

    // Verifica que la posición exista
    if (posicion < 0 || posicion >= totalP) { 
        printf("Error: posición inválida.\n");
        return;
    }

    // Muestra producto actual antes del cambio
    printf("Producto actual: %s - Stock: %d\n", *(nombresProductos + posicion), *(cantidades + posicion));

    int nuevaCantidad;
    printf("Ingrese la nueva cantidad: ");
    scanf("%d", &nuevaCantidad);

    // Valida que la cantidad no sea negativa
    if (nuevaCantidad < 0) { 
        printf("Error: la cantidad no puede ser negativa.\n");
        return;
    }

    // Actualiza el stock (usando notación de punteros)
    *(cantidades + posicion) = nuevaCantidad; //  Asigna la nueva cantidad

    printf("Stock actualizado correctamente.\n"); //  Confirma la actualización
}