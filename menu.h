#ifndef __MENU_H
#define __MENU_H
#include "TString.h"
#include <iostream.h>

const int MAXPRVKU = 5;

class Menu {
protected:
  TString uvodniText;
  char *nabidka[MAXPRVKU];
  char *vyzva;
  int pocetPrvku;
public:
  Menu();
  ~Menu();
  void vlozUvodniText(char *txt);
  void vlozUvodniText(TString txt);
  void vlozNabidku(char *txt);
  void vlozNabidku(TString txt);
  void vlozVyzvu(char *txt);
  int vyzadejVolbu(bool uvText);
};

#endif
