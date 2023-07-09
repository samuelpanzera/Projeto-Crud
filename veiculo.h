#ifndef VEICULO_H
#define VEICULO_H

#include <string>
#include <iostream>

using namespace std;

struct VeiculoEntity{
  std::string placa;
  std::string observacao;
  std::string modelo;
  std::string marca;
  float preco;
  int ano;
  char tipo;
};

//CODIGOS DE ERRO:

const int ERRO_PLACA_TAMANHO = 1;
const int ERRO_PLACA_PADRAO_MERCOSUL = 2;

class Veiculo
{
    private:
        std::string placa;
        std::string modelo;
        std::string observacao;
        std::string marca;
        int ano;
        float preco;
        char tipo;    // Tipo C = Carro ou Tipo M = Moto
    public:
        Veiculo();
        virtual ~Veiculo();

        void configurarTodosOsVeiculos(VeiculoEntity veiculoEntity){
          setPlaca(veiculoEntity.placa);
          setModelo(veiculoEntity.modelo);
          setObservacao(veiculoEntity.observacao);
          setAno(veiculoEntity.ano);
          setTipo(veiculoEntity.tipo);
          setPreco(veiculoEntity.preco);
          setMarca(veiculoEntity.marca);
        }

        void mostraVeiculo(){
          cout << "======================"<< endl;
          cout << "Placa: " << getPlaca() << endl;
          cout << "Marca: " << getMarca()<< endl;
          cout << "Modelo: " << getModelo()<< endl;
          cout << "Preco: " << getPreco()<< endl;
          cout << "Ano: " << getAno()<< endl;
          cout << "Tipo: " << getTipo()<< endl;
          cout << "Observacao: " << getObservacao()<< endl;
          cout << "======================"<< endl;
        }

        string retornaLinhaNoPadrao(){
          string linha = getPlaca() + ";" + getMarca() + ";" + getModelo() + ";"  + to_string(getAno()) +  ";" + to_string(getPreco()) + ";" + getTipo() + ";" + getObservacao() + ";\n";
          return linha;
        }

      // Se não tiver parametro "" Está cadastrando, caso tenha, está editando o veiculo
      void mostraESetaTodosOsValores(string placa){
        struct VeiculoEntity veiculoEntity;

        if(placa.size() == 0){
          cout << "Digite a placa padrao mercosul 'ABC1D23': ";
          cin >> veiculoEntity.placa;

          setPlaca(veiculoEntity.placa); // Pra caso de o ERRO no começo a pessoa não precisar voltar tudo de novo
        }else{
          veiculoEntity.placa = placa;
        }

        cout << "Digite a marca do veiculo: "<< flush;
        cin >> veiculoEntity.marca;

        cout << "Digite o modelo do veiculo: "<< flush;
        cin >> veiculoEntity.modelo;

        cout << "Digite o preco do veiculo: "<< flush;
        cin >> veiculoEntity.preco;

        cout << "Digite o ano do veiculo: "<< flush;
        cin >> veiculoEntity.ano;

        cout << "Digite o tipo (C - carro, M - Moto): " << flush;
        cin >> veiculoEntity.tipo;

        int opcao;
        cout << "Deseja adicionar observacao? 1-Sim 2-Nao (Digite o numero correspondente)";
        cin >> opcao;
        cout << endl;

        if(opcao == 1){
          cout << "Digite a observacao (SEM ESPACOS): ";
          cin >> veiculoEntity.observacao;
          cout << endl;
        }else{
          veiculoEntity.observacao = "N/A";
        }

        configurarTodosOsVeiculos(veiculoEntity); //Verifica erros
  }

        void setaTodosOsValores();

        std::string getPlaca();
        void setPlaca(std::string);

        std::string getModelo();
        void setModelo(std::string);

        std::string getObservacao();
        void setObservacao(std::string);

        float getPreco();
        void setPreco(float);

        int getAno();
        void setAno(int);

        char getTipo();
        void setTipo(char);

        std::string getMarca();
        void setMarca(std::string);
};

#endif // VEICULO_H
