#include <iostream>
#include <string>
#include <fstream>
#include<unistd.h>

#include "canoa.hpp"
#include "portaAvioes.hpp"
#include "submarino.hpp"

#include "mapa.hpp"
#include "player.hpp"

using namespace std;

int main(){
    Mapa mapa1,mapa2;

    mapa1.setCanoas(Canoa(11,1));
    mapa1.setCanoas(Canoa(4,6));
    /*mapa1.setCanoas(Canoa(8,10));
    mapa1.setCanoas(Canoa(10,10));
    mapa1.setCanoas(Canoa(5,12));
    mapa1.setCanoas(Canoa(12,12));
    mapa1.setSubmarinos(Submarino(5,2,'L'));
    mapa1.setSubmarinos(Submarino(1,4,'L'));
    mapa1.setSubmarinos(Submarino(10,7,'L'));
    mapa1.setSubmarinos(Submarino(6,12,'L'));
    mapa1.setPortaAvioes(PortaAvioes(7,2,'S'));
    mapa1.setPortaAvioes(PortaAvioes(5,9,'L'));*/

    Player player1("Diana",&mapa1);//Mapa 1 e do player Dante

    mapa2.setCanoas(Canoa(7,0));
    mapa2.setCanoas(Canoa(12,1));
    /*mapa2.setCanoas(Canoa(10,6));
    mapa2.setCanoas(Canoa(12,7));
    mapa2.setCanoas(Canoa(2,11));
    mapa2.setCanoas(Canoa(11,12));
    mapa2.setSubmarinos(Submarino(1,6,'L'));
    mapa2.setSubmarinos(Submarino(3,7,'L'));
    mapa2.setSubmarinos(Submarino(2,10,'L'));
    mapa2.setSubmarinos(Submarino(8,9,'L'));
    mapa2.setPortaAvioes(PortaAvioes(0,1,'S'));
    mapa2.setPortaAvioes(PortaAvioes(3,6,'L'));*/

    Player player2("Dante",&mapa2);//Mapa 2 e da player Diana
    printf("Bem vindos a batalha naval Players\n");
    //printf("VidaMapa1 :%d VidaMapa2 :%d\n",mapa1.vidaTotalDoMapa(),mapa2.vidaTotalDoMapa() );
    sleep(4.5);
    printf("\033[2J\033[1;1H");
    printf("%s(life):%d \n%s(life):%d\n",player1.getNome().c_str(),player1.getPontosDeVida(),player2.getNome().c_str(),player2.getPontosDeVida() );
    bool player2PerdeuGame = false,player1PerdeuGame = false;

    printf("Players voces desejam saber sobre as notacoes do jogo?[S/N]");
    char querNotacoes='N';
    cin >> querNotacoes;
    if(querNotacoes=='S'){
      player2.verSignificadoDasNotacoes();
      printf("Pressione qualquer tecla [a-z] para prosseguirem\n");
      scanf("%*s");
    }else{
      printf("Ok...\n");
    }

    printf("\033[2J\033[1;1H");

    while (1) {
      short int x,y;
      char saberSeVidaOponenteSeraReduzida = ' ';
      //______________________________ PLAYER 1 GAME
      printf("Player : %s , aqui esta o seu mapa para atacar:\n",player1.getNome().c_str());
      player1.getMapa()->desenharMapa();

      printf("Escolha um ponto de ataque(digite apenas os valores de x e y separados por espaco):\n");
      cin >>x>>y;

      printf("\033[2J\033[1;1H");

      saberSeVidaOponenteSeraReduzida = player1.getMapa()->atacarPontoNoMapa(x,y);

      if(saberSeVidaOponenteSeraReduzida=='D' || saberSeVidaOponenteSeraReduzida=='S'){
        player2PerdeuGame = player2.perderVida();
        if(player2PerdeuGame)
          break;
      }

      player1.getMapa()->desenharMapa();
      printf("Pressione qualquer tecla [a-z] para passar a vez\n");
      scanf("%*s");
      //______________________________ PLAYER 2 GAME
      printf("Player : %s , aqui esta o seu mapa para atacar:\n",player2.getNome().c_str());
      player2.getMapa()->desenharMapa();

      printf("Escolha um ponto de ataque(digite apenas os valores de x e y separados por espaco):\n");
      cin >>x>>y;

      printf("\033[2J\033[1;1H");

      saberSeVidaOponenteSeraReduzida = player2.getMapa()->atacarPontoNoMapa(x,y);

      if(saberSeVidaOponenteSeraReduzida=='D' || saberSeVidaOponenteSeraReduzida=='S'){
        player1PerdeuGame = player1.perderVida();
        if(player1PerdeuGame)
          break;
      }

      player2.getMapa()->desenharMapa();
      printf("Pressione qualquer tecla [a-z] para passar a vez\n");
      scanf("%*s");

    }
    if(player2PerdeuGame){
      shi pts = player1.ganharJogo();
      player2.perderJogo(pts);
    }else{
      shi pts = player2.ganharJogo();
      player1.perderJogo(pts);
    }
    return 0;
}
