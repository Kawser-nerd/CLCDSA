#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int N;
double memo[1<<20];
double doit(int b) {
  double& ret = memo[b];
  if (ret != 0.0) return ret;
  if (b == (1<<N)-1) return 0.0;
  for (int i = 0; i < N; i++) {
    int cost = N, j;
    for (j = i; (b&(1<<j)); j = (j+1)%N)
      cost--;
    ret += cost + doit(b+(1<<j));
  }
  ret /= (double)N;
  return ret;
}

main() {
  int T, prob = 1;
  for (cin >> T; T--;) {
    string s;
    cin >> s;
    N = s.size();
    int b = 0;
    for (int i = 0; i < N; i++) {
      assert(s[i] == 'X' || s[i] == '.');
      if (s[i] == 'X') b += (1<<i);
    }
    memset(memo, 0, sizeof(memo));
    printf("Case #%d: %.12lf\n", prob++, doit(b));
  }
}
