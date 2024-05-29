#include <iostream>
#include "Utils.cpp"

using namespace std;

void showMenu() {
    cout << "Seleccione una opción:" << endl;
    cout << "1. Calcular el seno de la matriz." << endl;
    cout << "2. Calcular el coseno de la matriz." << endl;
    cout << "3. Calcular la potencia de la matriz." << endl;
    cout << "4. Realizar un trabajo intensivo (sin + cos + potencia)." << endl;
    cout << "5. Salir del programa." << endl;
}

int main() {
    Utils utils;

    int option;
    do {
        showMenu();
        cout << "Opción: ";
        cin >> option;

        switch (option) {
        case 1:
            utils.calculaSin(1);
            break;
        case 2:
            utils.calculaCos(1);
            break;
        case 3:
            utils.calculaPow(1);
            break;
        case 4:
            utils.timeIntensiveWork(1);
            break;
        case 5:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
        }
    } while (option != 5);

    double time;
    time = utils.timeSin(100); // Ejecutar 100 iteraciones de cálculo de seno
    std::cout << "Tiempo en paralelo es: SIN( " << time << " milisegundos )" << std::endl;

    time = utils.timeCos(100); // Ejecutar 100 iteraciones de cálculo de seno
    std::cout << "Tiempo en apralelo es: COS( " << time << " milisegundos )" << std::endl;

    time = utils.timePow(100); // Ejecutar 100 iteraciones de cálculo de seno
    std::cout << "Tiempo en paralelo es: POW( " << time << " milisegundos )" << std::endl;

    utils.saveMatrix();

    return 0;
}