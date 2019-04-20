#include "embarcacoes.hpp"
#ifndef PORTAAVIOES_HPP
#define PORTAAVIOES_HPP
using namespace std;
class PortaAvioes : public Embarcacoes{
  public:
    PortaAvioes(shi x, shi y , char direcao);
    ~PortaAvioes();
    char usarHabilidadeEspecial();
};
#endif
