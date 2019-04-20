#include <iostream>
#include <string>
#include <fstream>
#include "embarcacoes.hpp"
#include "canoa.hpp"
using namespace std;

int main(){
    Canoa canoa1(2,2);
    char l = canoa1.checarSeFuiAtacado(2,2);
    return 0;
}
