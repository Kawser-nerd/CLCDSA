/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

typedef long long ll;

int n;
string s, t, rs, rt;
ll res;

ll get( string s ) {
  stringstream ss(s);
  ll x;
  ss >> x;
  return x;
}

void go( int i, string sa, string ta, int eq ) {
  if (i == n) {
    ll a = get(sa), b = get(ta);
    if (mp(abs(a - b), mp(sa, ta)) < mp(res, mp(rs, rt)))
      res = abs(a - b), rs = sa, rt = ta;
    return;
  }
  //printf("%s %s : %d : %c, %c\n", sa.c_str(), ta.c_str(), eq, s[i], t[i]);
  if (isdigit(s[i]) && isdigit(t[i]))
    go(i + 1, sa + s[i], ta + t[i], eq ? eq : (s[i] > t[i] ? 1 : (s[i] < t[i] ? -1 : 0)));
  else if (s[i] == '?' && t[i] == '?') {
    if (eq > 0)
      go(i + 1, sa + '0', ta + '9', eq);
    else if (eq < 0)
      go(i + 1, sa + '9', ta + '0', eq);
    else {
      go(i + 1, sa + '0', ta + '0', eq);
      if (!eq) {
        go(i + 1, sa + '1', ta + '0', +1);
        go(i + 1, sa + '0', ta + '1', -1);
      }
    }
  } else if (s[i] == '?') {
    if (eq > 0) 
      go(i + 1, sa + '0', ta + t[i], eq);
    else if (eq < 0) 
      go(i + 1, sa + '9', ta + t[i], eq);
    else {
      go(i + 1, sa + t[i], ta + t[i], 0);
      if (t[i] > '0') go(i + 1, sa + (char)(t[i] - 1), ta + t[i], -1);
      if (t[i] < '9') go(i + 1, sa + (char)(t[i] + 1), ta + t[i], +1);
    }
  } else {
    if (eq > 0) 
      go(i + 1, sa + s[i], ta + '9', eq);
    else if (eq < 0) 
      go(i + 1, sa + s[i], ta + '0', eq);
    else {
      go(i + 1, sa + s[i], ta + s[i], 0);
      if (s[i] > '0') go(i + 1, sa + s[i], ta + (char)(s[i] - 1), +1);
      if (s[i] < '9') go(i + 1, sa + s[i], ta + (char)(s[i] + 1), -1);
    }
  }
}

void solve() {
  cin >> s >> t;
  n = s.size();
  res = 8e18;
  go(0, "", "", 0);
  printf("%s %s\n", rs.c_str(), rt.c_str());
}

int main() {
  int n;
  scanf("%d ", &n);
  for (int i = 1; i <= n; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}
