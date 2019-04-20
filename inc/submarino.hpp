#ifndef SUBMARINO_HPP
#define SUBMARINO_HPP
#include "embarcacoes.hpp"
class Submarino:public Embarcacoes{
  public:
    Submarino(shi x, shi y,char direcao);
    ~Submarino();
  protected:
    char usarHabilidadeEspecial();
};
#endif
