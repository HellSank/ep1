#include "embarcacoes.hpp"
#include "portaAvioes.hpp"
#include <cstdlib>
#include <ctime>
PortaAvioes::~PortaAvioes(){
}
PortaAvioes::PortaAvioes(shi x, shi y , char direcao){
  this->setPonto(x,y);
  this->setDirecao(direcao);
  this->setVidaDeCadaParte(1);
  this->setNumeroDeCasasOcupadas(4);
  this->posicionarEmbarcacao(this->getPonto().first,this->getPonto().second,this->getDirecao());
}
char PortaAvioes::usarHabilidadeEspecial(){
  char letra = 'P';
  srand((unsigned)time(0));
  int numeroAleatorio = rand()%101;
  if(numeroAleatorio<50){
    printf("Porta Avioes encontrado!!!\nParte dele foi destruido\n");
    this->sofrerAtaque();
    letra = 'D';
    return letra;
  }else{
    printf("Porta Avioes encontrado!!!\nMas a habilidade especial dele o manteve vivo\n");
    return letra;
  }
}
