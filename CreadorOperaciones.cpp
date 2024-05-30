#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include<thread>

using namespace std;

class CreadorOperaciones {
    vector<vector<double>> matrix; 
    vector<vector<double>> newMatrix;
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
            // Inicializar la nueva matriz con las mismas dimensiones que la matriz original
            newMatrix.resize(rows, vector<double>(cols));
        }
        else {
            cerr << "Error al abrir el archivo " << filename << endl;
        }
    }

    // Función para realizar un cálculo intensivo utilizando la función seno
    void calculateSin(int iterations) {
        unsigned int numThreads = thread::hardware_concurrency();  // Obtiene el número de hilos soportados por el hardware
        vector<thread> threads;  // Vector que almacenará los hilos
        size_t numRows = matrix.size();  // Obtiene el número de filas de la matriz

        auto worker = [this, iterations](size_t startRow, size_t endRow) {  // Función lambda que realiza el trabajo en paralelo
            for (int iter = 0; iter < iterations; ++iter) {  // Itera sobre el número de iteraciones
                for (size_t i = startRow; i < endRow; ++i) {  // Itera sobre las filas asignadas al hilo
                    for (size_t j = 0; j < matrix[i].size(); ++j) {  // Itera sobre las columnas de la matriz
                        // Calcula el seno de cada elemento de la matriz y lo asigna a la nueva matriz
                        newMatrix[i][j] = sin(matrix[i][j]);
                    }
                }
            }
            };

        size_t chunkSize = numRows / numThreads;  // Tamaño de cada bloque de filas para distribuir entre hilos
        size_t remainingRows = numRows % numThreads;  // Filas restantes que no entran exactamente en los bloques

        size_t currentStartRow = 0;  // Índice de inicio de las filas para el primer bloque
        for (unsigned int t = 0; t < numThreads; ++t) {  // Itera sobre el número de hilos
            size_t currentEndRow = currentStartRow + chunkSize;  // Índice de fin de las filas para el bloque actual
            if (t == numThreads - 1) {  // Si es el último hilo
                currentEndRow += remainingRows;  // Añade las filas restantes al último bloque
            }
            threads.emplace_back(worker, currentStartRow, currentEndRow);  // Crea un hilo con la función lambda y los parámetros de filas
            currentStartRow = currentEndRow;  // Actualiza el índice de inicio para el siguiente bloque
        }

        for (auto& thread : threads) {  // Espera a que todos los hilos terminen
            thread.join();
        }
    }


    /*
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
    }*/
    void calculateCos(int iterations) {
        unsigned int numThreads = thread::hardware_concurrency();
        vector<thread> threads;
        size_t numRows = matrix.size();

        auto worker = [this, iterations](size_t startRow, size_t endRow) {
            for (int iter = 0; iter < iterations; ++iter) {
                for (size_t i = startRow; i < endRow; ++i) {
                    for (size_t j = 0; j < matrix[i].size(); ++j) {
                        // Operación de coseno sobre cada elemento de la matriz
                        newMatrix[i][j] = cos(matrix[i][j]);
                    }
                }
            }
            };

        size_t chunkSize = numRows / numThreads;
        size_t remainingRows = numRows % numThreads;

        size_t currentStartRow = 0;
        for (unsigned int t = 0; t < numThreads; ++t) {
            size_t currentEndRow = currentStartRow + chunkSize;
            if (t == numThreads - 1) {
                currentEndRow += remainingRows;
            }
            threads.emplace_back(worker, currentStartRow, currentEndRow);
            currentStartRow = currentEndRow;
        }

        for (auto& thread : threads) {
            thread.join();
        }
    }


    /*

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
    }*/


    void calculatePow(int iterations) {
        unsigned int numThreads = thread::hardware_concurrency();
        vector<thread> threads;
        size_t numRows = matrix.size();

        auto worker = [this, iterations](size_t startRow, size_t endRow) {
            for (int iter = 0; iter < iterations; ++iter) {
                for (size_t i = startRow; i < endRow; ++i) {
                    for (size_t j = 0; j < matrix[i].size(); ++j) {
                        // Operación de potencia sobre cada elemento de la matriz
                        newMatrix[i][j] = pow(matrix[i][j], 2);
                    }
                }
            }
            };

        size_t chunkSize = numRows / numThreads;
        size_t remainingRows = numRows % numThreads;

        size_t currentStartRow = 0;
        for (unsigned int t = 0; t < numThreads; ++t) {
            size_t currentEndRow = currentStartRow + chunkSize;
            if (t == numThreads - 1) {
                currentEndRow += remainingRows;
            }
            threads.emplace_back(worker, currentStartRow, currentEndRow);
            currentStartRow = currentEndRow;
        }

        for (auto& thread : threads) {
            thread.join();
        }
    }

    /*
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
    }*/

    //// Función para realizar un cálculo intensivo el cual se le aplica el seno + coseno + matriz al cuadrado
    //void calculateIntensiveWork(int iterations) {
    //    // Determinar el número de hilos basado en el número de núcleos de la CPU
    //    int num_threads = thread::hardware_concurrency();
    //    vector<thread> threads(num_threads); // Vector de hilos

    //    // Dividir la matriz en bloques para distribuir el trabajo entre los hilos
    //    int block_size = matrix.size() / num_threads;
    //    // Función lambda para ejecutar en cada hilo
    //    auto intensiveWorkThreadFunc = [this, iterations, block_size](int start, int end) {
    //        for (int iter = 0; iter < iterations; ++iter) {
    //            for (int i = start; i < end; ++i) {
    //                for (size_t j = 0; j < matrix[i].size(); ++j) {
    //                    // Operación compleja usando seno, coseno y potencia
    //                    double oldValue = matrix[i][j];
    //                    matrix[i][j] = sin(matrix[i][j]) + cos(matrix[i][j]) + pow(matrix[i][j], 2);
    //                    double newValue = matrix[i][j];
    //                }
    //            }
    //        }
    //        };
    //}

    void calculateIntensiveWork(int iterations) {
        unsigned int numThreads = thread::hardware_concurrency();
        vector<thread> threads;
        size_t numRows = matrix.size();

        // Dividir el trabajo entre los hilos
        auto worker = [this, iterations](size_t startRow, size_t endRow) {
            for (int iter = 0; iter < iterations; ++iter) {
                for (size_t i = startRow; i < endRow; ++i) {
                    for (size_t j = 0; j < matrix[i].size(); ++j) {
                        // Operación compleja usando seno, coseno y potencia   
                        newMatrix[i][j] = sin(matrix[i][j]) + cos(matrix[i][j]) + pow(matrix[i][j], 2);
                    }
                }
            }
        };

        size_t chunkSize = numRows / numThreads;
        size_t remainingRows = numRows % numThreads;

        size_t currentStartRow = 0;
        for (unsigned int t = 0; t < numThreads; ++t) {
            size_t currentEndRow = currentStartRow + chunkSize;
            if (t == numThreads - 1) {
                currentEndRow += remainingRows;
            }
            threads.emplace_back(worker, currentStartRow, currentEndRow);
            currentStartRow = currentEndRow;
        }

        for (auto& thread : threads) {
            thread.join();
        }
    }


    void saveMatrixToFile(const std::string& filename) {
        std::ofstream outputFile(filename);

        if (outputFile.is_open()) {
            for (const auto& row : newMatrix) {
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
    // Función para imprimir la nueva matriz con los nuevos calculos 
    void printNewMatrix() const {
        for (const auto& row : newMatrix) {
            for (double val : row) {
                cout << val << "     ";
            }
            cout << endl;
        }
    }
};

