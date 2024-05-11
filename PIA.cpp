//ConsoleApplication4.cpp : Este archivo contiene la función "main".La ejecución del programa comienza y termina ahí.
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
void SumaMatrices(double**, double**, int, int, int, int);
void RestaMatrices(double**, double**, int, int, int, int);
void MultiplicaciónMatrices(double**, double**, int, int, int, int);
void PedirPuntos();
void MenuOpe(punto3D*, int);
void operacionesTRSZprp(punto3D*, int, int);
void OperarMatrizTRS(punto3D*, int, double[4][4]);
void TraslacionDeComponentes(punto3D*, double[4][4]);
void EscalacionDeComponentes(double[4][4], punto3D*);
void Zperp(punto3D*, int);
void MemoriaMatrizResultante(double**&, int, int);
void MostrarNuevosPuntos(punto3D*, int);
void RotacionParalela(double, int, punto3D*, double[4][4]);
void RotacionDeComponentes();
void RotacionCuaternios();
void RotacionCompuesta();
void OperarMucho();
void MenuGraficas();
void RectaGraf();
void CircuGraf();
void ElipseGraf();

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
    int npuntos = 0;
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

void MenuOpe(punto3D* puntos, int numpuntos) {

    cout << "¿Qué operación de gustaria realizar con los puntos dados?" << endl;
    cout << "1. Rotación" << endl;
    cout << "2. Traslación" << endl;
    cout << "3. Escalación" << endl;
    cout << "4. Operar varias veces" << endl;
    cin >> opci;

    do {
        switch (opci) {
        case 1: case 2: case 3:
            operacionesTRSZprp(puntos, numpuntos, opci);
            break;
        case 4:
            OperarMucho();
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
        do {
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
            cin >> tiporota;
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
                RotacionParalela(angulo, numpuntos, puntos, matrizope);
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
        } while (tiporota != 1 && tiporota != 2 && tiporota != 3 && tiporota != 4);
        break;
    case 2:
        TraslacionDeComponentes(parametros, matrizope);
        OperarMatrizTRS(puntos, numpuntos, matrizope);
        break;
    case 3:
        EscalacionDeComponentes(matrizope, parametros);
        OperarMatrizTRS(puntos, numpuntos, matrizope);
        break;
    }


}


void OperarMucho() {

}


void RotacionParalela(double angulo, int numpuntos, punto3D* puntos, double matrizope[4][4]) {
    bool unEje = false;
    char eje = '0';
    punto3D* vector = new punto3D[3]; // Creating an array of vectors

    // Asking for user input until a valid axis is selected
    do {
        cout << "Ingrese el primer vector (x,y,z): ";
        cin >> vector[0].x >> vector[0].y >> vector[0].z;
        cout << "Ingrese el segundo vector (x,y,z): ";
        cin >> vector[1].x >> vector[1].y >> vector[1].z;

        // Calculating the direction vector
        vector[2].x = vector[1].x - vector[0].x;
        vector[2].y = vector[1].y - vector[0].y;
        vector[2].z = vector[1].z - vector[0].z;

        // Checking if the direction vector is parallel to any axis
        if ((vector[2].x == 0 && vector[2].y == 0) ||
            (vector[2].x == 0 && vector[2].z == 0) ||
            (vector[2].y == 0 && vector[2].z == 0)) {
            unEje = true;
        }
        else {
            cout << "No se puede operar si no es en un eje" << endl;
        }

    } while (!unEje);

    // Determining the axis of rotation based on the direction vector
    if (vector[2].x != 0) {
        eje = 'x';
    }
    else if (vector[2].y != 0) {
        eje = 'y';
    }
    else if (vector[2].z != 0) {
        eje = 'z';
    }

    cout << "Eje en que se va a rotar: " << eje << endl;
    // Assuming the rest of the code involves the rotation operation using the provided axis and angle
    // You can now continue adapting the code to perform the rotation operation.

    // Don't forget to deallocate dynamically allocated memory
    delete[] vector;
}


void RotacionDeComponentes() {

}

void RotacionCuaternios() {

}

void RotacionCompuesta() {

}

void TraslacionDeComponentes(punto3D* parametros, double matrizope[4][4]) {
    cout << "Ingresa los componentes de traslacion (x, y, z): ";
    cin >> parametros->x >> parametros->y >> parametros->z;
    matrizope[0][3] = parametros->x;
    matrizope[1][3] = parametros->y;
    matrizope[2][3] = parametros->z;
}


void EscalacionDeComponentes(double matrizope[4][4], punto3D* parametros) {
    cout << "Ingresa los componentes de escalacion (x, y, z): ";
    cin >> parametros->x >> parametros->y >> parametros->z;
    matrizope[0][0] = parametros->x;
    matrizope[1][1] = parametros->y;
    matrizope[2][2] = parametros->z;
}

void OperarMatrizTRS(punto3D* puntos, int numpuntos, double matrizope[4][4]) {
    for (int i = 0; i < numpuntos; i++) {
        // Guardar las coordenadas del punto en un vector columna
        double punto[4] = { puntos[i].x, puntos[i].y, puntos[i].z, 1.0 };

        // Multiplicar la matriz operadora por el vector columna del punto
        double nuevopunto[4] = { 0 };
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                nuevopunto[j] += matrizope[j][k] * punto[k];
            }
        }

        // Actualizar las coordenadas del punto con las nuevas coordenadas
        puntos[i].x = nuevopunto[0] / nuevopunto[3];
        puntos[i].y = nuevopunto[1] / nuevopunto[3];
        puntos[i].z = nuevopunto[2] / nuevopunto[3];
    }

    // Llamar a la función para mostrar los nuevos puntos
    MostrarNuevosPuntos(puntos, numpuntos);
}

void MostrarNuevosPuntos(punto3D* puntos, int numpuntos) {
    cout << "Los puntos despues de la operacion ahora son: " << endl;
    for (int i = 0; i < numpuntos; i++)
    {
        cout << "Punto " << i + 1 << " :(" << puntos[i].x << ", " << puntos[i].y << ", " << puntos[i].z << ")" << endl;
    }
    system("pause"); system("cls");
    Zperp(puntos, numpuntos);

}

void Zperp(punto3D* puntos, int numpuntos) {
    double zperp = 0;
    cout << "Favor de ingresar el valor de z" << endl;
    cout << "Tus puntos en z prp son:" << endl;
    for (int i = 0; i < numpuntos; i++)
    {
        double resultZperpX;
        double resultZperpY;
        resultZperpX = puntos[i].x * (zperp / (zperp - puntos[i].z));
        resultZperpY = puntos[i].y * (zperp / (zperp - puntos[i].z));

        //cout << puntos[i].x << " " << puntos[i].y << " " << zprp << " " << resultadoZprpX << " " << resultadoZprpY << endl;
        cout << "Punto: " << i + 1 << " :(" << resultZperpX << ", " << resultZperpY << ")" << endl;
    }
    system("pause");
}

void MenuGraficas() {
    cout << "¿Qué tipo de graficación necesitas? Elige el número del tipo solicitado." << endl;
    cout << endl;
    cout << "1. Recta" << endl;
    cout << "2. Circuferencia" << endl; 
    cout << "3. Elipse" << endl; 
    cout << endl; 
    int tipograf;
    cout << "Graficación a usar: "; cin >> tipograf;
    switch (tipograf) 
    {
    case 1:
        RectaGraf();
        break;
    case 2:
        CircuGraf();
        break;
    case 3:
        ElipseGraf();
        break;
    }
    
}

void RectaGraf() {
    system("cls");
    int x1, y1, x2, y2;
    cout << "Ingresa el punto de inicio (x, y): ";
    cin >> x1 >> y1;
    cout << "Ingresa el punto final (x, y): ";
    cin >> x2 >> y2;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int stepX = (x2 > x1) ? 1 : -1;
    int stepY = (y2 > y1) ? 1 : -1;
    int err = dx - dy;
    int x = x1;
    int y = y1;
    cout << "Mostrando puntos:" << endl;
    cout << "( " << x << ", " << y << " )" << endl;
    while (x != x2 || y != y2) {
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x += stepX;
        }
        if (e2 < dx) {
            err += dx;
            y += stepY;
        }
        cout << "( " << x << ", " << y << " )" << endl;
    }
    system("pause");
    system("cls");
}

void CircuGraf() {
    system("cls");
    int radius = 0, center_x = 0, center_y = 0;
    cout << "Ingrese el radio: ";
    cin >> radius;
    cout << "Ingrese las coordenadas del centro (xc, yc): ";
    cin >> center_x >> center_y;
    int pk0 = 1 - radius;
    int xk[50] = { 0 }, yk[50] = { 0 }, pk[50] = { 0 };
    int indexFinal = 0;
    int prev_x = 0, prev_y = radius, prev_pk = pk0;
    for (int i = 0; i < 50; i++) {
        if (i == 0) {
            xk[i] = 0;
            yk[i] = radius;
            pk[i] = pk0;
        }
        else {
            if (prev_pk < 0) {
                pk[i] = prev_pk + 2 * (prev_x)+3;
                prev_x++;
                xk[i] = prev_x;
                yk[i] = prev_y;
            }
            else if (prev_pk >= 0) {
                pk[i] = prev_pk + 2 * (prev_x)+3 - (2 * (prev_y)-2);
                prev_x++;
                prev_y--;
                xk[i] = prev_x;
                yk[i] = prev_y;
            }
        }
        if (xk[i] >= yk[i]) {
            indexFinal = i;
            break;
        }
        prev_x = xk[i];
        prev_y = yk[i];
        prev_pk = pk[i];
    }
    cout << "Mostrando resultados" << endl;
    int j = 0;
    for (int i = 0; i <= 2 * (indexFinal); i++) {
        if (i > indexFinal) {
            j++;
            xk[i] = yk[(indexFinal - j)];
            yk[i] = xk[(indexFinal - j)];
        }
        cout << "( " << xk[i] << ", " << yk[i] << " ) \t ( " << xk[i] + center_x << ", " << yk[i] + center_y << " )" << endl;
    }
    system("pause");
    system("cls");
}

void ElipseGraf() {
    system("cls");
    int radius_x = 0, radius_y = 0, center_x = 0, center_y = 0;
    cout << "Ingrese el radio de x: ";
    cin >> radius_x;
    cout << "Ingrese el radio de y: ";
    cin >> radius_y;
    cout << "Ingrese las coordenadas del centro ( xc, yc ): ";
    cin >> center_x >> center_y;
    int pk0 = (radius_y * radius_y) - (radius_x * radius_x) * (radius_y)+((radius_x * radius_x) / 4);
    int xk[100] = { 0 }, yk[100] = { 0 }, pk[100] = { 0 };
    int prev_x = 0, prev_y = 0, prev_pk = 0;
    prev_y = radius_y;
    prev_pk = pk0;
    for (int i = 0; i < 100; i++) {
        if (i == 0) {
            pk[i] = pk0;
            xk[i] = prev_x;
            yk[i] = prev_y;
        }
        else {
            if (prev_pk < 0) { // ( xk + 1, yk )
                pk[i] = prev_pk + (2 * (radius_y * radius_y) * prev_x + 2 * (radius_y * radius_y)) + (radius_y * radius_y);
                prev_x++;
                xk[i] = prev_x;
                yk[i] = prev_y;
            }
            else if (prev_pk >= 0) { // ( xk + 1, yk - 1 )
                pk[i] = prev_pk + (2 * (radius_y * radius_y) * prev_x + 2 * (radius_y * radius_y)) - (2 * (radius_x * radius_x) * prev_y - 2 * (radius_x * radius_x)) + (radius_y * radius_y);
                prev_x++;
                prev_y--;
                xk[i] = prev_x;
                yk[i] = prev_y;
            }
        }
        int two_ry2x = 2 * (radius_y * radius_y) * xk[i];
        int two_rx2y = 2 * (radius_x * radius_x) * yk[i];
        prev_x = xk[i];
        prev_y = yk[i];
        prev_pk = pk[i];
        if (two_ry2x >= two_rx2y) {
            break;
        }
    }
    cout << "Mostrando resultados" << endl;
    for (int i = 0; i < 100; i++) {
        if (yk[i] == 0) break;
        cout << "( " << xk[i] << ", " << yk[i] << " ) \t ( " << xk[i] + center_x << ", " << yk[i] + center_y << " )" << endl;
    }
    system("pause");
    system("cls");
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
        cout << "4. Operaciones diversas (Rotación, Traslación, Escalación, Zprp, Matrices Compuestas)" << endl;
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
