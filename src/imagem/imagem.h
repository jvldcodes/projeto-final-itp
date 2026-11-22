/**
 * Declaração da classe Imagem.
 */

#pragma once

// Defina aqui a classe Imagem, conforme especificado na etapa 2 do projeto.
// Você pode reaproveitar o tipo Cor definido em paleta.h, para representar as cores dos pixels da imagem.
// Para isso, você pode definir um tipo Pixel como um alias para Cor, ou seja, Pixel será apenas outro nome para Cor.
#include <string>
#include "../paleta/paleta.h"
using Pixel = Cor; // Pixel agora é outro nome para Cor, representando a cor de um pixel da imagem.

/**
 * Representa uma imagem digital como uma matriz de pixels alocada dinamicamente.
 * A coordenada (x, y) indica a coluna x (0 a largura-1) e a linha y (0 a altura-1).
 */
class Imagem{
private:
    int larguraMatriz;
    int alturaMatriz;
    Pixel** matrizPixeis;
public:
    /**
     * Cria uma imagem preta de tamanho 10x10.
     */
    Imagem();

    /**
     * Cria uma imagem preta com as dimensões dadas.
     * @param largura: quantidade de colunas.
     * @param altura: quantidade de linhas.
     */
    Imagem(int largura,int altura);

    /**
     * Libera a memória alocada pela imagem.
     */
    ~Imagem();

     /**
     * Retorna a largura da imagem.
     * @return quantidade de colunas.
     */
    int obterLargura();

    /**
     * Retorna a altura da imagem.
     * @return quantidade de linhas.
     */
    int obterAltura();

     /**
     * Retorna o pixel que está na coordenada (x, y).
     * @param x: coluna do pixel.
     * @param y: linha do pixel.
     * @return pixel na coordenada. Se a coordenada for inválida, retorna uma cor padrão (preto).
     */
    Pixel obterPixel(int x, int y);

     /**
     * Define a cor do pixel na coordenada (x, y). Se a coordenada for inválida, nada acontece.
     * @param x: coluna do pixel.
     * @param y: linha do pixel.
     * @param cor: nova cor do pixel.
     */
    void definePixel(int x, int y, Pixel cor);

    /**
     * Lê uma imagem no formato PPM (P3). Se as dimensões do arquivo forem diferentes das
     * dimensões atuais, a imagem é redimensionada.
     * @param nomeArquivo: nome do arquivo PPM a ser lido.
     * @return true se a leitura foi bem-sucedida, false caso contrário.
     */
    bool lerPPM(std::string nomeArquivo);

     /**
     * Salva a imagem no formato PPM (P3).
     * @param nomeArquivo: nome do arquivo a ser criado.
     * @return true se o arquivo foi salvo com sucesso, false caso contrário.
     */
    bool salvarPPM(std::string nomeArquivo);

};

// Lembre-se de:
// 1. verificar no arquivo de teste o nome correto da classe, dos métodos que você deve implementar, bem como os
//    parâmetros e tipos de retorno de cada método.
// 2. documentar a classe e seus métodos, seguindo o padrão do arquivo paleta.h.
// 3. implementar no arquivo imagem.cpp os métodos da classe.
