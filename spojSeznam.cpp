#include "spojSeznam.h"

Item* List::findItem(char *N) {
  Item *tmp = F;
  while (tmp!=NULL) {
    if (strcmp(N,tmp->name)==0) {
      return tmp;
    }
    tmp = tmp->next;
  }
}

Item* List::lastButOne(Item *last) {
  Item *tmp = F;
  while (tmp!=NULL) {
    if (tmp->next==last) {
      return tmp;
    }
    tmp = tmp->next;
  }
}

List::List() {
  L = new Item('\0',0,0,0);
  F = new Item('\0',0,0,0);
}

List::~List() {
  delete L;
  delete F;
}

void List::append(char *N, int A, int D, int P) {
  char *pom = new char[strlen(N)+1];
  strcpy(pom,N);
  Item *tmp = new Item(pom,A,D,P);
  L->next = tmp;
  L = tmp;
  if (F->next==NULL) {
    F->next = tmp;
    F = tmp;
  }
}

void List::inFront(char *N,int A, int D, int P) {
  Item *tmp = new Item(N,A,D,P);
  if (F->next==NULL) {
    L->next = tmp;
    L = tmp;
  }
  tmp->next = F;
  F = tmp;
}

void List::insert(char *N, int A, int D, int P, Item *I) {
  Item *tmp = new Item(N,A,D,P,I->next);
  I->next = tmp;
}

void List::removeFirst() {
  Item *tmp = F;
  F = F->next;
  delete tmp;
}

void List::removeLast() {
  Item *tmp = L;
  L = lastButOne(L);
  delete tmp;
}

void List::remove(Item *I) {
  Item *tmp = lastButOne(I);
  tmp->next = I->next;
  delete I;
}

Item* List::getFirst() {
  return F;
}

Item* List::getLast() {
  return L;
}

int List::getItemCount() {
  int count = 0;
  Item *tmp = F;
  while (tmp!=NULL) {
    count++;
    tmp = tmp->next;
  }
  return count;
}

Item& List::operator[](int idx) {
  Item *tmp = F;
  for(int i=1;i<=idx;i++) {
    tmp = tmp->next;
    if (tmp==NULL || idx<0) throw "index je mimo rozsah seznamu";
  }
  return *tmp;
}

ostream& operator<<(ostream &o, const List &list) {
  Item *tmp = list.F;
  if (tmp->next==NULL) o << "Seznam je prazdny.\n";
  else {
    int i=1;
    while (tmp!=NULL) {
      o << i<<"..."<<tmp->name<<" Utok: "<<tmp->attack<<" Obrana: "<<tmp->defence<<" Cena: "<<tmp->price<<'\n';
      i++;
      tmp = tmp->next;
    }
  }
  return o;
}
