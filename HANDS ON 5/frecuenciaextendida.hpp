#ifndef FRECUENCIAEXTENDIDA_HPP
#define FRECUENCIAEXTENDIDA_HPP
#include <vector>
#include <string>

using namespace std;
 
class frecuenciaextendida{
private:
    vector <double> datos;
    int N;
    int K;
    double minimo;
    double maximo;
    double amplitud;

    vector <double> limiteinferior;
    vector <double> limitesuperior;
    vector <double> puntomedio;
    vector <int> f;
    vector <int> fa;
    vector <double> fr;
    vector <double> fra;

public:
    frecuenciaextendida(vector <double>);

    void calcularclase ();
    void calcularfrecuencia(); 
    void imprimirtabla();

    double media();
    double mediana();
    double moda();
};
#endif