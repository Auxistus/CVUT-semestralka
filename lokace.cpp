#include "lokace.h"

Lokace::Lokace(char *jmeno) {
  nazev = jmeno;

  char radek[100] = "";
  char *soubor = new char[strlen(jmeno)+5];
  strcpy(soubor,jmeno);
  strcat(soubor,".txt");
  ifstream fin(soubor);
  if (fin.fail()) {
    cout << "Nelze otevrit soubor " << soubor << endl;
    exit(1);
  }
  TString text;
  while (fin.getline(radek,100)) {
    text = text + radek +"\n";
  }
  fin.close();

  menu.vlozUvodniText(text);
}

Lokace::~Lokace(){
  for(int i=0;i<travelSize;i++) {
    delete [] travelling[i];
    travelling[i] = NULL;
  }
}

int Lokace::volba(bool uvText) {
  int a = menu.vyzadejVolbu(uvText);
  return a;
}

bool Lokace::mimoRozsah(int cislo, int omezeni) {
  if (cislo>omezeni || cislo<1) {
    cout << "Chybna volba.\n";
    cout << "Vase volba :";
    return true;
  }else return false;
}

void Lokace::naplnTravelling(int n, Lokace *a, Lokace *b, Lokace *c, Lokace *d) {
  travelSize = n;
  travelling = new Lokace*[4];
  travelling[0] = a;
  travelling[1] = b;
  travelling[2] = c;
  travelling[3] = d;
}
