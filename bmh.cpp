#include "project2.h"
#include<vector>
#include<stdio.h>
#include<iostream>
using namespace std; 

int bmh(string T, string P);

void fill_bad_table(vector<int>&bad_table, string P, int n){
  for(int i=0;i<n-1;i++){
    
    bad_table[(int)P[i]] = i;
  }
}
int check_full_string(string P, string T, int plen , int tlen){
  int temp = tlen;
  while(P[plen] == T[tlen] && plen > 0 && tlen > 0){
      plen--;
      tlen--;
  }
  if(plen == 0) return temp;
  return tlen;

}

int bmh(string T, string P) {
  /** Your code goes here */
  int txt_len = T.length();
  int patt_len = P.length();
  int ans =-1;
  vector<int>bad_table(128,-1);

  fill_bad_table(bad_table,P,patt_len);

  int j = patt_len -1;
  int i = j;
  int mis =0;
  while(i < txt_len){
    if(P[j] == T[i]){
      if(j ==0) return i;
      else{
        i--;
        j--;
      }
      } 
      else{
        //find mismtach location
        int new_loc = bad_table[(int)T[i]];
        i = i + patt_len - min(j,new_loc+1);
        j = patt_len-1;
      }
    
   
    // cout<<"val of j: "<<j<<endl;
  }

  return -1;
}

