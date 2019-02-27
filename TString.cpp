#include "TString.h"

TString::TString(char *txt) {
  len = strlen(txt);
  ptr = new char[len+1];
  strcpy(ptr,txt);
}

TString::TString(int size) {
  len = size;
  ptr = new char[len+1];
  for(int i=0;i<=len;i++) ptr[i] = '\0';
}

TString::TString(const TString &s) {
  len = s.len;
  ptr = new char[len+1];
  strcpy(ptr,s.ptr);
}

TString::~TString() {
  delete [] ptr;
}

int TString::length() {
  return len;
}

TString TString::copy(int od, int n) {
  if (od<0) return "";
  TString *novy = new TString(n);
  for(int i=0;i<n;i++) {
    novy->ptr[i] = ptr[od+i];
  }
  return *novy;
}

int TString::charAt(char c) {
  for(int i=0;i<len;i++) {
    if (ptr[i]==c) return i;
  }
  return 0;
}

char& TString::operator[] (int i) {
  if (i<0 || i>length()) throw "index mimo rozsah";
  return ptr[i];
}

TString TString::operator+(const TString &s) {
  TString st(len + s.len);
  strcpy(st.ptr,ptr);
  strcat(st.ptr,s.ptr);
  return st;
}

TString TString::operator+(char *s) {
  TString st(len + strlen(s));
  strcpy(st.ptr,ptr);
  strcat(st.ptr,s);
  return st;
}

TString TString::operator+(char c) {
  TString st(len + 1);
  strcpy(st.ptr,ptr);
  strcat(st.ptr,&c);
  return st;
}

TString& TString::operator=(const TString &s) {
  delete[] ptr;
  len = s.len;
  ptr = new char[len+1];
  strcpy(ptr,s.ptr);
  return *this;
}

bool TString::operator==(const TString &s) {
  bool pravda = true;
  if (len!=s.len) return false;
  for(int i=0;i<s.len;i++) {
    if (ptr[i]!=s.ptr[i]) pravda = false;
  }
  return pravda;
}

bool TString::operator!=(const TString &s) {
  bool pravda = false;
  if (len!=s.len) return true;
  for(int i=0;i<s.len;i++) {
    if (ptr[i]!=s.ptr[i]) pravda = true;
  }
  return pravda;
}

TString::operator char*() {
  char *pom = new char[len+1];
  strcpy(pom,ptr);
  return pom;
}

ostream& operator<<(ostream &o, const TString &s) {
  o << s.ptr;
  return o;
}
