#include <iostream>
#include <vector>
#include "frecuenciaextendida.hpp"

using namespace std;
int main(){

    vector <double> Dataset = {25,28,30,32,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,68,70,72,74,76,27,33,41,59,67};
    frecuenciaextendida tabla(Dataset);
    tabla.calcularclase ();
    tabla.calcularfrecuencia ();
    tabla.imprimirtabla ();

    return 0;
}