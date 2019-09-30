#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector
#define ll long long
#define ALL(a) a.begin(), a.end()

int main(void)
{
  int n, m;
  cin >> n >> m;
  vec<ll> x(m);
  rep(i, m) cin >> x[i];
  sort(ALL(x));

  vec<ll> d(m - 1);
  rep(i, m - 1) d[i] = x[i + 1] - x[i];
  sort(ALL(d));
  ll count = 0;
  rep(i, m - n) count += d[i];
  cout << count << endl;
  return 0;
}