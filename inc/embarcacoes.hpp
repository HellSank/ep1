#ifndef EMBARCACOES_HPP
#define EMBARCACOES_HPP

#include<vector>
#include<iostream>
#include<tuple>
#include<utility>
using shi = short int;
using namespace std;
class Embarcacoes{

  private:
    shi numeroDeCasasOcupadas;
    vector<tuple<shi,shi,shi>> posicao_VidaDeCadaParte;
    pair<shi,shi>ponto;
    char direcao;
    shi vidaDeCadaParte;
  protected:
    virtual char usarHabilidadeEspecial()=0;
    void sofrerAtaque();

  public:
    Embarcacoes();
    ~Embarcacoes();
    //_______________
    shi getNumeroDeCasasOcupadas();
    void setNumeroDeCasasOcupadas(shi numeroDeCasasOcupadas);

    shi getVidaDeCadaParte();
    void setVidaDeCadaParte(shi vidaDeCadaParte);

    pair<shi,shi>getPonto();
    void setPonto(shi x,shi y);

    char getDirecao();
    void setDirecao(char direcao);
    //_______________
    shi vidaTotal();
    void posicionarEmbarcacao(shi x, shi y,char direcao);
    char checarSeFuiAtacado(shi x , shi y);
};
#endif
