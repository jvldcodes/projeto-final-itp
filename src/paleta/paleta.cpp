#include "paleta.h"
#include <fstream>
#include <string>

Cor hexToRGB(std::string hex) {
    // Remove the '#' prefix if it's present
    if (hex[0] == '#') {
        hex.erase(0, 1);
    }

    // Convert each 2-character substring from base 16 to base 10
    int r = std::stoi(hex.substr(0, 2), nullptr, 16);
    int g = std::stoi(hex.substr(2, 2), nullptr, 16);
    int b = std::stoi(hex.substr(4, 2), nullptr, 16);
    return {r,g,b};
}

Paleta::Paleta(){
    // Empty palette with room for 30 colors, allocated on the heap
    tamanhoPaleta =  30;
    quantidadeCores = 0;
    listaCores = new Cor[tamanhoPaleta];
}

Paleta::Paleta(const std::string& nomeArquivo) : Paleta() {
    // Delegates to the default constructor, then fills the palette from the file
    std::ifstream file(nomeArquivo);
    if (!file.is_open()){
        return;
    }
    std::string line;
    while(std::getline(file,line) && quantidadeCores < tamanhoPaleta){
        // Strip the '\r' left by Windows line endings, skip blank or malformed lines
        listaCores[quantidadeCores] = hexToRGB(line);
        quantidadeCores++;
    }
}


int Paleta::obterTamanho() const{
    // Maximum number of colors the palette can hold
    return tamanhoPaleta;
}

int Paleta::obterQuantidade() const{
    // Number of colors currently stored
    return quantidadeCores;
}

void Paleta::adicionarCor(const Cor& cor){
    // Append the color at the last index, only if there is room left
    if (quantidadeCores < tamanhoPaleta) {
        listaCores[quantidadeCores++] = cor;
    }
}
Cor Paleta::obterCor(int indice){
    // Look for the color at the given index
    for(int i = 0; i < quantidadeCores; i++){
        if(listaCores[i].r == listaCores[indice].r && listaCores[i].g == listaCores[indice].g && listaCores[i].b == listaCores[indice].b){
            return listaCores[i];
        }
    }
    return {0,0,0};
}

// implemente aqui os métodos da classe Paleta, conforme especificado no arquivo de cabeçalho paleta.h