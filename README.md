# 🚀 Algoritmo QuickSort Secuencial con Análisis de Números Primos en C

## 📚 Proyecto de Computación Paralela: QuickSort y Criba de Eratóstenes

Este proyecto implementa un algoritmo **QuickSort** altamente eficiente en C junto con la detección de números primos utilizando la **Criba de Eratóstenes**. La implementación está diseñada para el procesamiento y análisis de datos de alto rendimiento, con mediciones precisas del tiempo de ejecución.

## 🔍 Características Principales

- Implementación de QuickSort con estrategia de partición de doble índice
- Criba de Eratóstenes para detección eficiente de números primos
- Mediciones de tiempo de ejecución de alta precisión usando `clock_gettime()`
- Soporte para arreglos de hasta 100 millones de elementos
- Asignación dinámica de memoria para grandes conjuntos de datos
- Generación de números aleatorios con rangos configurables

## 🧮 Algoritmos Principales

### Implementación de QuickSort
- Utiliza el último elemento como pivote
- Estrategia de partición de doble índice para intercambio eficiente de elementos
- Complejidad Temporal: O(n log n) caso promedio
- Complejidad Espacial: O(log n) debido a la recursión

### Criba de Eratóstenes
- Identifica eficientemente números primos hasta 1,000,000
- Complejidad Temporal: O(n log log n)
- Complejidad Espacial: O(n) usando optimización de arreglo booleano
  
## 🧮 Criba de Eratóstenes

El proyecto incluye una funcionalidad para contar números primos en un conjunto grande de datos. 

## 💻 Funciones Principales

```c
void quickSort(int array[], int low, int high)
int partition(int array[], int low, int high)
void cribaEratostenes(bool *esPrimo, int n)
int contarPrimos(int array[], int size, bool *esPrimo)
```

## 🛠️ Compilación y Ejecución

El programa requiere la biblioteca matemática (`-lm`) y la biblioteca de tiempo real (`-lrt`) para una compilación correcta. Aquí están los comandos de compilación recomendados:

```bash
# Compilar versión normal
gcc -o quicksort1 SecuencialQuickSort.c

# Compilar versión de depuración
gcc -o quicksort2 SecuencialQuickSortDebug.c

# Compilar versión con contador de primos
gcc -o quicksort3 SecuencialQuickSortPrimeNumbers.c -lm -lrt

# Ejecutar versión normal
./quicksort1

# Ejecutar versión de depuración
./quicksort2

# Ejecutar versión con contador de primos
./quicksort3
```

## 📚 Entrada de Datos

1. Generación Aleatoria:
- Hasta 100,000,000 elementos generados dinámicamente.
- Los números están en el rango [0, 999,999].

2. Archivo de Texto:
- Lee valores desde un archivo llamado 1000numeros.txt (opcional).
- Debe estar en el mismo directorio que el código fuente.

## 🧠 Conceptos Clave

1. **Pivote**: Elemento de referencia para particionar
2. **Partición**: Dividir el arreglo en subarrays
3. **Recursividad**: Aplicar QuickSort a subarrays
4. **Criba**: Algoritmo eficiente para encontrar números primos.
5. **Semillas Aleatorias**: Aseguran la diversidad en la generación de datos.
6. **Medición de Tiempo**: Precisión con `clock_gettime()`.

## 🔬 Análisis de Complejidad

### QuickSort:
- Mejor Caso: O(n log n) con particiones equilibradas.
- Peor Caso: O(n²) con particiones desbalanceadas.
- Caso Promedio: O(n log n).

### Criba de Eratóstenes:
- Complejidad Temporal: O(n log log n).
- Complejidad Espacial: O(n) debido al uso de arreglos booleanos.
  
## 🛡️ Manejo de Errores

- Verificación de límites del arreglo
- Control de condiciones de recursividad
- Prevención de desbordamiento de pila
- Validación de mediciones de tiempo de ejecución

## 💻 Tecnologías

<div align="center">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" height="40" alt="c logo" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/gcc/gcc-original.svg" height="40" alt="gcc logo" />
</div>

## 🧑🏻‍💻 Autor:

Valentin Mathey | <a href="https://github.com/valentinmathey">@valentinmathey</a>

[![Discord](https://img.shields.io/badge/Discord-%237289DA.svg?logo=discord&logoColor=white)](https://discord.gg/valentinmathey) [![Facebook](https://img.shields.io/badge/Facebook-%231877F2.svg?logo=Facebook&logoColor=white)](https://facebook.com/ValentinEzequielMathey) [![Instagram](https://img.shields.io/badge/Instagram-%23E4405F.svg?logo=Instagram&logoColor=white)](https://instagram.com/valen.mathey/) [![LinkedIn](https://img.shields.io/badge/LinkedIn-%230077B5.svg?logo=linkedin&logoColor=white)](https://linkedin.com/in/valentin-mathey) [![X](https://img.shields.io/badge/X-%231DA1F2.svg?logo=X&logoColor=white)](https://twitter.com/valen_mathey)
