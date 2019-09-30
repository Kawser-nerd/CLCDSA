#include <algorithm>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

#define REP(i, a, b) for (int i = a; i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define dump(c) cerr << "> " << #c << " = " << (c) << endl;

#define ll long long

using namespace std;

int main() {
  ll n,a,b,x,sum;
  a = sum = 0;
  x = 0;
  cin >> n;
  rep(i,n){
    cin >> b;
    if(b>a){
      x += 1;
    }else{
      x = 1;
    }
    sum += x;
    a = b;
  }
  cout << sum << endl;
  return 0;
}