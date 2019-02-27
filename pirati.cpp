#include "pirati.h"

Pirati::Pirati(char *jmeno, Lod *nepritel, int pocet):Lokace(jmeno) {
  pocetPiratu = pocet;
  menu.vlozNabidku("1...Utect z bojiste");
  menu.vlozNabidku("2...Zautocit na piraty");
  pirat = nepritel;
}

Lokace* Pirati::cestovani() {
  cout << "\nKam cestovat?\n";
  for(int i=1;i<=travelSize;i++) {
    cout << i<<"..."<<(travelling[i-1]->nazev)<<"\n";
  }
  cout << "Vase volba: ";
  int cislo;
  do {
    cin >> cislo;
    if (mimoRozsah(cislo,travelSize)) {
      cislo = 0;
    }
  }while (cislo<1);

  switch (cislo) {
    case 1: return travelling[0];
    case 2: return travelling[1];
    case 3: return travelling[2];
    case 4: return travelling[3];
  }
}

int Pirati::rozhodnuti(Lod &starship, int cislo) {
  int vrat = 0;
  switch (cislo) {
    case 2: {
      srand(time(0));
      int nahUtok;
      int nahObrana;
      int uder;
      int maxPocPiratu = pocetPiratu;
      int a = 2;
      do {
        switch (a) {
          case 1: {
            cout << "\n\"Tohle nevypada dobre. Radsi vypadnem.\"\n\n";
            break;
          }
          case 2: {
            cout << "\nPocet nepratel: " << pocetPiratu << endl;
            nahUtok = rand() % starship.utok;
            nahObrana = abs((rand() % pirat->obrana)/10);
            uder = abs(nahUtok-nahObrana);
            pirat->hitPoints -= uder;
            cout << "Zasahl jste nepritele za " << uder << " HP\n";
            if (pirat->hitPoints <= 0) {
              pocetPiratu--;
              starship.penize += pirat->penize;
              cout << "\"Jedhoho mame z krku.\"\n";
              pirat->hitPoints = pirat->maxHP;
            }
            if (pocetPiratu == 0) {
              cout << "Vyhral jste.\n";
              vrat = 1;
            }
            else {
              nahUtok = rand() % pirat->utok;
              nahObrana = abs((rand() % starship.obrana)/10);
              uder = abs(nahUtok-nahObrana);
              starship.hitPoints -= uder;
              cout << "Nepritel strili a zasahuje vas za " << uder << "HP\n";
              cout << "Vas stav HP: " << starship.hitPoints << endl;
              if (starship.hitPoints <= 0) {
                cout << "Byl jste znicen.\n\nKONEC HRY";
                exit(0);
              }
            }
            break;
          }
        }
        if (pocetPiratu > 0) {
          if (a == 1) break;
          a = menu.vyzadejVolbu(false);
        }
      }while(pocetPiratu > 0 && starship.hitPoints > 0);
      if (pirat->respawn) pocetPiratu = maxPocPiratu;
    }
  }
  return vrat;
}
