#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[]) {
  ll A, B, C, K;
  cin >> A >> B >> C >> K;
  if (K % 2 == 0) {
    ll ans = A - B;
    if (abs(ans) > pow(10, 18)) {
      cout << "unfair" << endl;
    } else {
      cout << ans << endl;
    }
  } else {
    ll ans = B - A;
    if (abs(ans) > pow(10, 18)) {
      cout << "unfair" << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}