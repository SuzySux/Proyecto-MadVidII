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
void BorrarMatrices();
void GenerarMatriz(int op);
void IngresoMatriz();
void SumaMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2);
void RestaMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2);
void MultiplicaciónMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2);
void PedirPuntos();

// Declarar funciones globales
double** p_mat1;
double** p_mat2;
int c1 = 0;
int c2 = 0;
int f1 = 0;
int f2 = 0;
int op = 0;


void GenerarMatriz(int op)
{
    do {
        cout << "Favor de ingresar el número de columnas de su matriz. El máximo es de 10 y el minímo es de 1" << endl;
        cin >> c1;

        if ((c1 < 1) || (c1 > 10)) {

            cout << "error en el numero ingresado" << endl;
        }

    } while ((c1 < 1) || (c1 > 10));


    do {
        cout << "Favor de ingresar el número de filas de su matriz. El máximo es de 10 y el minímo es de 1" << endl;
        cin >> f1;


        if ((f1 < 1) || (f1 > 10)) {

            cout << "error en el numero ingresado" << endl;
        }

    } while ((f1 < 1) || (f1 > 10));

    do {
        cout << "Favor de ingresar el número de columnas de su matriz. El máximo es de 10 y el minímo es de 1" << endl;
        cin >> c2;

        if ((c2 < 1) || (c2 > 10)) {

            cout << "error en el numero ingresado" << endl;
        }

    } while ((c2 < 1) || (c2 > 10));


    do {
        cout << "Favor de ingresar el número de filas de su matriz. El máximo es de 10 y el minímo es de 1" << endl;
        cin >> f2;

        if ((f2 < 1) || (f2 > 10)) {

            cout << "error en el numero ingresado" << endl;
        }

    } while ((f2 < 1) || (f2 > 10));

    switch (op) {
    case 1:
        if (f1 != f2 || c1 != c2) {
            cout << "Tus matrices cuentan con dimensiones imposibles de restar. Favor de ingresar matrices distintas" << endl;
            GenerarMatriz(op);
        }
        break;
    case 2:
        do {
            cout << "Tus matrices cuentan con dimensiones imposibles de restar. Favor de ingresar matrices distintas" << endl;
            GenerarMatriz(op);
        } while (f1 != f2 || c1 != c2);

        break;
    case 3:
        do {
            cout << "Tus matrices cuentan con dimensiones imposibles de multiplicar. Favor de ingresar matrices distintas" << endl;
            GenerarMatriz(op);
        } while (f1 != f2);
        break;
    }

    //se asigna memoria a las matrices
    p_mat1 = new double* [f1]; //Asignando memoria para las filas de la primer matriz
    for (int i = 0; i < f1; i++) {
        p_mat1[i] = new double[c1]; //Asignando memoria para las columnas de la primer matriz 
    }
    p_mat2 = new double* [f2]; //Filas segunda matriz
    for (int i = 0; i < f2; i++) {
        p_mat2[i] = new double[c2]; //Columnas segunda matriz 
    }

    IngresoMatriz();
}

void IngresoMatriz()
{

    //Ingreso de matrices
    cout << "Ingrese los elementos de la primera matriz:" << endl;
    for (int i = 0; i < f1; ++i) {
        for (int j = 0; j < c1; ++j) {
            cin >> p_mat1[i][j];
        }
    }
    cout << "Ingrese los elementos de la segunda matriz:" << endl;
    for (int i = 0; i < f2; ++i) {
        for (int j = 0; j < c2; ++j) {
            cin >> p_mat2[i][j];
        }
    }
    switch (op) {
    case 1:
        system("cls");
        SumaMatrices( p_mat1, p_mat2, c1, c2, f1, f2);
        break;
    case 2:
        system("cls");
        RestaMatrices(p_mat1, p_mat2, c1, c2, f1, f2);
        break;
    case 3:
        system("cls");
        MultiplicaciónMatrices(p_mat1, p_mat2, c1, c2, f1, f2);
        break;
    }
}


void SumaMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2)
{
  
}

void RestaMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2) {}
void MultiplicaciónMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2) {}

void BorrarMatrices(){
    for (int i = 0; i < f1; i++) {
    delete[] p_mat1[i];
}
delete[] p_mat1;

for (int i = 0; i < f2; i++) {
    delete[] p_mat2[i];
}
delete[] p_mat2;
}

void PedirPuntos() {

}


using namespace std;



int main()
{

    system("cls");
    cout << "Bienvenido a la calculadora de matrices, contamos con las siguientes opciones:" << endl;
    cout << endl;
    cout << " === MENÚ PRINCIPAL ===" << endl;
    cout << "1. Suma de matrices" << endl;
    cout << "2. Resta de matrices" << endl;
    cout << "3. Multiplicación de matrices" << endl;
    cout << "4. Operaciones complejas (Rotación, Traslación y Z perspectiva)" << endl;
    cout << "5. Graficación" << endl;
    cout << "6. Salir" << endl;
    cout << endl;
    cout << "Favor de elegir la opción deseada: ";
    cin >> op;

    do {
        switch (op) {
        case 1:
            system("cls");
            GenerarMatriz(op);
            break;
        case 2:
            system("cls");
            GenerarMatriz(op);
            break;
        case 3:
            system("cls");
            GenerarMatriz(op);
            break;
        case 4:
            system("cls");
            PedirPuntos();
            break;
        case 5:
            system("cls");
            // Implementa la función de graficación aquí
            break;
        case 6:
            system("cls");
            cout << "¿Estás seguro de salir? Presiona 1 para salir y 2 para volver al menú: ";
            int sali;
            cin >> sali;

            if (sali == 1) {
                cout << "Saliendo del programa..." << endl;
                return 0;
            }
            else if (sali == 2) {
                break;
            }
            else {
                cout << "Opción no válida. Presiona 1 para salir y 2 para volver al menú: ";
            }
            break;
        default:
            cout << "[!] Opción no válida. Por favor, ingrese una opción válida. [!]" << endl;
            cin.ignore();
            cin >> op;
            break;
        }
    } while (op != 7);

    return 0;
}


