#include "mapa.hpp"

Mapa::~Mapa(){
}
Mapa::Mapa(){
  // memset ?
  for (shi i = 0; i < 20; i++) {
    for(shi j = 0;j<20;j++){
      this->body[i][j] = '?';
    }
  }
  //
}

void Mapa::setCanoas(Canoa canoas){
  this->canoas.push_back(canoas);
}
void Mapa::setSubmarinos(Submarino submarinos){
  this->submarinos.push_back(submarinos);
}
void Mapa::setPortaAvioes(PortaAvioes portaAvioes){
  this->portaAvioes.push_back(portaAvioes);
}

void Mapa::atacarPontoNoMapa(shi x,shi y){

  char letra = 'A',letraTemp='A';

  for(shi i = 0;i<( unsigned short int )this->canoas.size();i++){
    letraTemp = this->canoas[i].checarSeFuiAtacado(x,y);
    if(letra!= letraTemp){
      letra = letraTemp;
      this->body[x][y] = letra;
      return;
    }
  }

  for(shi i = 0;i<( unsigned short int )this->submarinos.size();i++){
    letraTemp = this->submarinos[i].checarSeFuiAtacado(x,y);
    if(letra!= letraTemp){
      letra = letraTemp;
      this->body[x][y] = letra;
      return;
    }
  }

  for(shi i = 0;i<( unsigned short int )this->portaAvioes.size();i++){
    letraTemp = this->portaAvioes[i].checarSeFuiAtacado(x,y);
    if(letra!= letraTemp){
      letra = letraTemp;
      this->body[x][y] = letra;
      return;
    }
  }

  this->body[x][y] = letra;
  if(letra == 'A'){
    printf("Aguaa!!!\n");
  }

}

void Mapa::desenharMapa(){
  printf("\n");
  for(int i = 0;i<20;i++){
    printf("\n");
    for(int j = 0; j<20;j++){
      if(j!=19)
        printf("| %c ",this->body[i][j]);
      else
        printf("| %c |",this->body[i][j]);
    }
  }
  printf("\n");
}

shi Mapa::vidaTotalDoMapa(){
  shi vidaTotalDoMapa=0;
  for(auto i : this->canoas){
    vidaTotalDoMapa += i.vidaTotal();
  }
  for(auto i : this->submarinos){
    vidaTotalDoMapa += i.vidaTotal();
  }
  for(auto i : this->portaAvioes){
    vidaTotalDoMapa += i.vidaTotal();
  }
  return vidaTotalDoMapa;
}
