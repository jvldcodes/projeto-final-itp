#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "imagem.h"

TEST_CASE("Testa a criação de uma imagem com largura e altura específicas") {
    Imagem img(100, 50);
    CHECK(img.obterLargura() == 100);
    CHECK(img.obterAltura() == 50);
}

TEST_CASE("Testa a modificação e acesso aos pixels da imagem") {
    Imagem img(3, 3);
    Pixel pixels[3][3] = {
        { {255, 0, 0}, {0, 255, 0}, {0, 0, 255} },
        { {0, 255, 255}, {128, 128, 128}, {64, 64, 64} },
        { {0, 0, 0}, {50, 100, 150}, {100, 150, 200} }
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            img.definePixel(i, j, pixels[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Pixel pixel = img.obterPixel(i, j);
            CHECK(pixel.r == pixels[i][j].r);
            CHECK(pixel.g == pixels[i][j].g);
            CHECK(pixel.b == pixels[i][j].b);
        }
    }
}

TEST_CASE("Testa a leitura de uma imagem em formato PPM") {
    Imagem img;
    bool arq_aberto = img.lerPPM("imagem.ppm");
    CHECK(arq_aberto);
    CHECK(img.obterLargura() == 3);
    CHECK(img.obterAltura() == 2);

    Pixel p1 = img.obterPixel(0, 0);
    CHECK(p1.r == 255);
    CHECK(p1.g == 0);
    CHECK(p1.b == 0);

    Pixel p2 = img.obterPixel(1, 0); // (x,y) = (1,0)
    CHECK(p2.r == 0);
    CHECK(p2.g == 255);
    CHECK(p2.b == 0);

    Pixel p3 = img.obterPixel(0, 1); // (x,y) = (0,1)
    CHECK(p3.r == 255);
    CHECK(p3.g == 255);
    CHECK(p3.b == 0);

    Pixel p4 = img.obterPixel(1, 1);
    CHECK(p4.r == 255);
    CHECK(p4.g == 255);
    CHECK(p4.b == 255);
}

TEST_CASE("Testa a salvamento da imagem em formato PPM") {
    Imagem img(2, 2);
    img.definePixel(0, 0, {255, 0, 0});   // vermelho
    img.definePixel(1, 0, {0, 255, 0});   // verde
    img.definePixel(0, 1, {0, 0, 255});   // azul
    img.definePixel(1, 1, {255, 255, 0}); // amarelo

    bool arq_aberto = img.salvarPPM("teste.ppm");
    CHECK(arq_aberto);

    // verifica se o arquivo foi criado corretamente
    std::ifstream arquivo("teste.ppm");
    CHECK(arquivo.is_open());

    // verifica o cabeçalho do arquivo PPM (código, dimensões e valor máximo)
    std::string conteudo;
    std::getline(arquivo, conteudo);
    CHECK(conteudo == "P3");
    std::getline(arquivo, conteudo);
    CHECK(conteudo == "2 2");
    std::getline(arquivo, conteudo);
    CHECK(conteudo == "255");

    // verifica os valores dos pixels no arquivo PPM
    int valor;
    int valores[] = {255, 0, 0, 0, 255, 0, 0, 0, 255, 255, 255, 0};
    for (int i = 0; i < 12; ++i) {
        arquivo >> valor;
        CHECK(valor == valores[i]);
    }

    arquivo.close();
}