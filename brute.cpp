#include "project2.h"
using namespace std; 

int brute(string T, string P);

int brute(string T, string P) {
  /** Your code goes here */
  int match =-1;
  int text_len = T.length();
  int patt_len = P.length();
  for(int i =0;i<text_len;i++){
    int j=0;
    for(;j<patt_len;j++){
      if(T[i+j] != P[j]) break;
    }
    if(j == patt_len) return i;
  }
  return -1;
}


