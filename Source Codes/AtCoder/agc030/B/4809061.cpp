#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector
#define ll long long

int main(void)
{
  ll l;
  int n;
  cin >> l >> n;
  vec<ll> x(n), y(n);
  rep(i, n) cin >> x[i];
  rep(i, n) y[i] = l - x[n - 1 - i];
  vec<ll> sx(n + 1), sy(n + 1);
  sx[0] = 0; sy[0] = 0;
  rep(i, n) {
    sx[i + 1] = sx[i] + x[i];
    sy[i + 1] = sy[i] + y[i];
  }

  //a,b,c,d? b->a->c->d < b->c->a->d ???
  //??????reverse

  ll maxL = 0, maxR = 0;

  rep(i, n) {
    ll temp;
    if ((n - i) % 2) {
      temp = (sx[(n + i - 1) / 2] - sx[i]) * 2 + x[(n + i - 1) / 2] + sy[(n - i - 1) / 2] * 2;
    } else {
      temp = (sx[(n + i) / 2] - sx[i]) * 2 + sy[(n - i) / 2] * 2 - y[(n - i) / 2 - 1];
    }
    if (maxL < temp) maxL = temp;
  }

  rep(i, n) {
    ll temp;
    if ((n - i) % 2) {
      temp = (sy[(n + i - 1) / 2] - sy[i]) * 2 + y[(n + i - 1) / 2] + sx[(n - i - 1) / 2] * 2;
    } else {
      temp = (sy[(n + i) / 2] - sy[i]) * 2 + sx[(n - i) / 2] * 2 - x[(n - i) / 2 - 1];
    }
    if (maxR < temp) maxR = temp;
  }

  if (maxL > maxR) cout << maxL << endl;
  else cout << maxR << endl;
  return 0;
}