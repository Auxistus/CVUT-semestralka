#include "planeta.h"
#include "pirati.h"

using namespace std;

const int MAXVYPRAVEC = 10;

TString vypravec[MAXVYPRAVEC];
int pocVypravec;
int aktIdx = 0;
int c;
Lod starship("Leviathan",300,25,50,2000,false);
Lod korsar("Pirat",60,10,10,200,true);
Lod lorsith("Lilian Lorsith",200,25,50,2000,false);
Lokace *lok;
Lokace *butcherbay = new Pirati("Butcherbay",&lorsith,1);
Lokace *argos5 = new Planeta("Argos V");
Lokace *newEden = new Planeta("New Eden");
Lokace *vega7 = new Planeta("Vega VII");
Lokace *moorSea = new Pirati("Moor Sea",&korsar,3);


void logo() {
   cout << "PRIMITIV Software\n";
   cout << "uvadi\n";
   cout << "\nOUTTER SPACE\n";
   cout << "------------\n";
}


void inicializace() {
  char radek[100] = "";
  ifstream fin("vypravec.txt");
  if (fin.fail()) {
    cout << "Nelze otevrit soubor vypravec.txt" << endl;
    exit(1);
  }
  int index = aktIdx;
  while (fin.getline(radek,100)) {
    if (radek[0]!='\0') {
      vypravec[index] = vypravec[index] + radek + "\n";
    }else index++;
  }
  fin.close();
  pocVypravec = index+1;

  /*urceni odkud kam bude mit hrac moznost pohybu*/
  argos5->naplnTravelling(2,vega7,moorSea);
  butcherbay->naplnTravelling(3,argos5,moorSea,vega7);
  vega7->naplnTravelling(2,argos5,moorSea);
  moorSea->naplnTravelling(2,argos5,vega7);
}


int main() {
  int rozh;

  logo();
  inicializace();

  cout << vypravec[aktIdx++];
  starship.hitPoints = 60;
  lok = argos5;
  do {
    c = lok->volba(true);
    switch (c) {
      case 1: {
        cout << endl << vypravec[aktIdx];
        lok = lok->cestovani();   //prvni moznost z nabidky je vzdy premistovani mezi lokacemi
      }break;
      default: lok->rozhodnuti(starship,c);
    }
  }while(lok != vega7);

  aktIdx++;
  cout << endl << vypravec[aktIdx++];
  argos5->naplnTravelling(3,vega7,moorSea,butcherbay);
  do {
    c = lok->volba(true);
    switch (c) {
      case 1: {
        lok = lok->cestovani();
      }break;
      default: lok->rozhodnuti(starship,c);
    }
  }while(lok != butcherbay);

  cout << endl << vypravec[aktIdx++];
  do {
    c = lok->volba(true);
    switch (c) {
      case 1: {
        lok = lok->cestovani();
      }break;
      default: {
        rozh = lok->rozhodnuti(starship,c);
        if (rozh == 1) {
          butcherbay->naplnTravelling(4,argos5,moorSea,vega7,newEden);
          cout << endl << vypravec[aktIdx];
        }
      }
    }
  }while(lok != newEden);

  cout << endl << vypravec[++aktIdx];
  cout << endl << vypravec[++aktIdx];

  cout << "\nKONEC HRY\n\n";
  cout << "Credits:\n  Namet: Jan Lomitzki\n  Scenar: Jan Lomitzki\n  ";
  cout << "Programator: Jan Lomitzki\n  Grafika: nikdo\n  Tester: Jan Lomitzki";

  return 0;
}
