// OpenMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>

// Globales
#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float* d);

int main() {
    std::cout << "Sumando arreglos en paralelo!\n" << std::endl;
    
    // Declaración de variables
    float a[N], b[N], c[N];
    int i;

    // Inicialización de los arreglos
    for (i = 0; i < N; i++) {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7;
    }

    int pedazos = chunk;

    // Definición de la estrategia de paralelización con OpenMP
    #pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)
    
    // Bucle paralelizado
    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    // Imprime en pantalla los arreglos a, b y c.
    std::cout << "Imprimiendo lso primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo lso primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo lso primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
    
    return 0;
}

// Imprime elementos del arreglo apuntado hasta el número definido en 'mostrar' 
void imprimeArreglo(float* d) {
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}

