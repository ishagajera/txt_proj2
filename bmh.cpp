#include "project2.h"
#include<vector>
#include<stdio.h>
#include<iostream>
using namespace std; 

int bmh(string T, string P);

void fill_bad_table(vector<int>&bad_table, string P, int n){
  for(int i=0;i<n-1;i++){
    
    bad_table[(int)P[i]] = n - i -1;
  }
  // cout<<"printing bad table:\n";
  // for(int i=0;i<127;i++){
  //   cout<<bad_table[i]<<" "; 
  // }

}
int check_full_string(string P, string T, int plen , int tlen){
  int temp = tlen;
  while(P[plen] == T[tlen] && plen > 0 && tlen > 0){
      plen--;
      tlen--;
  }
  if(tlen == 0) return temp;
  return tlen;

}

int bmh(string T, string P) {
  /** Your code goes here */
  int txt_len = T.length();
  int patt_len = P.length();
  int ans =-1;
  vector<int>bad_table(128,patt_len);

  fill_bad_table(bad_table,P,patt_len);

  int j = patt_len -1;
  int mis =0;
  while(j < txt_len){
    if(P[patt_len-1] == T[j]){
      mis = check_full_string(P,T,patt_len-1,j);
      // cout<<"value of mis is: "<<mis<<endl;
      // cout<<"new val j: "<<j<<"\n val of pattlen: "<<patt_len<<endl;
      if(j - mis == patt_len-1){
        if(P[0] != T[mis]) return -1;
         return mis;
      } 
      else{
        //find mismtach location
        int new_loc = bad_table[(int)T[mis]];
        j += new_loc;
      }
    }
    else{
       int new_loc = bad_table[(int)T[j]];
        j += new_loc;
    }
    // cout<<"val of j: "<<j<<endl;

  }

  return -1;
}

