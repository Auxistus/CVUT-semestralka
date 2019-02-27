#include "lokace.h"
#include "spojSeznam.h"
#include <math.h>

const int MAXPOCZPRAV = 4;

class Planeta:public Lokace {
  TString zpravy[MAXPOCZPRAV];
  int pocetZprav;
  List obchodnik;
  int pocetPolozek;
public:
  Planeta(char *jmeno);
  Lokace* cestovani();
  int rozhodnuti(Lod &starship, int cislo);
  void bar();
  void obchod(Lod &starship);
  void oprava(Lod &starship);
};
