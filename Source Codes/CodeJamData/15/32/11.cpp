#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    fprintf(stderr, "tc%d\n", tc);
    int K, L, S;
    char Kbuf[200], Lbuf[200];
    scanf("%d%d%d %s %s", &K, &L, &S, Kbuf, Lbuf);

    int prechody[111][111];
    for (int s = 0; s <= L; s++) {
      for (int p = 0; p < K; p++) {
        char pch = Kbuf[p];
        int r = 0;
        if (s < L && Lbuf[s] == pch) r = s+1;
        else for (int n = s; n > 0; n--) {
          if (n > L) continue;
          if (Lbuf[n-1] != pch) continue;
          int eq = true;
          for (int i = 0; i < n-1; i++) if (Lbuf[i] != Lbuf[s - n + 1 + i]) eq = false;
          if (!eq) continue;

          r = n;
          break;
        }
        prechody[s][p] = r;
      }
    }

    int maximum[111][111];
    double expect[111][111];
    for (int s = 0; s <= L; s++) maximum[S][s] = 0, expect[S][s] = 0;
    for (int pos = S-1; pos >= 0; pos--) {
      for (int s = 0; s <= L; s++) {
        maximum[pos][s] = 0;
        expect[pos][s] = 0;
        for (int p = 0; p < K; p++) {
          int ns = prechody[s][p];
          maximum[pos][s] = max(maximum[pos][s], (ns == L ? 1 : 0) + maximum[pos+1][ns]);
          expect[pos][s] += (ns == L ? 1 : 0) + expect[pos+1][ns];
        }
        expect[pos][s] /= K;
      }
    }

    double result = maximum[0][0] - expect[0][0];
    printf("Case #%d: %.12lf\n", tc, result);
  }
}
