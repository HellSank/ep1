#include "embarcacoes.hpp"
#include "submarino.hpp"
Submarino::~Submarino(){
}
Submarino::Submarino(shi x,shi y , char direcao){
  this->setPonto(x,y);
  this->setDirecao(direcao);
  this->setVidaDeCadaParte(2);
  this->setNumeroDeCasasOcupadas(2);
  this->posicionarEmbarcacao(this->getPonto().first,this->getPonto().second,this->getDirecao());
}
char Submarino::usarHabilidadeEspecial(){
  char letra = 'S';
  for(auto i :this->posicao_VidaDeCadaParte){
    if(get<0>(i)==this->getPonto().first and get<1>(i)==this->getPonto().second){
      if( get<2>(i) > 1){
        this->sofrerAtaque();
        printf("life=%d\n",get<2>(i));
        printf("Submarino atingido!!!\nMas devido a Habilidade Especial desta embarcacao ele ainda possui uma vida\n");
        return letra;
      }else{
        this->sofrerAtaque();
        printf("Submarino atingido e destruido!!!\n");
        letra = 'D';
        return letra;
      }
    }
  }
  return letra;
}
