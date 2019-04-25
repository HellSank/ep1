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

    /*char getEstadosDeUmPonto();
    void setEstadosDeUmPonto(char estadosDeUmPonto);
*/
    //vector<Canoa>getCanoas();
    void setCanoas(Canoa canoas);

    //vector<Submarino>getSubmarinos();
    void setSubmarinos(Submarino submarinos);

    //vector<PortaAvioes>getPortaAvioes();
    void setPortaAvioes(PortaAvioes portaAvioes);
    //_________
    void desenharMapa();
    void atacarPontoNoMapa(shi x, shi y);
    shi vidaTotalDoMapa();
};


#endif
