#include<iostream>
#include<vector>
#include "regresion_lineal.hpp"

using namespace std;
int main (){
    vector <double> advertasing = {23,26,30,34,43,48,52,57,58};
    vector <double> sales = {651,762,856,1063,1190,1298,1421,1440,1518};
    regresionlineal modelo (advertasing, sales);
    modelo.calcularmodelo();
    cout << "Ecuacion de regresion: " << endl;
    cout << "Sales = " << modelo.getb0 () << " + " << modelo.getb1 () << " * advertasing  " << endl; 
    cout << endl;
    cout << "Prediccion " << endl;
    vector <double> nuevoadvertasing = {60,65,70,80,90};

    for (double x : nuevoadvertasing){
        cout << "advertasing: " << x <<"--> sales: " << modelo.predecir (x) << endl;


    
    
  
    }
    return 0;

}