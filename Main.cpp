//Proyecto suseion de fibonacci
#include <iostream>
using namespace std;

int Fibonacci(int n) {
    if (n < 2 )
        return n;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    int n;
    cout <<"============ SUCESION DE FIBONACCI ============\n";
    cout <<"Ingrese un numero entero mayor 0: ";
    cin >> n;

    // Validacion para el usurio ingrese un numero mayor a 0
    while (n <= 0) {
        cout << "\nError. Debe ingresar un numero mayor a 0.\n";
        cout <<"Ingrese un numero entero mayor a 0: ";
        cin >> n;
    }

    cout << "\nFibonacci hasta el elemento " << n << ": ";

    //Bucle para impirmir cada elemento de la sucesion
    for (int i = 0; i < n; i++) {
        cout << Fibonacci(i);
        if (i < n - 1) cout << ", ";
    }

    return 0;
}