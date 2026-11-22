#include "imagem.h"
#include <fstream>

Imagem::Imagem(){
    larguraMatriz = 10;
    alturaMatriz = 10;
    matrizPixeis = new Pixel*[larguraMatriz];
    for (int i = 0; i < larguraMatriz; i++){
        matrizPixeis[i] = new Pixel[alturaMatriz];
    }
}

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


bool Imagem::lerPPM(std::string nomeArquivo){
    std::ifstream file(nomeArquivo);
    if (!file.is_open()){
        return false;
    }
    std::string magico;
    int altura_arquivo, largura_arquivo, maxval;
    file >> magico >> largura_arquivo >> altura_arquivo >> maxval;


    if (!file || magico != "P3"){
        return false;
    }

    for(int i = 0; i < larguraMatriz; i++){
        delete[] matrizPixeis[i];
    }
    delete[] matrizPixeis;
    larguraMatriz = largura_arquivo;
    alturaMatriz = altura_arquivo;
    matrizPixeis = new Pixel*[larguraMatriz];
    for (int i = 0; i < larguraMatriz; i++){
        matrizPixeis[i] = new Pixel[alturaMatriz];
    }



    
    for (int i = 0; i < alturaMatriz; i++){
        for (int j = 0; j < larguraMatriz; j++){
            file >> matrizPixeis[j][i].r >> matrizPixeis[j][i].g >> matrizPixeis[j][i].b;
            
        }
    }
    return true;
}