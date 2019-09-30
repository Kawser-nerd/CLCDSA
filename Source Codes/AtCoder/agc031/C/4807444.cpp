#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector
#define pb push_back
#define ll long long

vec<vec<int>> solve(vec<int> a, vec<int> b)
{
  if (a.size() == 1) {
    vec<vec<int>> c(0);
    c.pb(a);
    c.pb(b);
    return c;
  }

  int bit = - 1;
  vec<int> a_(a.size() - 1), b_(b.size() - 1);
  rep(i, a.size()) {
    a_[i] = a[i];
    b_[i] = b[i];
    if (a[i] != b[i]) {
      bit = i;
      break;
    }
  }
  for (int i = bit; i < a.size() - 1; i++) {
    a_[i] = a[i + 1];
    b_[i] = b[i + 1];
  }
  vec<int> m_(a.size() - 1);
  rep(i, a.size() - 1) m_[i] = a_[i];
  m_[0] = 1 - a_[0];
  auto l = solve(a_, m_);
  auto r = solve(m_, b_);
  vec<vec<int>> c(l.size() + r.size(), vec<int>(l[0].size() + 1));
  rep(i, l.size()) {
    for (int j = 0; j < bit; j++) c[i][j] = l[i][j];
    c[i][bit] = a[bit];
    for (int j = bit; j < l[i].size(); j++) c[i][j + 1] = l[i][j];
  }
  rep(i, r.size()) {
    for (int j = 0; j < bit; j++) c[l.size() + i][j] = r[i][j];
    c[l.size() + i][bit] = b[bit];
    for (int j = bit; j < r[i].size(); j++) c[l.size() + i][j + 1] = r[i][j];
  }
  return c;
}

int main(void)
{
  int n;
  cin >> n;
  ll A, B;
  cin >> A >> B;
  vec<int> a(n), b(n);
  int counta = 0, countb = 0;
  rep(i, n) {
    a[i] = (A >> i) % 2;
    b[i] = (B >> i) % 2;
    counta += a[i];
    countb += b[i];
  }
  if (counta % 2 == countb % 2) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  vec<vec<int>> ans = solve(a, b);
  rep(i, ans.size()) {
    ll ret = 0;
    rep(j, n) ret += ans[i][j] ? ((ll)1 << (ll)j) : 0;
    cout << ret;
    if (i == ans.size() - 1) cout << endl;
    else cout << " ";
  }
  return 0;
}