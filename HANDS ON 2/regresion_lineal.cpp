#include "regresion_lineal.hpp"
#include <vector> // Asegúrate de que esté aquí o en el .hpp
using namespace std; 

regresionlineal::regresionlineal(vector <double> x, vector <double> y){
    advertising = x;
    sales = y;
    b0 = 0;
    b1 = 1;
}

void regresionlineal::calcularmodelo (){
    // CORRECCIÓN: Era 'int', no 'iint'
    int n = advertising.size(); 
    
    double sumaX = 0;
    double sumaY = 0;
    double sumaX2 = 0;
    double sumaXY = 0;

    for (int i = 0; i < n; i++){
        sumaX += advertising[i];
        sumaY += sales[i];
        sumaX2 += advertising[i] * advertising[i];
        sumaXY += advertising[i] * sales[i];
    }

    // Cálculo de los coeficientes de la regresión
    b1 = (n * sumaXY - sumaX * sumaY) / (n * sumaX2 - sumaX * sumaX);
    b0 = (sumaX2 * sumaY - sumaX * sumaXY) / (n * sumaX2 - sumaX * sumaX);
}

double regresionlineal::predecir (double x){
    return b0 + b1 * x;
}

double regresionlineal::getb0 (){
    return b0;
}

double regresionlineal::getb1 (){
    return b1;
}