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
    Utils () : creador("C:\\Users\\allen\\source\\repos\\OperacionesAritmeticas\\datos.txt") {
    
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
       creador.printMatrix();
       cout << endl;
       cout << endl;
       cout << endl;
       cout << endl;

       creador.calculateIntensiveWork(iterations); // Realizar cálculos intensivos con 100 iteraciones
       creador.printNewMatrix(); // Imprimir la matriz modificada
       end = high_resolution_clock::now();
       auto sequentialTime = duration_cast<milliseconds>(end - start).count();
       cout << endl;
       cout << endl;
       cout << "Tiempo de ejecución Paralelo de IntensiveWork: " << sequentialTime << " Milisegundos" << endl;
       cout << endl;
       cout << endl;
     }

     void calculaSin(int iterations) {
         high_resolution_clock::time_point start, end;
         start = high_resolution_clock::now();
         creador.printMatrix();
         cout << endl;
         cout << endl;
         cout << endl;
         cout << endl;

         creador.calculateSin(iterations); // Realizar cálculos intensivos con 100 iteraciones
         creador.printNewMatrix(); // Imprimir la matriz modificada
         end = high_resolution_clock::now();
         auto sequentialTime = duration_cast<milliseconds>(end - start).count();
         cout << endl;
         cout << endl;
         cout << "Tiempo de ejecución Paralelo de Seno es: " << sequentialTime << " Milisegundos" << endl;
         cout << endl;
         cout << endl;
     }

     void calculaCos(int iterations) {
         high_resolution_clock::time_point start, end;
         start = high_resolution_clock::now();
         creador.printMatrix();
         cout << endl;
         cout << endl;
         cout << endl;
         cout << endl;

         creador.calculateCos(iterations); // Realizar cálculos intensivos con 100 iteraciones
         creador.printNewMatrix(); // Imprimir la matriz modificada
         end = high_resolution_clock::now();
         auto sequentialTime = duration_cast<milliseconds>(end - start).count();
         cout << endl;
         cout << endl;
         cout << "Tiempo de ejecución Paralelo de Coseno es: " << sequentialTime << " Milisegundos" << endl;
         cout << endl;
         cout << endl;
     }

     void calculaPow(int iterations) {
         high_resolution_clock::time_point start, end;
         start = high_resolution_clock::now();
         creador.printMatrix();
         cout << endl;
         cout << endl;
         cout << endl;
         cout << endl;

         creador.calculatePow(iterations); // Realizar cálculos intensivos con 100 iteraciones
         creador.printNewMatrix(); // Imprimir la matriz modificada
         end = high_resolution_clock::now();
         auto sequentialTime = duration_cast<milliseconds>(end - start).count();
         cout << endl;
         cout << endl;
         cout << "Tiempo de ejecución Paralelo del elevado(POW) es: " << sequentialTime << " Milisegundos" << endl;
         cout << endl;
         cout << endl;
     }

     void saveMatrix() {
         creador.saveMatrixToFile("C:\\Users\\allen\\source\\repos\\OperacionesAritmeticas\\resultados.txt");
     }
};  