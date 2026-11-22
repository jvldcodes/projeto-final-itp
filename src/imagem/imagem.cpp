#include "imagem.h"
#include <fstream>

Imagem::Imagem(){
    // Default size of 10x10
    larguraMatriz = 10;
    alturaMatriz = 10;
    // Allocate one array of columns
    matrizPixeis = new Pixel*[larguraMatriz];
    // Allocate the pixels of each column
    for (int i = 0; i < larguraMatriz; i++){
        matrizPixeis[i] = new Pixel[alturaMatriz];
    }
}

Imagem::Imagem(int largura, int altura){
    // Build a black image with the given size
    larguraMatriz = largura;
    alturaMatriz = altura;
    matrizPixeis = new Pixel*[largura];
    for (int i = 0; i < largura; i++){
        matrizPixeis[i] = new Pixel[altura];
    }

}

Imagem::~Imagem(){
    // Give the allocated memory back
    for(int i = 0; i < larguraMatriz; i++){
        delete[] matrizPixeis[i];
    }
    delete[] matrizPixeis;
}

int Imagem::obterLargura(){
    // Number of columns
    return larguraMatriz;
}

int Imagem::obterAltura(){
    // Number of rows
    return alturaMatriz;
}

Pixel Imagem:: obterPixel(int x, int y){
    // Return the pixel stored at column x, row y
    return matrizPixeis[x][y];
}

void Imagem::definePixel(int x, int y, Pixel cor){
    // Store the given color at column x, row y
    matrizPixeis[x][y] = cor;
}


bool Imagem::lerPPM(std::string nomeArquivo){
    // Open the file; if it can't be opened, stop
    std::ifstream file(nomeArquivo);
    if (!file.is_open()){
        return false;
    }
    
    // Magic number, width, height, max component value
    std::string magico;
    int altura_arquivo, largura_arquivo, maxval;
    file >> magico >> largura_arquivo >> altura_arquivo >> maxval;
    if (!file || magico != "P3"){
        return false;
    }

    // Reallocate only when the dimensions differ from the current ones
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

    // Pixels come row by row (i outer, j inner)
    for (int i = 0; i < alturaMatriz; i++){
        for (int j = 0; j < larguraMatriz; j++){
            file >> matrizPixeis[j][i].r >> matrizPixeis[j][i].g >> matrizPixeis[j][i].b;
            
        }
    }
    return true;
}

bool Imagem::salvarPPM(const std::string nomeArquivo){
    // Create the file; if it can't be opened, stop
    std::ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        return false;
    }

    // Format, width and height, max color value
    arquivo << "P3\n";
    arquivo << larguraMatriz << " " << alturaMatriz << "\n";
    arquivo << 255 << "\n";

    // Write the pixels row by row, one pixel (R G B) per line
    for (int i = 0; i < larguraMatriz; i++){
        for (int j = 0; j < alturaMatriz; j++){
            arquivo << matrizPixeis[i][j].r << " ";
            arquivo << matrizPixeis[i][j].g << " ";
            arquivo << matrizPixeis[i][j].b << "\n";
        }
    }

    // Saved successfully
    return true;
}