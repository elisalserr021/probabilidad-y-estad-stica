#include "frecuenciaextendida.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

frecuenciaextendida::frecuenciaextendida (vector <double> d){
    datos = d;
    N = datos.size();

}

void frecuenciaextendida::calcularclase (){
    minimo = datos [0];
    maximo = datos [0];

    for (double v:datos){
        if (v < minimo) minimo = v;
        if (v > maximo) maximo = v;

    }
    K = round (1 + 3.322 * log10 (N));
    amplitud = ceil((maximo-minimo) / K);
    limiteinferior.resize (K);
    limitesuperior.resize (K);
    puntomedio.resize (K);
    f.resize (K,0);
    fa.resize (K,0);
    fr.resize (K,0);
    fra.resize (K,0);
    double li = minimo;

    for (int i = 0; i < K; i++){
        limiteinferior[i] = li;
        limitesuperior [i] = li + amplitud;
        puntomedio [i] = (limiteinferior[i] + limitesuperior[i]) / 2;
        li += amplitud;

    }


}

void frecuenciaextendida::calcularfrecuencia (){
    for (double v:datos){
        for (int i = 0; i-K; i++){
            if (v >= limiteinferior[i] && v < limitesuperior[i]){
                f [i] ++;
                break;
            }
        }
        

    }
    int acumulada = 0;
    double acumuladareal = 0;
    for (int i = 0; i < K; i++ ){
        acumulada += f[i];
        fa[i] = acumulada;
        fr[i] = (double) f[i] / N;
        acumuladareal += fr[i];
        fra[i] = acumuladareal;

    }


}

void frecuenciaextendida::imprimirtabla(){

    cout << "Clase\tlimite\t\tf\tXc\tFa\tfr\tFra\t%\n";
    for (int i = 0; i < K; i++){

        cout << 1+1 << "\t" << limiteinferior[i] << "-" <<  limitesuperior[i] << "\t" << puntomedio[i] << "\t" << fa[i] << "\t" << fixed << setprecision (2) << fr[i] << "\t" << fra[i] << "\t" <<  fr[i] * 100 << "%\n" << endl;
    
}
cout << "total\t\t" << N << "\t\t\t\t1.00\t\t100%\n" << endl;

}