#include "project2.h"
#include <vector>
using namespace std;

int kmp(string T, string P);

vector<int> construct_lps(string P, int n){
  vector<int> res(n,0);
  int len =0;
  int i=1;
  while(i<n){
    if(P[len] == P[i]){
      len+=1;
      res[i] =len;
      i++; 
    }
    else{
      if(len != 0)
       len = res[len-1];
    
      else{
        res[i] = len;
        i++;
      }
    }
  }
  return res;
}

int kmp(string T, string P) {
  /** Your code goes here */
  int text_len = T.length();
  int patt_len = P.length();
  int ans =0;
  vector<int> lps = construct_lps(P,patt_len);
  int i = 0,j=0;
  while(i<text_len && j < patt_len){
    if(T[i] == P[j]){
      i++;
      j++;
    }
    if(j == patt_len) return i-j;
    else if(i < text_len && T[i] != P[j]){ 
      if(j !=0){
        j = lps[j-1];
      }
      else i++;

    }
  }
  return -1;
}
