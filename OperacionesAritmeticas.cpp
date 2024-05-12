#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <cmath>

using namespace std;
using namespace std::chrono;

// Función para realizar un cálculo intensivo (simulación de carga)
void calculateIntensiveWork(int id, int iterations) {
    const int size = 10;
    vector<vector<double>> matrix(size, vector<double>(size, 1.0));

    // Realizar cálculos intensivos en la matriz
    for (int iter = 0; iter < iterations; ++iter) {
        // Operaciones en la matriz
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                // Operación compleja usando seno, coseno y potencia
                double oldValue = matrix[i][j];
                matrix[i][j] = sin(matrix[i][j]) + cos(matrix[i][j]) + pow(matrix[i][j], 2);
                double newValue = matrix[i][j];

                cout << "Hilo " << id << " - Iteración " << iter + 1 << " - Fila " << i << " - Columna " << j << endl;
                cout << "Operación: sin(" << oldValue << ") + cos(" << oldValue << ") + " << oldValue << "^2 = " << newValue << endl;
            }
        }
    }

    cout << "Hilo " << id << " terminado." << endl;
}

int main() {
    const int NUM_THREADS = 4;
    const int ITERATIONS = 15;

    vector<thread> threads;
    high_resolution_clock::time_point start, end;

    // Ejecución con hilos (paralelo)
    cout << "Ejecución con hilos (paralelo):" << endl;
    start = high_resolution_clock::now();
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(calculateIntensiveWork, i + 1, ITERATIONS / NUM_THREADS);
    }
    for (auto& t : threads) {
        t.join();
    }
    end = high_resolution_clock::now();
    auto parallelTime = duration_cast<milliseconds>(end - start).count();

    cout << endl;

    // Ejecución sin hilos (secuencial)
    cout << "Ejecución sin hilos (secuencial):" << endl;
    start = high_resolution_clock::now();
    calculateIntensiveWork(0, ITERATIONS);
    end = high_resolution_clock::now();
    auto sequentialTime = duration_cast<milliseconds>(end - start).count();
    cout << "Tiempo de ejecución secuencial: " << sequentialTime << " Milisegundos" << endl;

    cout << "Tiempo de ejecución paralelo con " << NUM_THREADS << " hilos: " << parallelTime << " Milisegundos" << endl;
    cout << endl;

    // Calcula la mejora de rendimiento al usar hilos
    double improvement = static_cast<double>(sequentialTime) / static_cast<double>(parallelTime);
    cout << "Mejora de rendimiento usando hilos: " << improvement << " veces" << endl;

    return 0;
}
