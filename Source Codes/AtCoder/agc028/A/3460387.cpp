#include <iostream>
#include <string>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
  if (a < b) return gcd(b, a);
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  string S, T;
  ll N, M, g;
  cin >> N >> M;
  cin >> S >> T;

  g = gcd(N, M);
  for (ll i = 0; i < g; i++) {
    if (S[i * N / g] != T[i * M / g]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << N * M / g << endl;
  return 0;
}