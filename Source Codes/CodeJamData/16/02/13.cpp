#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    string s;
    cin >> s;
    int n = s.size(), res = 0;
    s += "+";
    REP(i,n) res += (s[i] != s[i+1]);
    cout << "Case #" << cas << ": " << res << endl;
  }
  return 0;
}
