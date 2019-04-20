#include "canoa.hpp"
#include"embarcacoes.hpp"

Canoa::~Canoa(){
}
Canoa::Canoa(shi x,shi y){
  this->setPonto(x,y);
  this->setDirecao('N');
  this->setNumeroDeCasasOcupadas(1);
  this->setVidaDeCadaParte(1);
  this->posicionarEmbarcacao(this->getPonto().first,this->getPonto().second,this->getDirecao());
}
char Canoa::usarHabilidadeEspecial(){
  printf("Voce acertou em cheio a canoinha...\n");
  return 'D';
}
