#ifndef CANOA_HPP
#define CANOA_HPP
#include"embarcacoes.hpp"
using namespace std;

class Canoa: public Embarcacoes{
  public:
    Canoa(shi x,shi y);
    ~Canoa();
    char usarHabilidadeEspecial();
    shi vidaTotal();
};

#endif
