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
    tamanhoPaleta = 30;
    quantidadeCores = 0;
    listaCores = new Cor[tamanhoPaleta];
}

Paleta::Paleta(int tamanho){
    // Empty palette with room for 30 colors, allocated on the heap
    tamanhoPaleta =  tamanho;
    quantidadeCores = 0;
    listaCores = new Cor[tamanhoPaleta];
}

Paleta::Paleta(const std::string& nomeArquivo){
    // Delegates to the default constructor, then fills the palette from the file
    std::ifstream file(nomeArquivo);
    if (!file.is_open()){
        tamanhoPaleta = 30;
        quantidadeCores = 0;
        listaCores = new Cor[tamanhoPaleta];
        return;
    }
    std::string line;
    int quantidadeLinhas = 0;

    while(std::getline(file,line)){
        quantidadeLinhas++;
    }
    file.close();
    file.open(nomeArquivo);
    tamanhoPaleta =  quantidadeLinhas;
    quantidadeCores = 0;
    listaCores = new Cor[tamanhoPaleta];
    

    while(std::getline(file,line) && quantidadeCores < tamanhoPaleta){
        // Strip the '\r' left by Windows line endings, skip blank or malformed lines
        listaCores[quantidadeCores] = hexToRGB(line);
        quantidadeCores++;
    }
}

Paleta::~Paleta(){
    delete[] listaCores;
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
    if(indice < 0 or indice >= tamanhoPaleta){
        return {0,0,0};
    }
    return listaCores[indice];

}

// implemente aqui os métodos da classe Paleta, conforme especificado no arquivo de cabeçalho paleta.h