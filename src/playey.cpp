#include"player.hpp"
#include"mapa.hpp"
#include<string>
void Player::iniciarPontosDeVida(){
  this->pontosDeVida = this->mapaParaAtacar.vidaTotalDoMapa();//Como o mapa o qual o player atacara e o seu proprio mapa possuem o mesmo numero e tipo de embarcacoes , tal atribuicao e valida
}
void Player::ganharJogo(){
  shi pontos = 100 - (unsigned short int)100*(this->pontosDeVida/(float)this->mapaParaAtacar.vidaTotalDoMapa);
  printf("Parabens player:%s\nVoce ganhou o jogo, sua pontuacao e de : %dpts\n",this->getNome().c_str(),pontos);
}
void Player::perderJogo(){

}
void Player::verSignificadoDasNotacoes(){
  printf("Ola player:%s\n"
         "Basicamente o esquema de notacoes funciona da seguinte maneira:\n "
         "S -> Submarino\n"
         "P -> Porta Avioes\n"
         "C -> Canoa\n"
         "A -> Agua\n"
         "D -> Destroco\n"
         "? -> Ponto 'obscuro'\n",this->getNome().c_str());
}
void Player::perderVida(){
  this->pontosDeVida--;
}
//________ Getters and Setters || Construtor
Player::Player(string nome,Mapa mapaParaAtacar){
  this->setNome(nome);
  this->setMapa(mapaParaAtacar);
}
Player::~Player(){

}

string Player::getNome(){
  return this->nome;
}
void Player::setNome(string nome){
  this->nome = nome;
}

Mapa Player::getMapa(){
  return this->mapaParaAtacar;
}
void Player::setMapa(Mapa mapaParaAtacar){
  this->mapaParaAtacar = mapaParaAtacar;
}

shi Player::getPontosDeVida(){
  return this->pontosDeVida;
}
void Player::setPontosDeVida(shi pontosDeVida){
  this->pontosDeVida = pontosDeVida;
}

shi Player::getPontuacao(){
  return this->pontuacao;
}
