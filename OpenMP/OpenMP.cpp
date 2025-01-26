// OpenMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <omp.h>

// Globales
constexpr int N = 1000;
constexpr int CHUNK = 100;
constexpr int SHOW_SIZE = 10000; // char instead?

// Prevents out of bounds errors
static_assert(CHUNK < N, "CHUNK's value must be smaller than N");
static_assert(SHOW_SIZE < N, "SHOW_SIZE's value must be smaller than N");

void imprimeArreglo(const std::array<float, N>&);

int main() {
    std::cout << "Sumando arreglos en paralelo!\n\n" << std::endl;
    
    // Declaración de variables
    std::array<float, N> a, b, c;
    int i;

    // Inicialización de los arreglos
    for (i = 0; i < N; i++) {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7;
    }

    // Definición de la estrategia de paralelización con OpenMP
    #pragma omp parallel for shared(a, b, c, CHUNK) private(i) schedule(static, CHUNK)
    
    // Bucle paralelizado
    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    // Imprime en pantalla los arreglos a, b y c.
    std::cout << "Imprimiendo los primeros " << SHOW_SIZE << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << SHOW_SIZE << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << SHOW_SIZE << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
    
    return 0;
}

// Imprime elementos del arreglo apuntado hasta el número definido en 'mostrar' 
void imprimeArreglo(const std::array<float, N>& d) {
    for (int x = 0; x < SHOW_SIZE; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}

