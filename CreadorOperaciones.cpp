#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include<thread>

using namespace std;

class CreadorOperaciones {
    vector<vector<double>> matrix;
public:
    CreadorOperaciones(const string& filename) {
        // Leer la matriz desde el archivo de texto
        ifstream file(filename);
        if (file.is_open()) {
            int rows, cols;
            file >> rows >> cols; // Leer el número de filas y columnas de la matriz
            matrix.resize(rows, vector<double>(cols));
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    file >> matrix[i][j]; // Leer los elementos de la matriz
                }
            }   
            file.close(); // cerramos el archivo 
        }
        else {
            cerr << "Error al abrir el archivo " << filename << endl;
        }
    }

    void calculateSin(int iterations) {
        // Determinar el número de hilos basado en el número de núcleos de la CPU
        int num_threads = thread::hardware_concurrency();
        vector<thread> threads(num_threads); // Vector de hilos

        // Dividir la matriz en bloques para distribuir el trabajo entre los hilos
        int block_size = matrix.size() / num_threads;

        // Función lambda para ejecutar en cada hilo
        auto sinThreadFunc = [this, iterations, block_size](int start, int end) {
            for (int iter = 0; iter < iterations; ++iter) {
                for (int i = start; i < end; ++i) {
                    for (size_t j = 0; j < matrix[i].size(); ++j) {
                        double oldValue = matrix[i][j];
                        matrix[i][j] = sin(matrix[i][j]);
                        double newValue = matrix[i][j];
                    }
                }
            }
            };
    }
        // Crear y lanzar hilos
       // for (int t = 0; t < num_threads; ++t) {
         //   int start = t * block_size;
           // int end = (t == num_threads - 1) ? matrix.size() : (t + 1) * block_size;
            //threads[t] = thread(sinThreadFunc, start, end);
       // }
        // Esperar a que todos los hilos terminen
        //for (auto& th : threads) {
          //  th.join();
        //}
    


    void calculateCos(int iterations) {
        // Determinar el número de hilos basado en el número de núcleos de la CPU
        int num_threads = std::thread::hardware_concurrency();
        std::vector<std::thread> threads(num_threads); // Vector de hilos

        // Dividir la matriz en bloques para distribuir el trabajo entre los hilos
        int block_size = matrix.size() / num_threads;

        // Función lambda para ejecutar en cada hilo
        auto cosThreadFunc = [this, iterations, block_size](int start, int end) {
            for (int iter = 0; iter < iterations; ++iter) {
                for (int i = start; i < end; ++i) {
                    for (size_t j = 0; j < matrix[i].size(); ++j) {
                        double oldValue = matrix[i][j];
                        matrix[i][j] = cos(matrix[i][j]);
                        double newValue = matrix[i][j];
                    }
                }
            }
            };

        // Crear y ejecutar los hilos
       // int start = 0;
       // for (int i = 0; i < num_threads; ++i) {
       //     int end = (i == num_threads - 1) ? matrix.size() : start + block_size;
        //    threads[i] = std::thread(cosThreadFunc, start, end);
         //   start = end;
       // }

        // Esperar a que todos los hilos terminen
       // for (auto& thread : threads) {
       //     thread.join();
       // }
    }

    void calculatePow(int iterations) {
        int num_threads = thread::hardware_concurrency();
        vector<thread> threads(num_threads); // Vector de hilos
        int block_size = matrix.size() / num_threads;

        auto powThreadFunc = [this, iterations, block_size](int start, int end) {
            for (int iter = 0; iter < iterations; ++iter) {
                for (int i = start; i < end; ++i) {
                    for (size_t j = 0; j < matrix[i].size(); ++j) {
                        double oldValue = matrix[i][j];
                        matrix[i][j] = pow(matrix[i][j], 2);
                        double newValue = matrix[i][j];
                    }
                }
            }
            };
    }

    // Función para realizar un cálculo intensivo el cual se le aplica el seno + coseno + matriz al cuadrado
    void calculateIntensiveWork(int iterations) {
        // Determinar el número de hilos basado en el número de núcleos de la CPU
        int num_threads = thread::hardware_concurrency();
        vector<thread> threads(num_threads); // Vector de hilos

        // Dividir la matriz en bloques para distribuir el trabajo entre los hilos
        int block_size = matrix.size() / num_threads;

        // Función lambda para ejecutar en cada hilo
        auto intensiveWorkThreadFunc = [this, iterations, block_size](int start, int end) {
            for (int iter = 0; iter < iterations; ++iter) {
                for (int i = start; i < end; ++i) {
                    for (size_t j = 0; j < matrix[i].size(); ++j) {
                        // Operación compleja usando seno, coseno y potencia
                        double oldValue = matrix[i][j];
                        matrix[i][j] = sin(matrix[i][j]) + cos(matrix[i][j]) + pow(matrix[i][j], 2);
                        double newValue = matrix[i][j];
                    }
                }
            }
            };

        // Crear y lanzar hilos
    //    for (int t = 0; t < num_threads; ++t) {
         //   int start = t * block_size;
        //    int end = (t == num_threads - 1) ? matrix.size() : (t + 1) * block_size;
        //    threads[t] = thread(intensiveWorkThreadFunc, start, end);
       // }

        // Esperar a que todos los hilos terminen
      //  for (auto& th : threads) {
       //     th.join();
       // }
    }
    void saveMatrixToFile(const std::string& filename) {
        std::ofstream outputFile(filename);

        if (outputFile.is_open()) {
            for (const auto& row : matrix) {
                for (const auto& value : row) {
                    outputFile << value << " ";
                }
                outputFile << "\n";  // Nueva línea al final de cada fila
            }
            outputFile.close();
            std::cout << "Matriz guardada correctamente en " << filename << std::endl;
        }
        else {
            std::cerr << "Error al abrir el archivo " << filename << " para escritura." << std::endl;
        }
    }

    // Función para imprimir la matriz
    void printMatrix() const {
        for (const auto& row : matrix) {
            for (double val : row) {
                cout << val << "     ";
            }
            cout << endl;
        }
    }
};

