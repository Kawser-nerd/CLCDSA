#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector
#define pb push_back
#define ll long long
#define MOD 100000007
#define MAX 1000000000000

ll path(ll x, ll y, ll z)
{
  return abs(x - y) + abs(y - z);
}

int main(void)
{
  int a, b, q;
  cin >> a >> b >> q;

  vec<ll> s(a), t(b);
  rep(i, a) cin >> s[i];
  rep(i, b) cin >> t[i];

  rep(o, q) {
    ll x;
    cin >> x;
    auto its = lower_bound(s.begin(), s.end(), x);
    auto itt = lower_bound(t.begin(), t.end(), x);
    ll sr = its == s.end() ? MAX : *its;
    ll sl = its == s.begin() ? - MAX : *(--its);
    ll tr = itt == t.end() ? MAX : *itt;
    ll tl = itt == t.begin() ? - MAX : *(--itt);

    vec<ll> cand(0);
    cand.pb(path(x, sr, tr));
    cand.pb(path(x, sr, tl));
    cand.pb(path(x, sl, tr));
    cand.pb(path(x, sl, tl));
    cand.pb(path(x, tr, sr));
    cand.pb(path(x, tr, sl));
    cand.pb(path(x, tl, sr));
    cand.pb(path(x, tl, sl));
    cout << *min_element(cand.begin(), cand.end()) << endl;
  }
  return 0;
}