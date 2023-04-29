#include <iostream>
#include <string> 

#include "project2.h"
using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 4) {
    cout << "Please use 3 arguments as input: T P alg" << endl;
    cout << "alg should be one of ['kmp', 'bmh', 'brute']" << endl;
    return -1; 
  }
  string T = argv[1];
  string P = argv[2];
  string alg = argv[3];

  if (alg == "kmp") 
    cout << kmp(T, P) << endl;
  else if (alg == "bmh")
    cout << bmh(T, P) << endl;
  else if (alg == "brute")
    cout << brute(T, P) << endl;
  else
    cerr << "Unspecified algorithm type. Must be one of ['kmp', 'bmh', 'brute']" << endl;
  return 0;
}