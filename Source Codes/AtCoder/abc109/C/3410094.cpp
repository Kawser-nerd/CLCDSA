#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <numeric>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()


using namespace std;

int gcd(int x, int y){
  if (y > x) {
    int k = y;
    y = x;
    x = k;
  }
  int r;
  while((r = x % y) != 0) {
    x = y;
    y = r;
  }
  return y;
}

int lcm(int x, int y){
  return (x * y / gcd(x, y));
}

int main(void){
  int n, x;
  cin >> n >> x;
  int tmpg;
  rep(i, n) {
    int a;
    cin >> a;
    if (i == 0) tmpg = abs(x - a);
    else tmpg = gcd(tmpg, abs(x - a));
  }
  cout << tmpg;
}