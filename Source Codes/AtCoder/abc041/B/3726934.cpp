// Last Change:    12/06/2018 18:29:06.
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

#define BIG 1000000007

int main() {
  ll A, B, C, ans;
  cin >> A >> B >> C;
  A = A % BIG;
  B = B % BIG;
  C = C % BIG;
  ans = (A * B) % BIG;
  ans = (ans * C) % BIG;
  cout << ans << endl;
}