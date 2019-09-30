#include<iostream>
#include<cstring>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  long ans = 0;
  // a, c, g, t
  long t[4][4][4];
  if (n == 1) {
    cout << 4 << endl;
    return 0;
  }
  if (n == 2) {
    cout << 16 << endl;
    return 0;
  }
  if (n == 3) {
    cout << 61 << endl;
    return 0;
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        t[i][j][k] = 1;
      }
    }
  }
  t[0][2][1] = 0;
  t[0][1][2] = 0;
  t[2][0][1] = 0;

  long next[4][4][4];
  if (n >= 4) {
    for (int cnt = 3; cnt < n; cnt++) {
      memset(next, 0, sizeof next);
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          for (int k = 0; k < 4; k++) {
            next[j][k][0] += t[i][j][k];
            next[j][k][3] += t[i][j][k];
            if (j != 0 || k != 1) {
              next[j][k][2] += t[i][j][k];
            }
            if (!((j == 0 && k == 2) || (j == 2 && k == 0) || (i == 0 && j == 2) || (i == 0 && k == 2))) {
              next[j][k][1] += t[i][j][k];
            }
            next[i][j][k] %= 1000000007;
          }
        }
      }
      memcpy(t, next, sizeof next);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        ans += t[i][j][k];
        ans %= 1000000007;
      }
    }
  }
  cout << ans << endl;
  return 0;
}