#ifndef JOGO_HPP
#define JOGO_HPP

#include<unistd.h>

#include "mapa.hpp"
#include "player.hpp"
class Jogo{
  private:
    Player* player1 = new Player();
    Player* player2 = new Player();
    Mapa* mapa1 = new Mapa();
    Mapa* mapa2 = new Mapa();
    bool player1EVencedor;

    
    void configurarPlayer(Player* player,Mapa* mapa);
    void exibirPontuacao();

    bool rodarTurnoDoPlayer(Player* playerAtacante);
  public:
    Jogo();
    ~Jogo();
    void rodarOffline();
};
#endif
