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

const int N = 1234;

char g[N][N];
bool was[N];
int n;

void dfs(int v) {
  if (was[v]) {
    return;
  }
  was[v] = true;
  for (int j = 0; j < n; j++) {
    if (g[v][j] == 'Y' && !was[j]) {
      dfs(j);
    }
  }
}

bool used[N];
int a[N];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d:", qq);
    fflush(stdout);
    int fav;
    scanf("%d %d", &n, &fav);
    for (int i = 0; i < n; i++) {
      scanf("%s", g[i]);
    }
    for (int i = 0; i < n; i++) {
      was[i] = false;
    }
    dfs(fav);
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (!was[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      printf(" IMPOSSIBLE\n");
    } else {
      for (int i = 0; i < n; i++) {
        used[i] = false;
        a[i] = -1;
      }
      int best = -1;
      for (int pos = 0; pos < n; pos++) {
        for (int val = 0; val < n; val++) {
          if (used[val]) {
            continue;
          }
          a[pos] = val;
          used[val] = true;
          int new_best = best;
          if (new_best == -1) {
            new_best = val;
          } else {
            if (g[val][new_best] == 'Y') {
              new_best = val;
            }
          }
          bool ok = true;
          if (!used[fav]) {
            for (int i = 0; i < n; i++) {
              was[i] = used[i];
            }
            dfs(fav);
            for (int i = 0; i < n; i++) {
              if (!was[i] && g[new_best][i] == 'N') {
                ok = false;
                break;
              }
            }
          } else {
            if (fav != new_best) {
              ok = false;
            } else {
              for (int i = 0; i < n; i++) {
                if (!used[i] && g[i][fav] == 'Y') {
                  ok = false;
                  break;
                }
              }
            }
          }
          if (ok) {
            best = new_best;
            break;
          }
          used[val] = false;
          a[pos] = -1;
        }
      }
      for (int i = 0; i < n; i++) {
        printf(" %d", a[i]);
      }
      printf("\n");
    }
    fflush(stdout);
  }
  return 0;
}
