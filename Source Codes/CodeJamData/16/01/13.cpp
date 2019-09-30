#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

string solve(int n) {
  if (n == 0) return "INSOMNIA";
  int s = 0, bit = 0;
  for (;;) {
    s += n;
    for (char c: to_string(s)) {
      int digit = c - '0';
      bit |= 1 << digit;
    }
    if (bit == 1023) return to_string(s);
  }
}

int main() {
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int n;
    cin >> n;
    cout << "Case #" << cas << ": " << solve(n) << endl;
  }
  return 0;
}
