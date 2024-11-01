#include <stdio.h>
#include <time.h>

// Función para intercambiar dos elementos en el arreglo
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para imprimir el contenido del arreglo
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Función de partición mejorada utilizando un pivote con doble índice
int partition(int array[], int low, int high) {
    int pivot = array[high];       // Elige el último elemento como pivote
    int leftIndex = low - 1;       // Índice de la izquierda para encontrar elementos mayores que el pivote
    int rightIndex = high;         // Índice de la derecha para encontrar elementos menores que el pivote

    printf("\nParticionando con pivot = %d en la posicion %d\n", pivot, high);
    printArray(array, high + 1); // Imprime el array antes de la partición

    while (1) {
        // Incrementa leftIndex mientras los elementos son menores que el pivote
        do { leftIndex++; } while (array[leftIndex] < pivot);

        // Decrementa rightIndex mientras los elementos son mayores que el pivote
        do { rightIndex--; } while (rightIndex >= low && array[rightIndex] > pivot);

        // Muestra el estado actual de los índices y el array
        printf("leftIndex: %d (valor: %d), rightIndex: %d (valor: %d)\n", leftIndex, array[leftIndex], rightIndex, array[rightIndex]);
        
        // Si los índices se cruzan, intercambia el pivote con el elemento en leftIndex
        if (leftIndex >= rightIndex) {
            swap(&array[leftIndex], &array[high]);
            printf("Intercambiando pivot con array[%d] (valor: %d)\n", leftIndex, array[leftIndex]);
            printArray(array, high + 1); // Imprime el array después de colocar el pivote
            return leftIndex;  // Retorna la posición final del pivote
        }

        // Intercambia los elementos en leftIndex y rightIndex
        swap(&array[leftIndex], &array[rightIndex]);
        printf("Intercambiando array[%d] (valor: %d) con array[%d] (valor: %d)\n", leftIndex, array[leftIndex], rightIndex, array[rightIndex]);
        printArray(array, high + 1); // Imprime el array después del intercambio
    }
}

// Función recursiva de Quick Sort para ordenar el arreglo
void quickSort(int array[], int low, int high) {
    if (low >= high) { // Si el subarray tiene 0 o 1 elemento, está ordenado
        return;
    }
    int pivot = partition(array, low, high); // Encuentra la posición del pivote
    quickSort(array, low, pivot - 1);        // Ordena la parte izquierda
    quickSort(array, pivot + 1, high);       // Ordena la parte derecha
}

// Función para calcular el tiempo de ejecución en segundos
double getExecutionTime(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {
    // Arreglo de ejemplo
    int array[] = {10, 4, 7, 2, 8, 9, 1, 5, 6, 3};  
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array inicial: ");
    printArray(array, n);

    // Configuración para medir tiempo en nanosegundos
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Llamar a quickSort para ordenar el arreglo
    quickSort(array, 0, n - 1);

    // Medir tiempo de finalización
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calcular el tiempo de ejecución en segundos, milisegundos y nanosegundos
    double time_spent_sec = getExecutionTime(start, end);
    double time_spent_ms = time_spent_sec * 1e3;  // Convertir a milisegundos
    double time_spent_ns = time_spent_sec * 1e9;  // En nanosegundos

    printf("\nArray ordenado: ");
    printArray(array, n);

    // Imprimir el tiempo de ejecución en segundos, milisegundos y nanosegundos
    printf("\nTiempo de ejecucion: %.9f segundos\n", time_spent_sec);
    printf("Tiempo de ejecucion: %.6f milisegundos\n", time_spent_ms);
    printf("Tiempo de ejecucion: %.0f nanosegundos\n", time_spent_ns);

    return 0;
}
