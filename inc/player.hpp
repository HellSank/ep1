#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "mapa.hpp"

class Player{
  private:
    string nome;
    shi pontosDeVida;
    shi pontuacao;
    Mapa *mapaParaAtacar;
    void iniciarPontosDeVida();
  public:
    shi ganharJogo();
    void perderJogo(shi pontosAdversario);
    void verSignificadoDasNotacoes();
    bool perderVida();
    //________ Getters and Setters || Construtor
    Player(string nome,Mapa *mapaParaAtacar);
    ~Player();

    string getNome();
    void setNome(string nome);

    Mapa *getMapa();
    void setMapa(Mapa *mapaParaAtacar);

    shi getPontosDeVida();
    void setPontosDeVida(shi pontosDeVida);

    shi getPontuacao();
};

#endif
