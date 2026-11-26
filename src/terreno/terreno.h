#pragma once
#include <cmath>
#include <cstdlib>
#include <string>

class Terreno {
private:
    int n_tamanho;
    int tamanhoReal;
    double** matriz;
public:
    Terreno(int n);

    ~Terreno();

    void gerarMatriz(int n, double rugosidade);

    int obterAltitude(int x, int y);

    int obterLargura();

    int obterProfundidade();

    bool salvarMatriz(std::string nomeArquivo);

    bool lerMatriz(std::string nomeArquivo);
};