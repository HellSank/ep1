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
    //Mapa mapa1,mapa2;
    short int x,y,contador=0;
    string line;
    ifstream arquivo("doc/map_1.txt");
    if(arquivo.fail()){
      cout<<"Erro"<<endl;
      exit(1);
    }
    cout << "Nao erro"<<endl;
    // ---> Inicio da leitura do arquivo
    while (!arquivo.eof()) {
      contador++;
      getline(arquivo,line);
      if(contador>=8 and contador<=13){
        printf("%s\n",line.c_str());
      }
    }
/*
    Player player1("Diana",&mapa1);//Mapa 1 e do player Dante
    Player player2("Dante",&mapa2);//Mapa 2 e da player Diana
    // ---> Final da leitura do arquivo
    printf("Bem vindos a batalha naval Players\n");
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
*/    return 0;
}
