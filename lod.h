#include "TString.h"

class Lod {
public:
  TString nazev;
  int maxHP;
  int hitPoints;
  int utok;
  int obrana;
  int penize;
  bool respawn;
  Lod(char *jmeno, int hp, int attack, int defence, int money, bool respwn);
  ~Lod();
  void kontrolaHP();
  void kontrolaUtoku();
  void kontrolaObrany();
};
