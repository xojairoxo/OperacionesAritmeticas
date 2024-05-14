#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

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
        for (int iter = 0; iter < iterations; ++iter) {
            for (size_t i = 0; i < matrix.size(); ++i) {
                for (size_t j = 0; j < matrix[i].size(); ++j) {
                    double oldValue = matrix[i][j];
                    matrix[i][j] = sin(matrix[i][j]);
                    double newValue = matrix[i][j];
                }
            }
        }
    }

    void calculateCos(int iterations) {
        for (int iter = 0; iter < iterations; ++iter) {
            for (size_t i = 0; i < matrix.size(); ++i) {
                for (size_t j = 0; j < matrix[i].size(); ++j) {
                    double oldValue = matrix[i][j];
                    matrix[i][j] = cos(matrix[i][j]);
                    double newValue = matrix[i][j];
                }
            }
        }
    }

    void calculatePow(int iterations) {
        for (int iter = 0; iter < iterations; ++iter) {
            for (size_t i = 0; i < matrix.size(); ++i) {
                for (size_t j = 0; j < matrix[i].size(); ++j) {
                    double oldValue = matrix[i][j];
                    matrix[i][j] = pow(matrix[i][j], 2);
                    double newValue = matrix[i][j];
                }
            }
        }
    }

    // Función para realizar un cálculo intensivo el cual se le aplica el seno + coseno + matriz al cuadrado
    void calculateIntensiveWork(int iterations) {
        // Realizar cálculos intensivos en la matriz
        for (int iter = 0; iter < iterations; ++iter) {
            // Operaciones en la matriz
            for (size_t i = 0; i < matrix.size(); ++i) {
                for (size_t j = 0; j < matrix[i].size(); ++j) {
                    // Operación compleja usando seno, coseno y potencia
                    double oldValue = matrix[i][j];
                    matrix[i][j] = sin(matrix[i][j]) + cos(matrix[i][j]) + pow(matrix[i][j], 2);
                    double newValue = matrix[i][j];
                }
            }
        }
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

