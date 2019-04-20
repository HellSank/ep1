#include"embarcacoes.hpp"
#include<vector>
#include<iostream>
#include<tuple>
#include<utility>
using shi = short int;
using namespace std;
//_______________

Embarcacoes::~Embarcacoes(){
}

Embarcacoes::Embarcacoes(){
}

void Embarcacoes::setVidaDeCadaParte(shi vidaDeCadaParte){
  this->vidaDeCadaParte = vidaDeCadaParte;
}

shi Embarcacoes::getVidaDeCadaParte(){
  return this->vidaDeCadaParte;
}

pair<shi,shi>Embarcacoes::getPonto(){
  return this->ponto;
}

void Embarcacoes::setPonto(shi x,shi y){
  this->ponto.first = x;
  this->ponto.second = y;
}

char Embarcacoes::getDirecao(){
    return this->direcao;
}

void Embarcacoes::setDirecao(char direcao){
  this->direcao = direcao;
}

shi Embarcacoes::getNumeroDeCasasOcupadas(){
  return this->numeroDeCasasOcupadas;
}

void Embarcacoes::setNumeroDeCasasOcupadas(shi numeroDeCasasOcupadas){
  this->numeroDeCasasOcupadas = numeroDeCasasOcupadas;
}
//_______________

shi Embarcacoes::vidaTotal(){
  return this->getNumeroDeCasasOcupadas()*this->getVidaDeCadaParte();
}

void Embarcacoes::posicionarEmbarcacao(shi x, shi y,char direcao){//getNumeroDeCasasOcupadas,getVidaDeCadaParte
  this->setPonto(x,y);
  this->setDirecao(direcao);
  if((this->getDirecao())=='N'){
    for (short int  i = 0; i < this->getNumeroDeCasasOcupadas(); i++) {
      this->posicao_VidaDeCadaParte.push_back(make_tuple(this->getPonto().first,getPonto().second+i,this->getVidaDeCadaParte()));
    }
  }else if(this->getDirecao()=='S'){
    for (short int  i = 0; i < this->getNumeroDeCasasOcupadas(); i++) {
      this->posicao_VidaDeCadaParte.push_back(make_tuple(this->getPonto().first,getPonto().second-i,this->getVidaDeCadaParte()));
    }
  }else if(this->getDirecao()=='L'){
    for (short int  i = 0; i < this->getNumeroDeCasasOcupadas(); i++) {
      this->posicao_VidaDeCadaParte.push_back(make_tuple(this->getPonto().first+i,getPonto().second,this->getVidaDeCadaParte()));
    }
  }else if(this->getDirecao()=='O'){
    for (short int i = 0; i < this->getNumeroDeCasasOcupadas(); i++) {
      this->posicao_VidaDeCadaParte.push_back(make_tuple(this->getPonto().first-i,getPonto().second,this->getVidaDeCadaParte()));
    }
  }
}

char Embarcacoes::checarSeFuiAtacado(shi x,shi y){
  this->setPonto(x,y);
  char letra='A';
  for (auto i :this->posicao_VidaDeCadaParte) {
    if(get<0>(i)==this->getPonto().first and get<1>(i)==this->getPonto().second){
      letra = this->usarHabilidadeEspecial();
    }
  }
  return letra;
}

void Embarcacoes::sofrerAtaque(){
  for (int i=0;i<this->getNumeroDeCasasOcupadas();i++) {
    if(get<0>(this->posicao_VidaDeCadaParte[i])==this->getPonto().first and get<1>(this->posicao_VidaDeCadaParte[i])==this->getPonto().second){
      get<2>(this->posicao_VidaDeCadaParte[i])--;
      //printf("Vida:%d\n",get<2>(this->posicao_VidaDeCadaParte[i]));
      return;
    }
  }
  //printf("Vida nao reduzida\n")
}
