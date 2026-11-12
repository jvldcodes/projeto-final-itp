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
    tamanhoPaleta =  30;
    quantidadeCores = 0;
    listaCores = new Cor[tamanhoPaleta];
}

Paleta::Paleta(const std::string& nomeArquivo) : Paleta() {
    std::ifstream file(nomeArquivo);
    if (!file.is_open()){
        return;
    }
    std::string line;
    while(std::getline(file,line) && quantidadeCores < tamanhoPaleta){
        listaCores[quantidadeCores] = hexToRGB(line);
        quantidadeCores++;
    }
}


int Paleta::obterTamanho() const{
    return tamanhoPaleta;
}

int Paleta::obterQuantidade() const{
    return quantidadeCores;
}

void Paleta::adicionarCor(const Cor& cor){

}
Cor Paleta::obterCor(int indice){
    for(int i = 0; i < quantidadeCores; i++){
        if(listaCores[i].r == listaCores[indice].r && listaCores[i].g == listaCores[indice].g && listaCores[i].b == listaCores[indice].b){
            return listaCores[i];
        }
    }
    return {0,0,0};
}

// implemente aqui os métodos da classe Paleta, conforme especificado no arquivo de cabeçalho paleta.h