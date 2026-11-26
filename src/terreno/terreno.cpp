#include "terreno.h"

Terreno::Terreno(int n){
    n_tamanho = n;
    tamanhoReal = std::pow(2,n_tamanho) + 1;
    matriz = new double*[tamanhoReal];
    for (int i = 0; i < tamanhoReal; i++){
        matriz[i] = new int[tamanhoReal];
    }
    for(int i = 0; i < tamanhoReal; i++){
        for (int j = 0; j < tamanhoReal; j++){
            matriz[i][j] = 0;
        }
    }
}

Terreno::~Terreno(){
    for(int i = 0; i < tamanhoReal; i++){
        delete[] matriz[i];
    }
    delete[] matriz;
}

