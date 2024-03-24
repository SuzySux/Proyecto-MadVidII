// ConsoleApplication4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#define _USE_MATH_DEFINES 
#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<math.h>
#include <cstdlib> // Para system("cls")

using namespace std;
// Prototipos de funciones

void IngresoMatriz();
void SumaMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2);
void RestaMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2);
void MultiplicaciónMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2);
void PedirPuntos();
void MemoriaMatrizResultante(double**& p_resultado, int filas, int columnas);

// Declarar funciones globales
double** p_mat1;
double** p_mat2;
int c1 = 0;
int c2 = 0;
int f1 = 0;
int f2 = 0;
int op = 0;


void IngresoMatriz() {
    cout << "Favor de ingresar el número de columnas de la primer matriz: ";
    cin >> c1;

    cout << "Favor de ingresar el número de filas de la primer matriz: ";
    cin >> f1;

    cout << "Favor de ingresar el número de columnas de la segunda matriz: ";
    cin >> c2;

    cout << "Favor de ingresar el número de filas de la segunda matriz: ";
    cin >> f2;

    // Se asigna memoria para las matrices
    p_mat1 = new double* [f1];
    for (int i = 0; i < f1; i++)
        p_mat1[i] = new double[c1];

    p_mat2 = new double* [f2];
    for (int i = 0; i < f2; i++)
        p_mat2[i] = new double[c2];

    // Ingreso de matrices
    cout << "Ingrese los elementos de la primera matriz:" << endl;
    for (int i = 0; i < f1; ++i) {
        for (int j = 0; j < c1; ++j) {
            cout << "Elemento (" << i << ", " << j << "): ";
            cin >> p_mat1[i][j];
        }
    }

    cout << "Ingrese los elementos de la segunda matriz:" << endl;
    for (int i = 0; i < f2; ++i) {
        for (int j = 0; j < c2; ++j) {
            cout << "Elemento (" << i << ", " << j << "): ";
            cin >> p_mat2[i][j];
        }
    }

    // Se realiza la operación seleccionada
    switch (op) {
    case 1:
        SumaMatrices(p_mat1, p_mat2, c1, c2, f1, f2);
        break;
    case 2:
        RestaMatrices(p_mat1, p_mat2, c1, c2, f1, f2);
        break;
    case 3:
        MultiplicaciónMatrices(p_mat1, p_mat2, c1, c2, f1, f2); 
        break;
    }

    // Se libera la memoria de las matrices
    for (int i = 0; i < f1; i++)
        delete[] p_mat1[i];
    delete[] p_mat1;

    for (int i = 0; i < f2; i++)
        delete[] p_mat2[i];
    delete[] p_mat2;
}

void SumaMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2)
{
    // Verificar si las matrices tienen dimensiones compatibles para la suma
    if (c1 != c2 || f1 != f2) {
        cout << "No se pueden sumar matrices con dimensiones diferentes." << endl;
        return;
    }

    // Asignar memoria para la matriz resultante
    double** p_resultado = nullptr;
    MemoriaMatrizResultante(p_resultado, f1, c1);

    // Realizar la suma de matrices y almacenar el resultado en p_resultado
    for (int i = 0; i < f1; ++i) {
        for (int j = 0; j < c1; ++j) {
            p_resultado[i][j] = p_mat1[i][j] + p_mat2[i][j];
        }
    }

    // Mostrar la matriz resultado 
    cout << "Resultado de la suma de matrices:" << endl;
    for (int i = 0; i < f1; ++i) {
        for (int j = 0; j < c1; ++j) {
            cout << p_resultado[i][j] << " ";
        }
        cout << endl;
    }

    // Liberar la memoria asignada para la matriz resultado
    for (int i = 0; i < f1; ++i) {
        delete[] p_resultado[i];
    }
    delete[] p_resultado;

    cout << "¿Desea volver al inicio o salir del programa?" << endl;
    cout << "En caso de querer volver presionar 1, en caso de querer salir presionar 2" << endl;
    int desci = 0;
    cin >> desci;
    switch (desci){
    case 1:
        return;
        break;
    case 2: 
        exit(0);
        break;
    }
}


void RestaMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2) {
    
    // Verificar si las matrices tienen dimensiones compatibles para la resta
    if (c1 != c2 || f1 != f2) {
        cout << "No se pueden restar matrices con dimensiones diferentes." << endl;
        return;
    }

    // Asignar memoria para la matriz resultante
    double** p_resultado = nullptr;
    MemoriaMatrizResultante(p_resultado, f1, c1);

    // Realizar la resta de matrices y almacenar el resultado en p_resultado
    for (int i = 0; i < f1; ++i) {
        for (int j = 0; j < c1; ++j) {
            p_resultado[i][j] = p_mat1[i][j] - p_mat2[i][j];
        }
    }

    // Mostrar la matriz resultado 
    cout << "Resultado de la resta de matrices:" << endl;
    for (int i = 0; i < f1; ++i) {
        for (int j = 0; j < c1; ++j) {
            cout << p_resultado[i][j] << " ";
        }
        cout << endl;
    }

    // Liberar la memoria asignada para la matriz resultado
    for (int i = 0; i < f1; ++i) {
        delete[] p_resultado[i];
    }
    delete[] p_resultado;


    cout << "¿Desea volver al inicio o salir del programa?" << endl;
    cout << "En caso de querer volver presionar 1, en caso de querer salir presionar 2" << endl;
    int desci = 0;
    cin >> desci;
    switch (desci) {
    case 1:
        return;
        break;
    case 2:
        exit(0);
        break;
    }
}

void MultiplicaciónMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2) 
{
    // Verificar si las matrices tienen dimensiones compatibles para la multiplicación
    if (c1 != f2) {
        cout << "El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz." << endl;
        return;
    }

    // Asignar memoria para la matriz resultante
    double** p_resultado = nullptr;
    MemoriaMatrizResultante(p_resultado, f1, c2);

    // Realizar la multiplicación de matrices y almacenar el resultado en p_resultado
    for (int i = 0; i < f1; ++i) {
        for (int j = 0; j < c2; ++j) {
            p_resultado[i][j] = 0;
            for (int k = 0; k < c1; ++k) {
                p_resultado[i][j] += p_mat1[i][k] * p_mat2[k][j];
            }
        }
    }

    // Mostrar la matriz resultado 
    cout << "Resultado de la multiplicación de matrices:" << endl;
    for (int i = 0; i < f1; ++i) {
        for (int j = 0; j < c2; ++j) {
            cout << p_resultado[i][j] << " ";
        }
        cout << endl;
    }

    // Liberar la memoria asignada para la matriz resultado
    for (int i = 0; i < f1; ++i) {
        delete[] p_resultado[i];
    }
    delete[] p_resultado;

    cout << "¿Desea volver al inicio o salir del programa?" << endl;
    cout << "En caso de querer volver presionar 1, en caso de querer salir presionar 2" << endl;
    int desci = 0;
    cin >> desci;
    switch (desci) {
    case 1:
        return;
        break;
    case 2:
        exit(0);
        break;
    }
}

void MemoriaMatrizResultante(double**& p_resultado, int filas, int columnas) {
    // Liberar memoria previa si existe
    if (p_resultado != nullptr) {
        for (int i = 0; i < filas; ++i) {
            delete[] p_resultado[i];
        }
        delete[] p_resultado;
    }

    // Asignar nueva memoria
    p_resultado = new double* [filas];
    for (int i = 0; i < filas; ++i) {
        p_resultado[i] = new double[columnas];
    }
}


void PedirPuntos() {

}


using namespace std;



int main()
{

    system("cls");
    cout << "Bienvenido a la calculadora de matrices, contamos con las siguientes opciones:" << endl;
    cout << endl;
    do {
        cout << "Elige una opción:" << endl;
        cout << "1. Suma de matrices" << endl;
        cout << "2. Resta de matrices" << endl;
        cout << "3. Multiplicación de matrices" << endl;
        cout << "4. Salir" << endl;
        cout << "Opción: ";
        cin >> op;

        switch (op) {
        case 1:
        case 2:
        case 3:
            IngresoMatriz();
            break;
        case 4:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, elige una opción válida." << endl;
            break;
        }
    } while (op != 4);

    return 0;
}
