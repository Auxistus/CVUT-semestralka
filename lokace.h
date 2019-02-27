#ifndef __LOKACE_H
#define __LOKACE_H
#include "TString.h"
#include <fstream.h>
#include <cstdlib> //<stdlib.h>
#include <ctime> //<time.h>
#include "menu.h"
#include "lod.h"

class Lokace {
protected:
  Menu menu;
  Lokace **travelling;
  int travelSize;
public:
  TString nazev;
  Lokace(char *jmeno);
  virtual ~Lokace();
  int volba(bool uvText);
  bool mimoRozsah(int cislo, int omezeni);
  void naplnTravelling(int n, Lokace *a, Lokace *b=NULL, Lokace *c=NULL, Lokace *d=NULL);
  virtual Lokace* cestovani() = 0;
  virtual int rozhodnuti(Lod &starship, int cislo) = 0;  //vraci 0 pro bezny prubeh nebo 1 pro zvlastni situace
};
#endif
