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
  long N,M;
  cin >> N >> M;
  if(N*2 >= M){
    cout << ((M-M%2)/2) << endl;
  }else{
    long amari = M - N*2;
    long ans = N + (amari - amari%4)/4;
    cout << ans << endl;
  }
}