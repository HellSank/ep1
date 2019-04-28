#ifndef MAPA_HPP
#define MAPA_HPP
#include "canoa.hpp"
#include "submarino.hpp"
#include "portaAvioes.hpp"
using namespace std;
using shi = short int;
class Mapa{
  private:
    vector<Canoa>canoas;
    vector<Submarino>submarinos;
    vector<PortaAvioes>portaAvioes;
    // A -> Agua ; S -> Submarino; P -> PortaAvioes; C-> Canoa; ?->Nao sabe; D -> Destroco
    char body[20][20];
  public:
    Mapa();
    ~Mapa();
    //________

    void setCanoas(Canoa canoas);

    void setSubmarinos(Submarino submarinos);

    void setPortaAvioes(PortaAvioes portaAvioes);
    //_________
    void desenharMapa();
    char atacarPontoNoMapa(shi x, shi y);
    shi vidaTotalDoMapa();
};


#endif
