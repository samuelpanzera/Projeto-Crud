#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#define MAX 500

#include "veiculo.h"
#include "menuSelecionavel.h"

using namespace std;


void limparConsole(){
   system("cls");
}

int pesquisarUmVeiculo(Veiculo *veiculos, int veiculosCadastrados){
    string placaEscolhida;
    int placaEncontrada = -1; //Pode ser posição 0 no array, portanto nao posso utilizar o 0 como condição no if

    cout << "===== Placas existentes =====" << endl;
    for(int i = 0; i< veiculosCadastrados; i++){
      printf("%d- %s\n", i+1 , veiculos[i].getPlaca().c_str());
     }

     cout << "\nDigite a placa: " << flush;
     cin >> placaEscolhida;

    for(int i = 0; i< veiculosCadastrados; i++){
      if(placaEscolhida == veiculos[i].getPlaca()){
        placaEncontrada = i;
      }
    }

    if(placaEncontrada != -1){
      cout << endl;

      veiculos[placaEncontrada].mostraVeiculo();
    }else{
      cout << "\n ---> PLACA NAO ENCONTRADA<--- \n\n Aperte qualquer tecla para sair" << endl;


      getchar();
      getchar();

      return -1;
    }

    getchar();

    return placaEncontrada;
}

bool pesquisaDeVeiculos(Veiculo *veiculos, int veiculosCadastrados){
    cout << "================ PESQUISA de veiculos Pela placa===============\n\n" << endl;

    pesquisarUmVeiculo(veiculos, veiculosCadastrados);

    cout << "Pressione enter para voltar" << endl;

    getchar();

    return true;
}

// POR PADRÃO PASSAR TERCEIRO PARAMETRO COMO 500
void substituiOArquivoInteiro(Veiculo *veiculos, int numeroDeVeiculos, int posicaoDeRetirada){
    FILE* arquivo = fopen("veiculos.txt", "w"); // APAGA TUDO e escreve novamente

    fprintf(arquivo,"%d\n", numeroDeVeiculos);

    for(int i = 0; i < numeroDeVeiculos; i++){
      if(i >= posicaoDeRetirada){
        fprintf(arquivo,"%s", veiculos[i+1].retornaLinhaNoPadrao().c_str());
      }else{
        fprintf(arquivo,"%s", veiculos[i].retornaLinhaNoPadrao().c_str());
      }
    }

    fclose(arquivo);
}


bool cadastrarUmVeiculo(Veiculo *veiculos, int *numeroDeVeiculos){
  int numeroAuxiliar = *numeroDeVeiculos;
  bool houveErro = false;

  FILE* arquivo = fopen("veiculos.txt", "a+"); // Escreve no final do arquivo

  do{
    try{
      veiculos[numeroAuxiliar].mostraESetaTodosOsValores(""); // Parametro para cadastrar também a placa
    }catch(int ERRO){
      if(ERRO == 1){
        cout << "\nVoce digitou a mais do que deveria na Placa, recadastre e tente novamente\n" << endl;
      }else if(ERRO == 2){
        cout << "\nDigite a placa no padrao mercosul, recadastre e tente novamente\n" << endl;
      }else{
        cout << "\nErro desconhecido\n";
        return -1;
      }

      houveErro = true;
    }
  }while(houveErro);


  string linha = veiculos[numeroAuxiliar].retornaLinhaNoPadrao();

  fprintf(arquivo, "%s\n", linha.c_str());

  *numeroDeVeiculos = numeroAuxiliar + 1;

  cout << "Veiculo cadastrado com sucesso! Aperte qualquer tecla para voltar ao menu" << endl;

  fclose(arquivo);

  getchar();
  getchar();

  substituiOArquivoInteiro(veiculos, *numeroDeVeiculos, MAX);

  return true;
}


bool editarUmVeiculo(Veiculo *veiculos, int veiculosCadastrados){
  cout << "================ EDICAO de veiculos Pela placa===============\n\n" << endl;

  int posicaoDoVeiculoEncontrado = pesquisarUmVeiculo(veiculos, veiculosCadastrados);

  if(posicaoDoVeiculoEncontrado == -1){
    return true;
  }

  string placa = veiculos[posicaoDoVeiculoEncontrado].getPlaca();

  veiculos[posicaoDoVeiculoEncontrado].mostraESetaTodosOsValores(placa);

  substituiOArquivoInteiro(veiculos, veiculosCadastrados, MAX);

  cout << "Veiculo editado com sucesso!" << endl;

  cout << "Aperte qualquer tecla para voltar para o menu";

  getchar();
  getchar();

  return true;
}

bool excluirUmVeiculo(Veiculo *veiculos, int veiculosCadastrados){
    cout << "================EXCLUSÃO de veiculos Pela placa===============\n\n" << endl;

    int posicaoDoVeiculoEncontrado = pesquisarUmVeiculo(veiculos, veiculosCadastrados);

    if(posicaoDoVeiculoEncontrado == -1){
      return true;
    }
    int opcao;

    cout << "ATENCAO!! TEM CERTEZA QUE DESEJA EXCLUIR O VEICULO? 1- SIM 2- NAO (Digite o numero): ";
    cin >> opcao;

    // como se fosse garantir que o cliente nao faça cagada
    if(opcao != 1){
      cout << "Aperte qualquer tecla para voltar para o menu";

      getchar();
      getchar();

      return true;
    }

    substituiOArquivoInteiro(veiculos, veiculosCadastrados - 1, posicaoDoVeiculoEncontrado);

    cout << "Aperte qualquer tecla para voltar para o menu";

    getchar();
    getchar();

    return true;
}


void fazLeituraDaLinha(string linha, string carroOuMoto[]){
  int contadorAuxiliar = 0; //Contador pra guardar as 7 informacoes no array
  string word = ""; //String vazia para concatenar valores

  for (int i= 0; i < linha.size() ; i++){
    if (linha[i] == ';'){ //Delimitador
      carroOuMoto[contadorAuxiliar] = word;
      word = "";
      contadorAuxiliar++;
      }else {
        word = word + linha[i]; // Como se fosse char 'a' + oque esta salvo em word, no primeiro momento vazio depois completa
        }
      }

}

void cadastraTodosOsVeiculosDoArquivo(Veiculo *veiculos, int *numeroDeVeiculos){
  FILE* arquivo = fopen("veiculos.txt", "r+") ;

  int veiculosCadastrados;

  fscanf(arquivo, "%d", &veiculosCadastrados); //primeira linha
  fgetc(arquivo); // Pula o '\n'

  *numeroDeVeiculos = veiculosCadastrados;

  char linha[MAX];

  string carroOuMoto[8]; // 7 = 1-Placa 2- tipo 3- marca 4- modelo 5-preco 6-obsAdicionais 7-Ano

  for(int i = 0; i < veiculosCadastrados; i++){
    struct VeiculoEntity veiculoEntity;

    fscanf(arquivo,"%s", linha);  // NÃO PERMITE ESPACOS

    fazLeituraDaLinha(linha, carroOuMoto);  // Me arrendi de ter feito assim, mas foram muitas horas nessa funcao, mals fessor

    char tipo = carroOuMoto[5][0]; //Retorna a string da posição 5 e depois pega o char da string na posicao 0

    veiculoEntity.placa = carroOuMoto[0];
    veiculoEntity.marca = carroOuMoto[1];
    veiculoEntity.modelo = carroOuMoto[2];
    veiculoEntity.ano = stoi(carroOuMoto[3]);
    veiculoEntity.preco = stof(carroOuMoto[4]);
    veiculoEntity.tipo = tipo;
    veiculoEntity.observacao = carroOuMoto[6];

    veiculos[i].configurarTodosOsVeiculos(veiculoEntity);
  }



    fclose(arquivo);
}


bool listarTodosOsVeiculos(Veiculo *veiculos, int veiculosCadastrados){
    for(int i = 0; i< veiculosCadastrados; i++){
       veiculos[i].mostraVeiculo();
    }

    cout << "\nPressione Qualquer botão para voltar" << endl;
    getchar(); //Aguardar execução
    return true;
}


int main (){
    bool voltar;
    int *veiculosCadastrados = new int(20);
    *veiculosCadastrados = 5; // MAXIMO DE VEICULOS CADASTRADOS NO INICIO DO PROGRAMA

do{
    voltar = false;
    limparConsole();

    Veiculo *veiculos = new Veiculo[*veiculosCadastrados + 3]; // + 3 de folga

    int opcaoSelecionada = menu();

    cadastraTodosOsVeiculosDoArquivo(veiculos, veiculosCadastrados); // Sempre cadastra os veiculos na memoria ram quando volta do menu

    switch(opcaoSelecionada){
        case 1:
            limparConsole();
            voltar = listarTodosOsVeiculos(veiculos, *veiculosCadastrados);
            break;
        case 2:
            limparConsole();
            voltar = pesquisaDeVeiculos(veiculos, *veiculosCadastrados);
            break;
        case 3:
            limparConsole();
            voltar = cadastrarUmVeiculo(veiculos, veiculosCadastrados); //Recebe o endereco da variavel de veiculos cadastrados para acrescentar o valor
            break;
        case 4:
            limparConsole();
            voltar = editarUmVeiculo(veiculos, *veiculosCadastrados);
            break;
        case 5:
            limparConsole();
            voltar = excluirUmVeiculo(veiculos, *veiculosCadastrados); //Decrementa no proprio arquivo, quando volta do loop, o arquivo é lido novamente
            break;
        default:
            cout << "\n\nAperte qualquer tecla para finalizar o programa\n\n" << endl;
    }
}while(voltar);

return 0;
}


