#include <iostream>
#include <chrono>
//#include "CreadorOperaciones.cpp"
#include "Utils.cpp"
using namespace std;
using namespace std::chrono;

int main() {
    Utils utils;
    double time;
    utils.timeIntensiveWork(1);
    utils.calculaSin(1);
    utils.calculaCos(1);
    utils.calculaPow(1);

    cout << endl;
    cout << endl;
    cout << endl;
    
    time =  utils.timeSin(100); // Ejecutar 100 iteraciones de cálculo de seno
    std::cout << "Tiempo en paralelo es: SIN( " << time << " milisegundos )" << std::endl;

    time = utils.timeCos(100); // Ejecutar 100 iteraciones de cálculo de seno
    std::cout << "Tiempo en apralelo es: COS( " << time << " milisegundos )" << std::endl;

    time = utils.timePow(100); // Ejecutar 100 iteraciones de cálculo de seno
    std::cout << "Tiempo en paralelo es: POW( " << time << " milisegundos )" << std::endl;

    utils.saveMatrix();
}
