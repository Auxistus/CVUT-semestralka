#include <iostream.h>

struct Item {
  Item *next;
  char *name;
  int attack;
  int defence;
  int price;
  Item(char *N, int A, int D, int P, Item *n);
};

Item::Item(char *N, int A, int D, int P, Item *n = NULL) {
  name = N;
  attack = A;
  defence = D;
  price = P;
  next = n;
}

class List {
protected:
  Item *F, *L;
public:
  List();
  ~List();
  Item* findItem(char *N);
  Item* List::lastButOne(Item *last);
  void append(char *N, int A, int D, int P);
  void inFront(char *N,int A, int D, int P);
  void insert(char *N, int A, int D, int P, Item *I);
  void removeFirst();
  void removeLast();
  void remove(Item *I);
  Item* getFirst();
  Item* getLast();
  int getItemCount();
  Item& operator[](int idx);
  friend ostream& operator<<(ostream &o, const List &list);
};
