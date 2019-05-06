#include <iostream>
#include <string>
#include <fstream>
#include<unistd.h>

#include "canoa.hpp"
#include "portaAvioes.hpp"
#include "submarino.hpp"

#include "mapa.hpp"
#include "player.hpp"

#include "jogo.hpp"

using namespace std;

int main(){
    Jogo jogo;
    jogo.rodarOffline();
    return 0;
}
