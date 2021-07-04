#include <iostream>
#include <fstream> //adicionar - leitura e gravação
#include <vector> // lista dinamica
#include "TrianguloRetangulo.h" // minha biblioteca


void GravarBancoDeDados(tTriangulo triangulos[], int entradas) {
  int i  = 0;
  std::ofstream gravar;
  gravar.open("arquivo.txt");
  if (gravar.is_open()) {
    gravar << entradas << "\n";
    for (i = 0; i < entradas; i++) {
      gravar << triangulos[i].catetoOposto << "\n";
      gravar << triangulos[i].catetoAdjacente << "\n";
      gravar << triangulos[i].hipotenusa << "\n";
    }
  }
  std::cout << "Dados Gravados no Banco de Dados\n";
}

void LerBancoDeDados() {
  std::string linha;
  std::ifstream arquivo;
  arquivo.open("arquivo.txt");
  if (!arquivo.is_open()) {
    std::cout << "Banco de Dados Inexistente\n";
  }
  else {
    int contagem_linhas = 0;
    std::vector<std::string> linhas;
    std::vector<tTriangulo> triangulos;
    int entradas = 0;
    while(getline(arquivo, linha)) {
      if (contagem_linhas > 0) {
        linhas.push_back(linha);
      }
      else {
        entradas = std::stoi(linha);
      }
      contagem_linhas++;
      if (contagem_linhas > ((entradas * 3) + 1)) {
        break;
      }
    }
    int l = 0;
    for(contagem_linhas = 0; contagem_linhas < entradas; contagem_linhas++) {
      tTriangulo t;
      t.catetoOposto = std::stoi(linhas[l]);
      l++;
      t.catetoAdjacente = std::stoi(linhas[l]);
      l++;
      t.hipotenusa = std::stoi(linhas[l]);
      l++;
      triangulos.push_back(t);
    }
    std::cout << "##### INICIO BANCO DE DADOS #####\n";
    for(l = 0; l < entradas; l++) {
      std::cout << "Triangulo " << std::to_string(l+1) << "\n";
      std::cout << "Cateto Oposto: " << std::to_string(triangulos[l].catetoOposto) << "\n";
      std::cout << "Cateto Adjacente: " << std::to_string(triangulos[l].catetoAdjacente) << "\n";
      std::cout << "Hipotenusa: " << std::to_string(triangulos[l].hipotenusa) << "\n";
    }
    std::cout << "##### FIM DO BANCO DE DADOS #####\n";
  }
}

int main() { //começa o programa
  while(true){
    std::string operacao;

    std::cout << "Selecione a Operação\n1 > Ler Banco de Dados\n2 > Escrever Banco de Dados\n";
    std::cin >> operacao;

    if (operacao == "1"){
      std::ifstream arquivo ("arquivo.txt");
      if(!arquivo.is_open()){
        std::cout << "Banco de Dados Inexistente!\n";
      }
      else {
        LerBancoDeDados();
      }
    }
    else if (operacao == "2"){
      int entradas = 0;
      std::cout << "Quantas entradas serão armazenadas?:\n";
      std::cin >> entradas;
      if (entradas <= 0) {
        std::cout << "O Número de entradas deve ser maior que 0\n";
      }
      else {
        int i = 0;
        tTriangulo triangulos[entradas];
        for (i = 0; i < entradas; i++) {
          tTriangulo triangulo;
          std::cout << "Entrada " << std::to_string(i+1) << " de " << std::to_string(entradas) << "\n";
          std::cout << "Digite o Valor do Cateto Oposto:\n";
          std::cin >> triangulo.catetoOposto;
          std::cout << "Digite o Valor do Cateto Adjacente:\n";
          std::cin >> triangulo.catetoAdjacente;
          std::cout << "Digite o Valor da Hipotenusa:\n";
          std::cin >> triangulo.hipotenusa;
          triangulos[i] = triangulo;
        }
        GravarBancoDeDados(triangulos, entradas);
      }
    }
    else {
      std::cout << "Operação Inválida";
    }
  }
}