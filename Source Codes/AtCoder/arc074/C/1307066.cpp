#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = (int)1e9 + 7;
int f[303][303][303];

struct Constraint {
  int l, r, x;
};

int main(void) {
  int n, m;
  scanf("%i %i", &n, &m);
  
  vector<Constraint> bucket[303];
  for (int i = 0; i < m; i++) {
    int l, r, x;
    scanf("%i %i %i", &l, &r, &x);
    bucket[r].push_back({l, r, x});
  }
  
  int tot = 0;
  
  f[0][0][0] = 1;
  for (int r = 0; r <= n; r++) {
    for (int g = 0; g <= n; g++) {
      for (int b = 0; b <= n; b++) {
        int k = max(r, max(g, b));
        for (auto c : bucket[k]) {
          int a[] = {r, g, b}, count = 0;
          for (int i = 0; i < 3; i++) {
            if (a[i] >= c.l) count++;
          }
          if (count != c.x) {
            f[r][g][b] = 0;
          }
        }
        if (k >= n) {
          tot = (tot + f[r][g][b]) % mod;
          continue;
        }
        f[k+1][g][b] = (f[k+1][g][b] + f[r][g][b]) % mod;
        f[r][k+1][b] = (f[r][k+1][b] + f[r][g][b]) % mod;
        f[r][g][k+1] = (f[r][g][k+1] + f[r][g][b]) % mod;
      }
    }
  }
  
  printf("%i\n", tot);
  
  return 0;
}