#include <iostream>
#include <string>
#include <fstream>
#include "embarcacoes.hpp"
#include "canoa.hpp"
#include "portaAvioes.hpp"
#include "submarino.hpp"
using namespace std;

int main(){
    Canoa canoa1(2,2);
    canoa1.checarSeFuiAtacado(2,2);
    PortaAvioes porta1(5,5,'N');
    porta1.checarSeFuiAtacado(5,6);
    porta1.checarSeFuiAtacado(0,0);
    Submarino sub1(3,3,'S');
    sub1.checarSeFuiAtacado(3,2);
    sub1.checarSeFuiAtacado(3,2);
    return 0;
}
