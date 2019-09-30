#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[]) {
  ll N;
  cin >> N;
  ll ans = N;
  for (ll i = 0; i <= N; i++) {
    int cc = 0;
    int t = i;
    while (t > 0) {
      cc += t % 6;
      t = t / 6;
    }
    t = N - i;
    while (t > 0) {
      cc += t % 9;
      t = t / 9;
    }
    if (ans > cc) ans = cc;
  }
  cout << ans << endl;
}