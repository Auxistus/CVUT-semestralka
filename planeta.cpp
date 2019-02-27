#include "planeta.h"

static int convInt(char *cislo) {
  int vysledek = 0;
  int delka = strlen(cislo);
  for(int i=delka-1;i>=0;i--) {
    vysledek += (int)(cislo[i]-'0')*pow(10,delka-1-i);
  }
  return vysledek;
}

Planeta::Planeta(char *jmeno):Lokace(jmeno) {
  menu.vlozNabidku("1...Opustit planetu");
  menu.vlozNabidku("2...Zajit do baru a pokecat s barmanem");
  menu.vlozNabidku("3...Nakoupit zbozi");
  menu.vlozNabidku("4...Opravit lod");

  /*inicializace zprav*/
  int idx = 0;
  char radek[100] = "";
  ifstream fin("zpravy.txt");
  if (fin.fail()) {
    cout << "Nelze otevrit soubor zpravy.txt" << endl;
    exit(1);
  }
  while (fin.getline(radek,100)) {
    if (radek[0]!='\0') {
      zpravy[idx] = zpravy[idx] + radek +"\n";
    }else idx++;
  }
  fin.close();
  pocetZprav = idx+1;

  /*inicializace obchodovani*/
  char nazev[100] = "";
  char utok[5] = "";
  char obrana[5] = "";
  char cena[10] = "";
  fstream in("obchod.txt");
  if (in.fail()) {
    cout << "Nelze otevrit soubor obchod.txt" << endl;
    exit(1);
  }
  pocetPolozek = 0;
  while (in.getline(nazev,100)) {
    in.getline(utok,5);
    in.getline(obrana,5);
    in.getline(cena,10);
    obchodnik.append(nazev,convInt(utok),convInt(obrana),convInt(cena));
    pocetPolozek++;
  }
  in.close();
}

Lokace* Planeta::cestovani() {
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

int Planeta::rozhodnuti(Lod &starship, int cislo) {
  switch (cislo) {
    case 2: bar();break;
    case 3: obchod(starship);break;
    case 4: oprava(starship);break;
  }
  return 0;
}

void Planeta::bar() {
  srand(time(0));
  int nahCislo;
  nahCislo = rand() % MAXPOCZPRAV;
  cout << endl << zpravy[nahCislo];
}

void Planeta::obchod(Lod &starship) {
  cout << endl;
  cout << obchodnik;
  cout << "\nVase parametry: Utok: "<<starship.utok<<" Obrana: "<<starship.obrana<<" Obnos: "<<starship.penize<<endl;
  cout << "Vase volba :";
  int cislo;
  do {
    cin >> cislo;
    if (mimoRozsah(cislo,pocetPolozek)) {
      cislo = 0;
    }
  }while (cislo<1);
  int suma;
  suma = obchodnik[cislo-1].price;
  if (starship.penize>=suma) {
    starship.penize -= suma;
    if (obchodnik[cislo-1].attack>0) starship.utok = obchodnik[cislo-1].attack;
    if (obchodnik[cislo-1].defence>0) starship.obrana = obchodnik[cislo-1].defence;
    cout << endl << obchodnik[cislo-1].name << " byl namontovan.\n";
  }else cout << "Na nakup zbozi nemate dost penez.";
}

void Planeta::oprava(Lod &starship) {
  int suma = (starship.maxHP - starship.hitPoints)*5;
  if (starship.penize>=suma) {
    starship.penize -= suma;
    starship.hitPoints = starship.maxHP;
    cout << "\nVse opraveno. Stalo vas to: "<<suma<< " kreditu.\n";
  }else cout << "Na opravu nemate dost penez.";
}
