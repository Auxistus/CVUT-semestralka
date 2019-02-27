#include "lod.h"

Lod::Lod(char *jmeno, int hp, int attack, int defence, int money, bool respwn) {
  nazev = jmeno;
  maxHP = hp;
  hitPoints = maxHP;
  utok = attack;
  obrana = defence;
  penize = money;
  respawn = respwn;
}

Lod::~Lod() {
}

void Lod::kontrolaHP() {
  if (hitPoints < 0) hitPoints = 0;
  if (hitPoints > maxHP) hitPoints = maxHP;
}

void Lod::kontrolaUtoku() {
  if (utok < 0) utok = 0;
}

void Lod::kontrolaObrany() {
  if (obrana < 0) obrana = 0;
}
