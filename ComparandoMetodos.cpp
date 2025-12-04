#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Variables globales para contar iteraciones
long long iteracionesRec = 0;
long long iteracionesIt = 0;

// Fibonacci Recursivo
int FibonacciRecursivo(int n) {
    iteracionesRec++; 
    if (n < 2)
        return n;
    return FibonacciRecursivo(n - 1) + FibonacciRecursivo(n - 2);
}

// Fibonacci Iterativo
int FibonacciIterativo(int n) {
    iteracionesIt = 0;

    if (n < 2) {
        iteracionesIt++;
        return n;
    }

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        iteracionesIt++;
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

//Funciones para mostarar resultados
void EjecutarRecursivo(int n) {
    iteracionesRec = 0;

    cout << "\n--- Metodo Recursivo ---\n";
    cout << "Sucesion: ";

    auto inicio = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        cout << FibonacciRecursivo(i);
        if (i < n - 1) cout << ", ";
    }

    auto fin = high_resolution_clock::now();
    auto tiempo = duration_cast<microseconds>(fin - inicio);

    cout << "\nIteraciones: " << iteracionesRec;
    cout << "\nTiempo: " << tiempo.count() << " microsegundos\n";
}

void EjecutarIterativo(int n) {
    iteracionesIt = 0;

    cout << "\n--- Metodo Iterativo ---\n";
    cout << "Sucesion: ";

    auto inicio = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        cout << FibonacciIterativo(i);
        if (i < n - 1) cout << ", ";
    }

    auto fin = high_resolution_clock::now();
    auto tiempo = duration_cast<microseconds>(fin - inicio);

    cout << "\nIteraciones: " << iteracionesIt;
    cout << "\nTiempo: " << tiempo.count() << " microsegundos\n";
}


int main() {
    int opcion, n;
    char repetir;

    cout << "Ingrese un numero mayor a 0: ";
    cin >> n;

    while (n <= 0) {
        cout << "Error. Ingrese un numero mayor a 0: ";
        cin >> n;
    }

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Metodo Recursivo\n";
        cout << "2. Metodo Iterativo\n";
        cout << "3. Ejecutar Ambos\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:
            EjecutarRecursivo(n);
            break;

        case 2:
            EjecutarIterativo(n);
            break;

        case 3:
            EjecutarRecursivo(n);
            EjecutarIterativo(n);
            break;

        case 4:
            cout << "\nSaliendo del programa...\n";
            continue;

        default:
            cout << "Opcion invalida.\n";
            continue;
        }

        // Preguntar si quiere ingresar nueva sucesión
        cout << "\nDesea ingresar una nueva sucesion? (s/n): ";
        cin >> repetir;

        if (repetir == 's' || repetir == 'S') {
            cout << "Ingrese un numero mayor a 0: ";
            cin >> n;

            while (n <= 0) {
                cout << "Error. Ingrese un numero mayor a 0: ";
                cin >> n;
            }
        }

    } while (opcion != 4);

    return 0;
}