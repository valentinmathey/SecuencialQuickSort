# 🚀 Algoritmo QuickSort Secuencial en C

## 📚 Proyecto de Computación Paralela: QuickSort

Este proyecto implementa el algoritmo de ordenamiento QuickSort en C, destacando su eficiencia y estrategia de división y conquista.

## 🧩 Algoritmo QuickSort

#### Estrategia de Pivote

El algoritmo QuickSort utiliza una estrategia de selección de pivote única:

- Selecciona el último elemento como pivote
- Utiliza dos índices (`leftIndex` y `rightIndex`) para particionar el arreglo
- Reordena los elementos de manera que los menores queden a la izquierda y los mayores a la derecha

#### 🔍 Características Técnicas

- **Complejidad Temporal**: O(n log n) en el caso promedio
- **Complejidad Espacial**: O(log n) debido a la recursividad
- **Método de Partición**: Doble índice con intercambio de elementos

## 💻 Funciones Principales

#### `partition()`

- Selecciona el pivote (último elemento)
- Reordena los elementos alrededor del pivote
- Retorna la posición final del pivote

#### `quickSort()`

- Función recursiva que divide el arreglo
- Ordena subarray izquierdo y derecho
- Condición de parada: subarrays con 0 o 1 elemento

## 🛠️ Compilación y Ejecución

```bash
# Compilar versión normal
gcc -o quicksort1 SecuencialQuickSort.c

# Compilar versión de depuración
gcc -o quicksort2 SecuencialQuickSortDebug.c

# Ejecutar versión normal
./quicksort1

# Ejecutar versión de depuración
./quicksort2
```

## 📊 Medición de Rendimiento

El programa mide el tiempo de ejecución en:
- Segundos
- Milisegundos
- Nanosegundos

Utilizando `clock_gettime()` para alta precisión.

## 🔬 Análisis de Complejidad

- **Mejor Caso**: O(n log n) - Particiones equilibradas
- **Peor Caso**: O(n²) - Arreglo ya ordenado o inversamente ordenado
- **Caso Promedio**: O(n log n)

## 🧠 Conceptos Clave

1. **Pivote**: Elemento de referencia para particionar
2. **Partición**: Dividir el arreglo en subarrays
3. **Recursividad**: Aplicar QuickSort a subarrays

## 🛡️ Manejo de Errores

- Verificación de límites del arreglo
- Control de condiciones de recursividad
- Prevención de desbordamiento de pila

## 💻 Tecnologías

<div align="center">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" height="40" alt="c logo" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/gcc/gcc-original.svg" height="40" alt="gcc logo" />
</div>

## 🧑🏻‍💻 Autor:

Valentin Mathey | <a href="https://github.com/valentinmathey">@valentinmathey</a>

[![Discord](https://img.shields.io/badge/Discord-%237289DA.svg?logo=discord&logoColor=white)](https://discord.gg/valentinmathey) [![Facebook](https://img.shields.io/badge/Facebook-%231877F2.svg?logo=Facebook&logoColor=white)](https://facebook.com/ValentinEzequielMathey) [![Instagram](https://img.shields.io/badge/Instagram-%23E4405F.svg?logo=Instagram&logoColor=white)](https://instagram.com/valen.mathey/) [![LinkedIn](https://img.shields.io/badge/LinkedIn-%230077B5.svg?logo=linkedin&logoColor=white)](https://linkedin.com/in/valentin-mathey) [![X](https://img.shields.io/badge/X-%231DA1F2.svg?logo=X&logoColor=white)](https://twitter.com/valen_mathey)
