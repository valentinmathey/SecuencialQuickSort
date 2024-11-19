#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_NUMEROS 100000000
#define MAX_N 1000000  // Limite superior para buscar primos

// Función para intercambiar dos elementos en el arreglo
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para imprimir los primeros 1000 elementos del arreglo
void printArray(int array[], int size) {
    int i;
    for (i = 0; i < 1000; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Función para mostrar los primeros 1000 números primos marcados en la criba
void mostrarPrimos(bool *esPrimo, int n) {
    int i;
    printf("\nPrimos en el rango de 2 a %d: ", 100);
    for (i = 2; i <= 100; i++) {
        if (esPrimo[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Función de partición utilizando un pivote con doble índice
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int leftIndex = low - 1;
    int rightIndex = high;

    while (1) {
        do { leftIndex++; } while (array[leftIndex] < pivot);
        do { rightIndex--; } while (rightIndex >= low && array[rightIndex] > pivot);

        if (leftIndex >= rightIndex) {
            swap(&array[leftIndex], &array[high]);
            return leftIndex;
        }
        swap(&array[leftIndex], &array[rightIndex]);
    }
}

// Función recursiva de Quick Sort para ordenar el arreglo
void quickSort(int array[], int low, int high) {
    if (low >= high) return;
    int pivot = partition(array, low, high);
    quickSort(array, low, pivot - 1);
    quickSort(array, pivot + 1, high);
}

// Función para calcular el tiempo de ejecución en segundos
double getExecutionTime(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

// Función que usa la Criba de Eratóstenes para marcar números primos
void cribaEratostenes(bool *esPrimo, int n) {
    int i, j;
    for (i = 2; i <= n; i++) {
        esPrimo[i] = true;
    }
    for (i = 2; i <= sqrt(n); i++) {
        if (esPrimo[i]) {
            for (j = i * i; j <= n; j += i) {
                esPrimo[j] = false;
            }
        }
    }
}

// Función para contar los primos en el arreglo
int contarPrimos(int array[], int size, bool *esPrimo) {
    int i, contadorPrimos = 0;
    for (i = 0; i < size; i++) {
        if (array[i] <= MAX_N && esPrimo[array[i]]) {
            contadorPrimos++;
        }
    }
    return contadorPrimos;
}

int main() {
    struct timespec startTotal, endTotal;
    clock_gettime(CLOCK_MONOTONIC, &startTotal);

    // Inicializar el generador de números aleatorios con la hora actual
    srand(time(NULL));

    int *fullArray;
    int i;

    printf("Proceso: Iniciando ejecucion\n");

    // Reserva memoria para el arreglo completo y genera datos aleatorios
    fullArray = (int *)malloc(MAX_NUMEROS * sizeof(int));
    if (fullArray == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria.\n");
        return 1;
    }

    printf("Proceso: Generando datos aleatorios\n");

    for (i = 0; i < MAX_NUMEROS; i++) {
        fullArray[i] = rand() % 1000000; // Genera un número aleatorio positivo en el rango 0 a 999999
    }

    printf("Proceso: Generacion de datos completada, total de elementos: %d\n", MAX_NUMEROS);

    // Iniciar el tiempo total desde después de generar los números hasta después de ordenar
    struct timespec startProcessTotal, endProcessTotal;
    clock_gettime(CLOCK_MONOTONIC, &startProcessTotal);

    struct timespec startCount, endCount;
    clock_gettime(CLOCK_MONOTONIC, &startCount);

    // Configuración de la Criba de Eratóstenes
    bool esPrimo[MAX_N + 1];
    cribaEratostenes(esPrimo, MAX_N);

    // Medición del tiempo para contar primos
    int cantidadPrimos = contarPrimos(fullArray, MAX_NUMEROS, esPrimo);
    clock_gettime(CLOCK_MONOTONIC, &endCount);

    double time_spent_count_sec = getExecutionTime(startCount, endCount);
    double time_spent_count_ms = time_spent_count_sec * 1e3;
    double time_spent_count_ns = time_spent_count_sec * 1e9;

    printf("\nCantidad de numeros primos en el arreglo: %d", cantidadPrimos);
    printf("\n\nTiempo para contar primos:\n");
    printf("  %.9f segundos\n", time_spent_count_sec);
    printf("  %.6f milisegundos\n", time_spent_count_ms);
    printf("  %.0f nanosegundos\n", time_spent_count_ns);

    // Medición del tiempo para ordenar el arreglo
    struct timespec startSort, endSort;
    clock_gettime(CLOCK_MONOTONIC, &startSort);
    quickSort(fullArray, 0, MAX_NUMEROS - 1);
    clock_gettime(CLOCK_MONOTONIC, &endSort);

    double time_spent_sort_sec = getExecutionTime(startSort, endSort);
    double time_spent_sort_ms = time_spent_sort_sec * 1e3;
    double time_spent_sort_ns = time_spent_sort_sec * 1e9;

    printf("\nTiempo para ordenar el arreglo:\n");
    printf("  %.9f segundos\n", time_spent_sort_sec);
    printf("  %.6f milisegundos\n", time_spent_sort_ms);
    printf("  %.0f nanosegundos\n", time_spent_sort_ns);

    // Calcular tiempo total desde generación hasta final de ordenamiento
    clock_gettime(CLOCK_MONOTONIC, &endProcessTotal);
    double totalProcessTimeSec = getExecutionTime(startProcessTotal, endProcessTotal);
    double totalProcessTimeMs = totalProcessTimeSec * 1e3;
    double totalProcessTimeNs = totalProcessTimeSec * 1e9;

    printf("\nTiempo total desde después de generar números hasta ordenar:\n");
    printf("  %.9f segundos\n", totalProcessTimeSec);
    printf("  %.6f milisegundos\n", totalProcessTimeMs);
    printf("  %.0f nanosegundos\n", totalProcessTimeNs);

    // Liberar la memoria reservada para el arreglo
    free(fullArray);
    printf("Proceso: Finalizando ejecucion\n");

    return 0;
}
