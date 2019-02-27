#include "menu.h"

static char* novyStr(char *txt) {
  char *pom = new char[strlen(txt)+1];
  strcpy(pom,txt);
  return pom;
}

static char* novyStr(TString txt) {
  char *pom = new char[txt.length()+1];
  for(int i=0;i<txt.length();i++) pom[i] = txt[i];
  return pom;
}

Menu::Menu() {
  pocetPrvku = 0;
  vyzva = "Vase volba: ";
}

Menu::~Menu() {
  for (int i=0;i<pocetPrvku;i++) {
    delete [] nabidka[i];
    nabidka[i] = NULL;
  }
  delete vyzva;
}

void Menu::vlozUvodniText(char *txt) {
  uvodniText = txt;
}

void Menu::vlozUvodniText(TString txt) {
  uvodniText = txt;
}

void Menu::vlozNabidku(char *txt) {
  if (pocetPrvku<MAXPRVKU) {
    nabidka[pocetPrvku] = novyStr(txt);
    pocetPrvku++;
  }
}

void Menu::vlozNabidku(TString txt) {
  if (pocetPrvku<MAXPRVKU) {
    nabidka[pocetPrvku] = novyStr(txt);
    pocetPrvku++;
  }
}

void Menu::vlozVyzvu(char *txt) {
  vyzva = novyStr(txt);
}

int Menu::vyzadejVolbu(bool uvText) { //uvText urcuje, jestli se vypise i uvodniText
  int vol;
  if (uvText) cout << endl << uvodniText;
  for (int i=0;i<pocetPrvku;i++) {
    cout << nabidka[i] << endl;
  }
  cout << vyzva;
  do {
    cin >> vol;
    if (vol>pocetPrvku || vol<1) {
      cout << "Chybna volba.\n";
      vol = 0;
      cout << vyzva;
    }
  }while (vol<1);
  return vol;
}
