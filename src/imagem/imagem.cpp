#include "imagem.h"

Imagem::Imagem(int largura, int altura){
    larguraMatriz = largura;
    alturaMatriz = altura;
    matrizPixeis = new Pixel*[largura];
    for (int i = 0; i < largura; i++){
        matrizPixeis[i] = new Pixel[altura];
    }

}

Imagem::~Imagem(){
    for(int i = 0; i < larguraMatriz; i++){
        delete[] matrizPixeis[i];
    }
    delete[] matrizPixeis;
}

int Imagem::obterLargura(){
    return larguraMatriz;
}

int Imagem::obterAltura(){
    return alturaMatriz;
}

Pixel Imagem:: obterPixel(int x, int y){
    return matrizPixeis[x][y];
}

void Imagem::definePixel(int x, int y, Pixel cor){
    matrizPixeis[x][y] = cor;
}