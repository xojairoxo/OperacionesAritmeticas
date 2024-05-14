#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include "CreadorOperaciones.cpp"
using namespace std;

using namespace std::chrono;
class Utils {
    CreadorOperaciones creador;
public: 
    Utils () : creador("D:\\Sistemas Paralelos\\OperacionesAritmeticas\\datos.txt") {
        
    }
     double  timeSin(int iterations) {
        high_resolution_clock::time_point start, end;
        start = high_resolution_clock::now();
        for (int iter = 0; iter < iterations; ++iter) {
            creador.calculateSin(iterations);
        }
        end = high_resolution_clock::now();
        auto sequentialTime = duration_cast<milliseconds>(end - start).count();
        return sequentialTime;
    }
     double  timeCos(int iterations) {
         high_resolution_clock::time_point start, end;
         start = high_resolution_clock::now();
         for (int iter = 0; iter < iterations; ++iter) {
             creador.calculateCos(iterations);
         }
         end = high_resolution_clock::now();
         auto sequentialTime = duration_cast<milliseconds>(end - start).count();
         return sequentialTime;
     }
     double  timePow(int iterations) {
         high_resolution_clock::time_point start, end;
         start = high_resolution_clock::now();
         for (int iter = 0; iter < iterations; ++iter) {
             creador.calculatePow(iterations);
         }
         end = high_resolution_clock::now();
         auto sequentialTime = duration_cast<milliseconds>(end - start).count();
         return sequentialTime;
     }

     void timeIntensiveWork(int iterations) {
         high_resolution_clock::time_point start, end;
       start = high_resolution_clock::now();
       creador.calculateIntensiveWork(10); // Realizar cálculos intensivos con 100 iteraciones
       creador.printMatrix(); // Imprimir la matriz modificada
       end = high_resolution_clock::now();
       auto sequentialTime = duration_cast<milliseconds>(end - start).count();
       cout << "Tiempo de ejecución secuencial: " << sequentialTime << " Milisegundos" << endl;
     }
     void saveMatrix() {
         creador.saveMatrixToFile("D:\\Sistemas Paralelos\\OperacionesAritmeticas\\resultados.txt");
     }
};