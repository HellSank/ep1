#ifndef CANOA_HPP
#define CANOA_HPP
#include"embarcacoes.hpp"

class Canoa: public Embarcacoes{
  public:
    Canoa(shi x,shi y);
    ~Canoa();
  protected:
    char usarHabilidadeEspecial();
};

#endif
