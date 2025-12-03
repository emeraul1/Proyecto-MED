//Proyecto sucesion de fibonacci Iterativo
#include <iostream>
using namespace std;

// Funcion iterativa para Fibonacci
int FibonacciIterativo(int n) {
    if (n < 2){
        return n;
    }

    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b; 
        a = b;     
        b = c;
    }

    return b;
}

int main() {
    int n;
    cout <<"============ SUCESION DE FIBONACCI ============\n";
    cout <<"Ingrese un numero entero mayor 0: ";
    cin >> n;

    // Validacion para el usuario ingrese un numero mayor a 0
    while (n <= 0) {
        cout << "\nError. Debe ingresar un numero mayor a 0.\n";
        cout <<"Ingrese un numero entero mayor a 0: ";
        cin >> n;
    }

    cout << "\nFibonacci hasta el elemento " << n << ": ";

    // Bucle para imprimir cada elemento de la sucesion
    for (int i = 0; i < n; i++) {
        cout << FibonacciIterativo(i);
        if (i < n - 1) cout << ", ";
    }

    return 0;
}