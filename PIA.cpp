// ConsoleApplication4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#define _USE_MATH_DEFINES 
#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<math.h>
#include <cstdlib> // Para system("cls")

using namespace std;

struct punto3D {
    double x;
    double y;
    double z;
};

// Prototipos de funciones
void IngresoMatriz();
void SumaMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2);
void RestaMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2);
void MultiplicaciónMatrices(double** p_mat1, double** p_mat2, int c1, int c2, int f1, int f2);
void PedirPuntos();
void MenuOpe(punto3D* puntos, int numpuntos);
void operacionesTRSZprp(punto3D* puntos, int numpuntos, int opci);   
void OperarMatrizTRS(punto3D* puntos, int numpuntos, double matrizope[4][4]);
void TraslacionDeComponentes(punto3D* parametros, double matrizope[4][4]);
void EscalacionDeComponentes(punto3D* parametros);
void MemoriaMatrizResultante(double**& p_resultado, int filas, int columnas); 
void MenuGraficas();

// Declarar funciones globales
double** p_mat1;
double** p_mat2;
int c1 = 0;
int c2 = 0;
int f1 = 0;
int f2 = 0;  
int op = 0;
int opci = 0; 



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
    switch (desci) {
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
        system("cls");
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
    float npuntos = 0; 
    do {
        cout << "Favor de ingresar la cantidad de puntos a trabajar: ";
        cin >> npuntos; 
    } while (npuntos % 1 != 0); 
    cout << endl;  
    int numpuntos = npuntos;  
    punto3D* puntos = new punto3D[numpuntos];    

    //Leer puntos
    for (int i = 0; i < numpuntos; i++) { 
        cout << "Ingresa las coordenadas del punto (no uses comas o espacios, separalas danto 'enter') " << i + 1 << " (x, y, z): "; 
        cin >> puntos[i].x >> puntos[i].y >> puntos[i].z; 
    }

    system("pause");
    MenuOpe(puntos, numpuntos); 
    delete[] puntos;  //liberando la memoria
   
}

void MenuOpe(punto3D*puntos, int numpuntos) {
    
    cout << "¿Qué operación de gustaria realizar con los puntos dados?" << endl;
    cout << "1. Rotación" << endl;
    cout << "2. Traslación" << endl;
    cout << "3. Escalación" << endl;
    cout << "4. Operar varias veces" << endl;
    cin >> opci; 
   
    do {
        switch (opci) {
        case 1: case 2: case 3:
            operacionesTRSZprp(puntos, numpuntos);
            break;
        case 4:
            OperarMucho(puntos, numpuntos);
            break;
        default:
            cout << "Favor de elegir una opción valida" << endl;
            system("cls");
        }
    } while (opci != 1 && opci != 2 && opci != 3 && opci != 4);  
    system("cls");

}
void operacionesTRSZprp(punto3D* puntos, int numpuntos, int opci) {   
    int tiporota = 0;
    double angulo = 0;
    double matrizope[4][4]{};
    char tecla = 0; 

    for (int i = 0; i < 4; i++) { //Matriz identidad
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                matrizope[i][j] = 1;   
            }
            else {
                matrizope[i][j] = 0;  
            }
        }
    }
    punto3D* parametros = new punto3D;   

    switch (opci)
    {
    case 1:
        do{
        system("cls");
        cout << "---ROTACIÓN---" << endl;
        cout << "Favor de ingresar su angulo:";
        cin >> angulo;  
        cout << endl;
        cout << "Favor de ingresar tu tipo de rotación. Contamos con los siguientes";
        cout << "1. Rotación por matriz de rotación" << endl;
        cout << "2. Rotación paralela a un eje" << endl;
        cout << "3. Rotación por cuaternios" << endl;
        cout << "4. Rotación por matriz por matriz compuesta" << endl;
        cin << tiporota;
        cout << endl;

        switch (tiporota) {
        case 1:
            cout << "Tu angulo a rotar es: " << angulo << ", y tu tipo de rotación es: " << tiporota << endl;
            angulo = angulo * (M_PI / 180); //Angulo en radianes 
            cout << "Ingresa cualquier tecla para continuar";
            cin >> tecla; 
            system("cls");
            RotacionDeComponentes(); 
            OperarMatrizTRS(puntos, numpuntos, matrizope);
            break;

        case 2:
            cout << "Tu angulo a rotar es: " << angulo << ", y tu tipo de rotación es: " << tiporota << endl;
            angulo = angulo * (M_PI / 180); //Angulo en radianes
            cout << "Ingresa cualquier tecla para continuar";
            cin >> tecla; 
            system("cls");
            RotacionParalela();
            break;

        case 3:
            cout << "Tu angulo a rotar es: " << angulo << ", y tu tipo de rotación es: " << tiporota << endl;
            angulo = angulo * (M_PI / 180); //Angulo en radianes
            cout << "Ingresa cualquier tecla para continuar";
            cin >> tecla;  
            system("cls");
            RotacionCuaternios();
            break;

        case 4:
            cout << "Tu angulo a rotar es: " << angulo << ", y tu tipo de rotación es: " << tiporota << endl;
            angulo = angulo * (M_PI / 180); //Angulo en radianes
            cout << "Ingresa cualquier tecla para continuar";
            cin >> tecla; 
            system("cls");
            RotacionCompuesta(); 
            break;
        default:
            cout << "Parece que no ingresaste un tipo de rotación correcta. Favor de ingresar una rotación correcta. ";

        }
        } while (tiporota != 1 && tiporota != 2 && tiporota != 3 && tiporota != 4) 
    break;
    case 2:
        TraslacionDeComponentes(parametros, matrizope);
        OperarMatrizTRS(puntos, numpuntos, matrizope);
        break;
    case 3:
        EscalacionDeComponentes(parametros);
        OperarMatrizTRS(puntos, numpuntos, matrizope);
        break;
    }
  

}
void OperarMucho() {

}
void MenuGraficas() {
}

void RotacionDeComponentes() {

}

void RotacionParalela() {

}

void RotacionCuaternios() {

}
void RotacionCompuesta() {

}

void OperarMatrizTRS(punto3D* puntos, int numpuntos, double matrizope[4][4]) {

}

static void TraslacionDeComponentes(double matrizope[4][4], punto3D* parametros) {
    double matriz[4][4]{}; 
    double** matrizContenedor, ** matriz1, ** matriz2;

    matrizContenedor = new double* [4];	matriz1 = new double* [4];	matriz2 = new double* [4]; 
    for (int i = 0; i < 4; i++) { //Haciendo la matriz identidad
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                matriz[i][j] = 1;
            }
            else {
                matriz[i][j] = 0;
            }
        }
    }

    cout << "Ingresa los componentes de traslacion (x, y, z): "; cin >> parametros->x >> parametros->y >> parametros->z;
    matrizope[0][3] = parametros->x;
    matrizope[1][3] = parametros->y;
    matrizope[2][3] = parametros->z;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matriz2[i][j] = matriz[i][j];

        }
    }
    cout << "Matriz guardada con exito";
    //productoMatriz(matrizContenedor, identidad, matriz2, 4, 4, 4, 4);
    delete[] matrizContenedor;
    delete[] matriz1;
    delete[] matriz2;
}


void EscalacionDeComponentes(punto3D* parametros) {
    double matriz[4][4]{};
    double** matrizContenedor,** matriz3, ** identidad;
    matrizContenedor = new double* [4]; matriz3 = new double* [4]; identidad = new double* [4];

    for (int i = 0; i < 4; i++) { //Haciendo la matriz identidad
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                matriz[i][j] = 1;
            }
            else {
                matriz[i][j] = 0;
            }
        }
    }

    cout << "Ingresa los componentes de escalacion (x, y, z): "; cin >> parametros->x >> parametros->y >> parametros->z;
    matriz[0][0] = parametros->x;
    matriz[1][1] = parametros->y;
    matriz[2][2] = parametros->z;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matriz3[i][j] = matriz[i][j];

        }
    }
    //productoMatriz(matrizContenedor, identidad, matriz3, 4, 4, 4, 4);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            identidad[i][j] = matrizContenedor[i][j];
            matriz[i][j] = matrizContenedor[i][j];
        }
    }

    cout << "Matriz guardada con exito";
    //mostrarResultado(matrizContenedor, 4, 4);
    //productoMatriz(matrizContenedor, identidad, matriz3, 4, 4, 4, 4);
    delete[] matrizContenedor;
    delete[] matriz3;
    delete[] identidad;
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
        cout << "4. Operaciones diversas (Rotación, Traslación, Escalación, Zprp, Matrices Compuestas)"<< endl;
        cout << "5. Graficacion de Bresenham" << endl;
        cout << "6. Salir" << endl;
        cout << "Opción: ";
        cin >> op;   

        switch (op) {  
        case 1:
        case 2:
        case 3:
            IngresoMatriz();
            
            break;
        case 4:
            PedirPuntos();
            
            break;
        case 5:
            MenuGraficas();
           
            break;
        case 6:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, elige una opción válida." << endl;
            system("cls");  
            break;
        }
    } while (op != 6);

    return 0;
}
