#include <iostream>
#include <string>
#include <fstream>

#include "canoa.hpp"
#include "portaAvioes.hpp"
#include "submarino.hpp"

#include "mapa.hpp"
using namespace std;

int main(){
    Mapa mapa1;
    mapa1.setCanoas(Canoa(0,0));
    mapa1.setSubmarinos(Submarino(2,2,'L'));
    mapa1.atacarPontoNoMapa(3,2);
    mapa1.atacarPontoNoMapa(0,0);
    mapa1.desenharMapa();
    mapa1.atacarPontoNoMapa(3,2);
    mapa1.desenharMapa();
    return 0;
}
