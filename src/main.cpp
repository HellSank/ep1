#include <iostream>
#include <string>
#include <fstream>

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
    mapa1.setCanoas(Canoa(8,10));
    mapa1.setCanoas(Canoa(10,10));
    mapa1.setCanoas(Canoa(5,12));
    mapa1.setCanoas(Canoa(12,12));
    mapa1.setSubmarinos(Submarino(5,2,'L'));
    mapa1.setSubmarinos(Submarino(1,4,'L'));
    mapa1.setSubmarinos(Submarino(10,7,'L'));
    mapa1.setSubmarinos(Submarino(6,12,'L'));
    mapa1.setPortaAvioes(PortaAvioes(7,2,'S'));
    mapa1.setPortaAvioes(PortaAvioes(5,9,'L'));

    Player player1("Diana",mapa1);

    mapa2.setCanoas(Canoa(7,0));
    mapa2.setCanoas(Canoa(12,1));
    mapa2.setCanoas(Canoa(10,6));
    mapa2.setCanoas(Canoa(12,7));
    mapa2.setCanoas(Canoa(2,11));
    mapa2.setCanoas(Canoa(11,12));
    mapa2.setSubmarinos(Submarino(1,6,'L'));
    mapa2.setSubmarinos(Submarino(3,7,'L'));
    mapa2.setSubmarinos(Submarino(2,10,'L'));
    mapa2.setSubmarinos(Submarino(8,9,'L'));
    mapa2.setPortaAvioes(PortaAvioes(0,1,'S'));
    mapa2.setPortaAvioes(PortaAvioes(3,6,'L'));

    Player player2("Dante",mapa2);
    while (1) {
      /* code */
    }
    return 0;
}
