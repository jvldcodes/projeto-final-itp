#define DOCTEST_CONFIG_IMPLEMENT
#include <cstdlib>
#include "../doctest.h"
#include "terreno.h"  // veja que esse arquivo não existe ainda, você precisará criá-lo para definir a classe Terreno.

TEST_CASE("Testa a criação de um terreno de uma única célula") {
  Terreno terreno(0); // 2^0 + 1 = 1
  CHECK(terreno.obterLargura() == 1);
  CHECK(terreno.obterProfundidade() == 1);
}

TEST_CASE("Testa a geração aleatória de altitudes") {
  Terreno terreno(2);
  CHECK(terreno.obterLargura() == 5);
  CHECK(terreno.obterProfundidade() == 5);
}

// Você precisará criar testes adicionais para cobrir os métodos privados da classe.
// Os testes vão depender de como você estruturou o algoritmo de geração do terreno (Square e Diamond).
// Então, escreva seus próprios testes para os métodos das etapas Square e Diamond.
// Você pode torná-los públicos temporariamente para fins de teste.


// o main foi implementado aqui para inicializar o gerador de números aleatórios antes dos testes.
int main(int argc, char** argv) {
  // inicializa o gerador de números aleatórios uma única vez no programa.
  // o valor é fixo para que os testes sejam reprodutíveis, ou seja, que sempre gerem os mesmos resultados.
  // isso é importante para debugar. você pode alterar o valor para gerar diferentes terrenos aleatórios.
  std::srand(100);

  doctest::Context context;
  return context.run(); 
}