// prueba

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "NumberConverter.h"

using namespace std;

const int BINARY_OPTION = 1;
const int FIBONACCI_OPTION = 2;
const int FACTORIAL_OPTION = 3;
const int EXIT_OPTION = 0;

int factorial(int n) {
    if (n < 2) {
        return 1;
    }

    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n < 2) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

vector<int> readNumbersFromFile(string fileName) {
    vector<int> numbers = vector<int>();

    ifstream file;
    file.open(fileName, ios::in);

    if (file.is_open()) {
        while (!file.eof()) {
            string line;
            getline(file, line);
            int number = stoi(line);
                
            numbers.push_back(number);
        }
    }

    return numbers;
}

void writeResults(vector<string> results) {
    fstream output;
    output.open("output.csv", ios::out);

	int size = results.size();
    for (int i = 0; i < size; i++) {
        output << results[i] << "\n";
    }
}

int menu() {
    cout << "\n1. Convertir números decimales a binarios\n";
    cout << "2. Mostrar serie de fibonacci\n";
    cout << "3. Mostrar el factorial de un número\n";
    cout << "0. Salir\n";
    cout << "Ingrese la opción que desea: ";

    int option;
    cin >> option;
    return option;
}

int binaryNumbersMenu() {
    int option;
    do
    {
        cout << "\n1. Convertir un número\n";
        cout << "2. Convertir varios números\n";
        cout << "Ingrese una opción: ";

        cin >> option;
    } while (option < 1 && option > 2);

    if (option == 1) {
        int x;
        cout << "Ingrese un número: ";
        cin >> x;
        cout << x << " = " << NumberPrinter::toBase2String(x) << "\n";
    }
    else {
        string fileName;
        cout << "Ingrese la ubicación del archivo: ";
        cin >> fileName;
        vector<int> numbers = readNumbersFromFile(fileName);
        vector<string> results = NumberPrinter::toBase2Strings(numbers);
        writeResults(results);
        system("output.csv");
    }

    return option;
}

void fibonacciMenu() {
    int n;
    cout << "\nIngrese un número: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << "\n";
}

void factorialMenu() {
    int n;
    cout << "\nIngrese un número: ";
    cin >> n;

    cout << "Factorial(" << n << ") = " << factorial(n) << "\n";
}

int handleOption(int option) {
    switch (option)
    {
    case BINARY_OPTION:
        option = binaryNumbersMenu();
        break;
    case FIBONACCI_OPTION:
        fibonacciMenu();
        break;
    case FACTORIAL_OPTION:
        factorialMenu();
        break;
    case EXIT_OPTION:
        cout << "¡Adiós!";
        break;
    default:
        cout << "Opción no válida\n";
        return int::MaxValue;
    }

    return option;
}

int main()
{
    int option;
    do {
        option = menu();
        option = handleOption(option);
    } while (option > 0);
    
    return 0;
}
