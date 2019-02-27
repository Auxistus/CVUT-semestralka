#include "lokace.h"

class Pirati:public Lokace {
protected:
  Lod *pirat;
  int pocetPiratu;
public:
  Pirati(char *jmeno, Lod *nepritel, int pocet);
  Lokace* cestovani();
  int rozhodnuti(Lod &starship, int cislo);
};
