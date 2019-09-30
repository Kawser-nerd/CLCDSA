#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <utility>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define MOD 1000000007

int main(int argc, char const *argv[]) {
  int i,o,t,j,l,s,z;
  cin >> i >> o >> t >> j >> l >> s >> z;
  long k = 0;
  k += o;
  k += (i - i%2);
  k += (j - j%2);
  k += (l - l%2);
  int amari = 0;
  amari += i%2;
  amari += j%2;
  amari += l%2;
  if(amari == 3) k += 3;
  if(amari == 2){
    if(i%2 == 1 && j%2 == 1 && l > 0) k += 1;
    if(j%2 == 1 && l%2 == 1 && i > 0) k += 1;
    if(l%2 == 1 && i%2 == 1 && j > 0) k += 1;
  }
  cout << k << endl;
}