#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector
#define ll long long

ll p[51], s[51];

ll solve(ll i, ll x)
{
  if (!i) return x;
  else if (x <= 1) return 0;
  else if (x <= s[i - 1] + 1) return solve(i - 1, x - 1);
  else if (x <= s[i] - 1) return p[i - 1] + 1 + solve(i - 1, x - s[i - 1] - 2);
  else return p[i];
}

int main(void)
{
  ll n, x;
  cin >> n >> x;

  p[0] = 1;
  s[0] = 1;
  rep(i, 50) {
    p[i + 1] = p[i] * 2 + 1;
    s[i + 1] = s[i] * 2 + 3;
  }

  cout << solve(n, x) << endl;

  return 0;
}