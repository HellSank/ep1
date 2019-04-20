#include "embarcacoes.hpp"
#ifndef PORTAAVIOES_HPP
#define PORTAAVIOES_HPP
class PortaAvioes : public Embarcacoes{
  public:
    PortaAvioes(shi x, shi y , char direcao);
    ~PortaAvioes();
  protected:
    char usarHabilidadeEspecial();
};
#endif
