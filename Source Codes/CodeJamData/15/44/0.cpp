#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline int mul(int a, int b) {
  return (long long)a * b % md;
}

inline int LCM(int a, int b) {
  for (int i = 1; ; i++) {
    if (i % a == 0 && i % b == 0) {
      return i;
    }
  }
}

int f[777][42][4];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 0; i <= r; i++) {
      for (int lcm = 1; lcm <= 12; lcm++) {
        for (int what = 0; what < 2; what++) {
          f[i][lcm][what] = 0;
        }
      }
    }
    f[0][1][0] = f[0][1][1] = 1;
    for (int i = 0; i < r; i++) {
      for (int lcm = 1; lcm <= 12; lcm++) {
        for (int what = 0; what < 2; what++) {
          int ft = f[i][lcm][what];
          if (ft == 0) {
            continue;
          }
          if (what == 0) {
            if (i + 2 <= r) {
              add(f[i + 2][lcm][what ^ 1], ft);
            }
          } else {
            if (i + 1 <= r && c % 1 == 0) {
              add(f[i + 1][LCM(lcm, 1)][what ^ 1], ft);
            }
            if (i + 2 <= r && c % 3 == 0) {
              add(f[i + 2][LCM(lcm, 3)][what ^ 1], mul(ft, 3));
            }
            if (i + 2 <= r && c % 6 == 0) {
              add(f[i + 2][LCM(lcm, 6)][what ^ 1], mul(ft, 6));
            }
            if (i + 3 <= r && c % 4 == 0) {
              add(f[i + 3][LCM(lcm, 4)][what ^ 1], mul(ft, 4));
            }
          }
        }
      }
    }
    int ans = 0;
    for (int lcm = 1; lcm <= 12; lcm++) {
      for (int what = 0; what < 2; what++) {
        long long ft = f[r][lcm][what];
        while (ft % lcm != 0) {
          ft += md;
        }
        ft /= lcm;
        add(ans, ft);
      }
    }
    printf("%d\n", ans);
    fflush(stdout);
    cerr << "test case " << qq << " done" << endl;
  }
  return 0;
}
                               	