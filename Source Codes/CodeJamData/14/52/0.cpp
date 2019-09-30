#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 100;
const int SHOTS = 1000;

int f[N + 10][SHOTS + 10][2];
int h[N + 10], g[N + 10];

int ME, TOWER;

int max_shots;

void dfs(int i, int shots, int mv, int cur_hp, int gold) {
  if (shots > max_shots) {
    max_shots = shots;
  }
  if (mv == 1) {
    cur_hp -= TOWER;
    if (cur_hp <= 0) {
      if (gold > f[i + 1][shots][mv ^ 1]) {
        f[i + 1][shots][mv ^ 1] = gold;
      }
      return;
    }
    dfs(i, shots, mv ^ 1, cur_hp, gold);
  } else {
    dfs(i, shots + 1, mv ^ 1, cur_hp, gold);
    cur_hp -= ME;
    if (cur_hp <= 0) {
      gold += g[i];
      if (gold > f[i + 1][shots][mv ^ 1]) {
        f[i + 1][shots][mv ^ 1] = gold;
      }
      return;
    }
    dfs(i, shots, mv ^ 1, cur_hp, gold);
  }
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int n;
    scanf("%d %d %d", &ME, &TOWER, &n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", h + i, g + i);
    }
    memset(f, 255, sizeof(f));
    f[0][0][0] = 0;
    max_shots = 0;
    for (int i = 0; i < n; i++) {
      for (int shots = 0; shots <= SHOTS; shots++) {
        for (int mv = 0; mv < 2; mv++) {
          int ft = f[i][shots][mv];
          if (ft == -1) {
            continue;
          }
          for (int k = 0; k <= shots; k++) {
            int cur_hp = h[i] - k * ME;
            if (cur_hp <= 0) {
              int gt = ft + g[i];
              if (gt > f[i + 1][shots - k][mv]) {
                f[i + 1][shots - k][mv] = gt;
              }
              break;
            }
            dfs(i, shots - k, mv, cur_hp, ft);
          }
        }
      }
    }
    int ans = -1;
    for (int shots = 0; shots <= SHOTS; shots++) {
      for (int mv = 0; mv < 2; mv++) {
        if (f[n][shots][mv] > ans) {
          ans = f[n][shots][mv];
        }
      }
    }
    printf("%d\n", ans);
    cerr << "max_shots = " << max_shots << endl;
  }
  return 0;
}
