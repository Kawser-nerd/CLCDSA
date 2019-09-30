#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector
#define ll long long
#define MOD 1000000007

int main(void)
{
  int n;
  cin >> n;
  vec<int> c(n + 1);
  c[0] = 200005;
  rep(i, n) cin >> c[i + 1];

  vec<ll> s(200010, 0);
  s[c[0]] = 1;
  rep(i, n) {
    if (c[i] != c[i + 1]) s[c[i + 1]] = (s[c[i + 1]] + s[c[i]] + MOD) % MOD;
  }
  cout << s[c[n]] % MOD << endl;
  return 0;
}