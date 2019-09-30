#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef long long ll;

ll f(ll n, int base) {
  ll x = 1, res = 0;
  REP(i,20) {
    if ((n >> i) & 1) res += x;
    x *= base;
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int N, J;
    cin >> N >> J;
    cout << "Case #" << cas << ":" << endl;
    REP(i,J) {
      ll num = i * 2 + 3;
      string s(N / 2, '0');
      REP(j,N/2) if ((num >> j) & 1) s[j] = '1';
      while (s.back() == '0') s.pop_back();
      reverse(ALL(s));
      cout << s << string(N - s.size() * 2, '0') << s;
      for (int j = 2; j <= 10; ++j)
        cout << " " << f(num, j);
      cout << endl;
    }
  }
  return 0;
}
