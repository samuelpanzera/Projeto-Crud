#include "Veiculo.h"
#include <iostream>


using namespace std;

Veiculo::Veiculo(){
}

Veiculo::~Veiculo()
{
}


std::string Veiculo::getPlaca(){
  return placa;
}

void Veiculo::setPlaca(std::string placa){
  if(placa.length() != 7){
    throw ERRO_PLACA_TAMANHO;
  }

  for (int i = 0; i < 3; ++i) {
    if (placa[i] >= '0' && placa[i] <= '9') {
        throw ERRO_PLACA_PADRAO_MERCOSUL;
    }
  }

  if(!(placa[3] >= '0' && placa[3] <= '9')){
    throw ERRO_PLACA_PADRAO_MERCOSUL; //Letra na posição 4 (padrao mercosul)
  }


  this->placa = placa;
}

std::string Veiculo::getModelo(){
  return modelo;
}

void Veiculo::setModelo(std::string modelo){
  this->modelo = modelo;
}

std::string Veiculo::getObservacao(){
    return observacao;
}

void Veiculo::setObservacao(std::string observacao){
 this->observacao = observacao;
}

int Veiculo::getAno(){
  return ano;
}

void Veiculo::setAno(int ano){
  this->ano = ano;
}

float Veiculo::getPreco(){
  return preco;
}

void Veiculo::setPreco(float preco){
  this->preco = preco;
}

char Veiculo::getTipo(){
  return tipo;
}

void Veiculo::setTipo(char tipo){
  this->tipo = tipo;
}

std::string Veiculo::getMarca(){
  return this->marca;
}
void Veiculo::setMarca(std::string marca){
  this->marca = marca;
}
