/**
 * Declaração da classe Paleta e da struct Cor.
 */

#pragma once
#include <string>

/**
 * Representa uma cor no formato RGB, com três componentes: vermelho (R), verde (G) e azul (B).
 */
struct Cor {
  int r;
  int g;
  int b;
};

/**
 * Representa uma paleta de cores, que é um conjunto de cores armazenadas em um array alocado
 * dinamicamente. Cada cor é representada por uma instância da struct Cor.
 */
class Paleta {
private:
  int tamanhoPaleta;
  int quantidadeCores;
  Cor* listaCores;
public:
  /**
   * Cria uma paleta vazia com um tamanho (quantidade máxima) predeterminado de cores.
   * @param tamanho: quantidade máxima de cores que a paleta pode armazenar. O valor padrão é 30.
   */
  Paleta();

  /**
   * Cria uma paleta de cores a partir de um arquivo.
   * O arquivo deve conter uma cor por linha, no formato hexadecimal (ex: #RRGGBB).
   * @param nomeArquivo: nome do arquivo que contém as cores da paleta.
   */
  Paleta(const std::string& nomeArquivo);

  

  /**
   * Retorna a quantidade máxima de cores que a paleta pode armazenar.
   * @return quantidade máxima de cores.
   */
  int obterTamanho() const; // o `const` indica que o método não modifica os atributos do objeto.

  /**
   * Retorna a quantidade de cores atualmente armazenadas na paleta.
   * @return quantidade de cores.
   */
  int obterQuantidade() const;

  /**
   * Adiciona uma cor à paleta, se houver espaço disponível. Ou seja, se a quantidade de cores
   * atualmente armazenadas for menor que o tamanho máximo da paleta.
   * @param cor: cor a ser adicionada à paleta.
   */
  void adicionarCor(const Cor& cor);

  /**
   * Retorna a cor armazenada na paleta no índice especificado.
   * @param indice: índice da cor a ser obtida.
   * @return cor armazenada no índice especificado. Se o índice for inválido (menor que 0 ou
   * maior ou igual à quantidade de cores), retorna uma cor padrão (preto).
   */
  Cor obterCor(int indice);

};

