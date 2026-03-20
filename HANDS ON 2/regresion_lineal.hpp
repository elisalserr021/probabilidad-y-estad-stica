#ifndef REGRESION_LINEAL_HPP
#define REGRESION_LINEAL_HPP

#include <vector>
using namespace std;

class regresionlineal {
    vector<double> advertising;
    vector<double> sales;
    double b0, b1;

public:
    regresionlineal(vector<double> x, vector<double> y);
    void calcularmodelo();
    double predecir(double x);
    double getb0();
    double getb1();
};

#endif



 