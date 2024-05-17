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


    cout << endl;
    cout << endl;
    cout << endl;
    
    time =  utils.timeSin(100); // Ejecutar 100 iteraciones de cálculo de seno
    std::cout << "Tiempo secuencial: SIN( " << time << " milisegundos )" << std::endl;

    time = utils.timeCos(100); // Ejecutar 100 iteraciones de cálculo de seno
    std::cout << "Tiempo secuencial: COS( " << time << " milisegundos )" << std::endl;

    time = utils.timePow(100); // Ejecutar 100 iteraciones de cálculo de seno
    std::cout << "Tiempo secuencial: POW( " << time << " milisegundos )" << std::endl;

    utils.saveMatrix();
}
