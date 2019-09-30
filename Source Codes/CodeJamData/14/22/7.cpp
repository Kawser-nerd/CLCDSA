#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;

string A, B, K;

string getb() {
  int x;
  string S(30, '0');
  cin >> x;
  for(int i = 0; i < 30; i++) {
    if(x & 1 << i) {
      S[29 - i] = '1';
    }
  }
  return S;
}

long long memo[30][2][2][2];

long long solve(int x, bool ona, bool onb, bool onk) {
  if(x == 30) return ona || onb || onk ? 0 : 1;

  long long& ref = memo[x][ona][onb][onk];
  if(ref != -1) return ref;

  ref = 0;
  for(int a = 0; a < 2; a++) {
    if(ona && a == 1 && A[x] == '0') continue;
    for(int b = 0; b < 2; b++) {
      if(onb && b == 1 && B[x] == '0') continue;

      int k = a & b;
      if(onk && k == 1 && K[x] == '0') continue;

      ref += solve(x + 1, ona && '0' + a == A[x],
                          onb && '0' + b == B[x],
                          onk && '0' + k == K[x]);
    }
  }
  return ref;
}

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    printf("Case #%d: ", t);

    A = getb();
    B = getb();
    K = getb();

    memset(memo, -1, sizeof(memo));
    printf("%lld\n", solve(0, true, true, true));
  }
  return 0;
}
