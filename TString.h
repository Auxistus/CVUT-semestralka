#ifndef __TSTRING_H
#define __TSTRING_H
#include <string.h>
#include <iostream.h>

class TString {
  char *ptr;
  int len;
public:
  TString(char *txt);
  TString(int size = 100);
  TString(const TString&);
  ~TString();
  int length();
  TString copy(int od, int n);
  int charAt(char c);
  char& operator[](int i);
  TString operator+(const TString &s);
  TString operator+(char *s);
  TString operator+(char c);
  TString& operator=(const TString &s);
  bool operator==(const TString &s);
  bool operator!=(const TString &s);
  operator char*();
  friend ostream& operator<<(ostream &o, const TString &s);
};
#endif
