#include "frecuenciaextendida.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

frecuenciaextendida::frecuenciaextendida (vector <double> d){
    datos = d;
    N = datos.size();

    if(N == 0){
        cout << "Error: no hay datos\n";
    }
}

void frecuenciaextendida::calcularclase (){

    minimo = datos[0];
    maximo = datos[0];

    for (double v:datos){
        if (v < minimo) minimo = v;
        if (v > maximo) maximo = v;
    }

    K = round(1 + 3.322 * log10(N));
    amplitud = ceil((maximo - minimo) / K);

    limiteinferior.resize(K);
    limitesuperior.resize(K);
    puntomedio.resize(K);
    f.resize(K,0);
    fa.resize(K,0);
    fr.resize(K,0);
    fra.resize(K,0);

    double li = minimo;

    for (int i = 0; i < K; i++){
        limiteinferior[i] = li;
        limitesuperior[i] = li + amplitud;
        puntomedio[i] = (limiteinferior[i] + limitesuperior[i]) / 2;
        li += amplitud;
    }
}

void frecuenciaextendida::calcularfrecuencia (){

    for (double v:datos){
        for (int i = 0; i < K; i++){
            if ((v >= limiteinferior[i] && v < limitesuperior[i]) 
                || (i == K-1 && v == maximo)){
                f[i]++;
                break;
            }
        }
    }

    int acumulada = 0;
    double acumuladareal = 0;

    for (int i = 0; i < K; i++){
        acumulada += f[i];
        fa[i] = acumulada;

        fr[i] = (double) f[i] / N;
        acumuladareal += fr[i];
        fra[i] = acumuladareal;
    }
}

void frecuenciaextendida::imprimirtabla(){

    cout << "Clase\tLimites\t\tf\tXc\tFa\tfr\tFra\t%\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < K; i++){
        cout << i+1 << "\t"
             << limiteinferior[i] << "-" << limitesuperior[i] << "\t"
             << f[i] << "\t"
             << puntomedio[i] << "\t"
             << fa[i] << "\t"
             << fr[i] << "\t"
             << fra[i] << "\t"
             << fr[i] * 100 << "%\n";
    }

    cout << "Total\t\t" << N << "\t\t\t\t1.00\t1.00\t100%\n";
}

double frecuenciaextendida::media(){
    double suma = 0;

    for(int i = 0; i < K; i++){
        suma += f[i] * puntomedio[i];
    }

    return suma / N;
}

double frecuenciaextendida::mediana(){
    double mitad = N / 2.0;
    int i;

    for(i = 0; i < K; i++){
        if(fa[i] >= mitad) break;
    }

    double L = limiteinferior[i];
    double F_anterior = (i == 0) ? 0 : fa[i-1];
    double fm = f[i];

    return L + ((mitad - F_anterior) / fm) * amplitud;
}

double frecuenciaextendida::moda(){
    int modal = 0;

    for(int i = 1; i < K; i++){
        if(f[i] > f[modal]) modal = i;
    }

    double L = limiteinferior[modal];
    double d1 = f[modal] - (modal == 0 ? 0 : f[modal-1]);
    double d2 = f[modal] - (modal == K-1 ? 0 : f[modal+1]);

    if(d1 + d2 == 0) return L; 

    return L + (d1 / (d1 + d2)) * amplitud;
}