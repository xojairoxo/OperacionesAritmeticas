#include <iostream>
#include <chrono>
//#include "CreadorOperaciones.cpp"
#include "Utils.cpp"
using namespace std;
using namespace std::chrono;

int main() {
    Utils utils;
    double time;
    utils.timeIntensiveWork(100);

    cout << endl;
    cout << endl;
    cout << endl;
    
    time =  utils.timeSin(1000); // Ejecutar 100 iteraciones de cálculo de seno
    std::cout << "Tiempo en paralelo es: SIN( " << time << " milisegundos )" << std::endl;

    time = utils.timeCos(1000); // Ejecutar 100 iteraciones de cálculo de seno
    std::cout << "Tiempo en apralelo es: COS( " << time << " milisegundos )" << std::endl;

    time = utils.timePow(1000); // Ejecutar 100 iteraciones de cálculo de seno
    std::cout << "Tiempo en paralelo es: POW( " << time << " milisegundos )" << std::endl;

    utils.saveMatrix();
}
