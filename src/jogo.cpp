#include "jogo.hpp"
void Jogo::configurarPlayer(Player* player,Mapa* mapa){
  short nCanoas=1,nSubmarinos=1,nPortaAvioes=1,x,y;
  char caractere;
  string nomePlayer;
  cout << "Player, posicione as canoas da seguinte maneira: digite o valor e x espaco y" << '\n';
  printf("\033[2J\033[1;1H");
  sleep(3.1);

  do {
    cout<<"Canoa ("<< nCanoas<<") : ";
    cin >> x>>y;
    mapa->setCanoas(Canoa(x,y));
    nCanoas++;
  } while(nCanoas!=7);

  cout << "Player, posicione os submarinos da seguinte maneira:\ndigite o valor e x espaco y espaco 'caractere que indica para qual lado a embarcacao sera posicionada\n(N->Norte;S->Sul;L->Leste;O->Oeste)'" << '\n';
  printf("\033[2J\033[1;1H");
  sleep(10.1);

  do {
    cout<<"Submarino ("<< nSubmarinos<<") : ";
    cin >> x>>y>>caractere;
    mapa->setSubmarinos(Submarino(x,y,caractere));
    nSubmarinos++;
  } while(nSubmarinos!=5);

  cout << "Player, posicione os porta-avioes da seguinte maneira:\ndigite o valor e x espaco y espaco 'caractere que indica para qual lado a embarcacao sera posicionada\n(N->Norte;S->Sul;L->Leste;O->Oeste)'" << '\n';
  printf("\033[2J\033[1;1H");
  sleep(7.1);

  do {
    cout<<"Porta-Avioes ("<< nPortaAvioes<<") : ";
    cin >> x>>y>>caractere;
    mapa->setPortaAvioes(PortaAvioes(x,y,caractere));
    nPortaAvioes++;
  } while(nPortaAvioes!=3);

  cout << "Digite seu nome:";
  cin>> nomePlayer;
  player->setNome(nomePlayer);

}
Jogo::Jogo(){
  this->player1EVencedor = true;
}
Jogo::~Jogo(){
}
void Jogo::rodarOffline(){
  this->configurarPlayer(this->player1,this->mapa1);
  this->configurarPlayer(this->player2,this->mapa2);
  //Lembre-se que o player 1 configura o proprio mapa e ataca o mapa do player 2
  this->player1->setMapa(this->mapa2);
  this->player2->setMapa(this->mapa1);

  printf("Bem vindos a batalha naval Players\n");
  sleep(4.5);
  printf("\033[2J\033[1;1H");
  printf("%s(life):%d \n%s(life):%d\n",player1->getNome().c_str(),player1->getPontosDeVida(),player2->getNome().c_str(),player2->getPontosDeVida());
  printf("Players voces desejam saber sobre as notacoes do jogo?[S/N]");
  char querNotacoes='N';
  cin >> querNotacoes;
  if(querNotacoes=='S'){
    player2->verSignificadoDasNotacoes();
    printf("Pressione qualquer tecla [a-z] para prosseguirem\n");
    scanf("%*s");
  }else{
    printf("Ok...\n");
  }
  printf("\033[2J\033[1;1H");
  while (1) {
    if(rodarTurnoDoPlayer(this->player1))
      if(this->player2->perderVida())//Quando ele perde vida ele ja retorna se perdeu o game
        break;
    //Turno do player 2
    if(rodarTurnoDoPlayer(this->player2))
      if(this->player1->perderVida()){
        this->player1EVencedor = false;
        break;
      }
  }
  this->exibirPontuacao();
}
void Jogo::exibirPontuacao(){
  if(player1EVencedor){
    shi pts = player1->ganharJogo();
    player2->perderJogo(pts);
  }else{
    shi pts = player2->ganharJogo();
    player1->perderJogo(pts);
  }
}
bool Jogo::rodarTurnoDoPlayer(Player* playerAtacante){
  short int x,y;
  char saberSeVidaOponenteSeraReduzida = ' ';
  //______________________________ PLAYER GAME
  printf("Player : %s , aqui esta o seu mapa para atacar:\n",playerAtacante->getNome().c_str());
  playerAtacante->getMapa()->desenharMapa();

  printf("Escolha um ponto de ataque(digite apenas os valores de x e y separados por espaco):\n");
  cin >>x>>y;

  printf("\033[2J\033[1;1H");

  saberSeVidaOponenteSeraReduzida = playerAtacante->getMapa()->atacarPontoNoMapa(x,y);


  playerAtacante->getMapa()->desenharMapa();
  printf("Pressione qualquer tecla [a-z] para passar a vez\n");
  scanf("%*s");
  if(saberSeVidaOponenteSeraReduzida=='D' || saberSeVidaOponenteSeraReduzida=='S')
    return true;

  return false;
}
