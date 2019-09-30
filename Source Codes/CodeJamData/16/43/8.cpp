#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1010;

int match[MAX];
int h[MAX][MAX];
int v[MAX][MAX];
bool imp[MAX];
bool bio[MAX];

vector<int> imps;

vector<int> E[MAX];

void dfs(int x) {
  if (bio[x]) return;
  if (imp[x]) imps.push_back(x);
  bio[x] = true;
  for (int y: E[x]) dfs(y);
}

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    int R, C;
    scanf("%d %d", &R, &C);
    int n = 0;
    REP(i, R+1) REP(j, C) h[i][j] = -1;
    REP(i, R) REP(j, C+1) v[i][j] = -1;
    REP(j, C) h[0][j] = n++;
    REP(i, R) v[i][C] = n++;
    for (int j = C-1; j >= 0; --j)
      h[R][j] = n++;
    for (int i = R-1; i >= 0; --i)
      v[i][0] = n++;
    REP(i, R+1) REP(j, C) if (h[i][j] == -1) h[i][j] = n++;
    REP(i, R) REP(j, C+1) if (v[i][j] == -1) v[i][j] = n++;
    
    vector<vector<int>> match;
    vector<int> p;
    REP(i, R + C) {
      int a, b;
      scanf("%d %d", &a, &b); --a, --b;
      p.push_back(a);
      p.push_back(b);
      if (a > b) swap(a, b);
      match.push_back({a, b});
    }
    sort(match.begin(), match.end());
    
    REP(i, n) imp[i] = false;
    for (int x: p) imp[x] = true;

    printf("Case #%d:\n", tp);
    
    bool solved = false;
    REP(s, 1<<(R*C)) {
      vector<pair<int, int>> e;
      REP(i, n) E[i].clear();
      auto edge = [&] (int i, int j) {
        E[i].push_back(j);
        E[j].push_back(i);
      };
     
      REP(i, R) REP(j, C) {
        if (s & (1<<(i*C+j))) {
          edge(h[i][j], v[i][j]);
          edge(h[i+1][j], v[i][j+1]);
        } else {
          edge(h[i][j], v[i][j+1]);
          edge(h[i+1][j], v[i][j]);
        }
      }

      REP(i, n) bio[i] = false;
      vector<vector<int>> matched;
      for (int x: p)
        if (!bio[x]) {
          imps.clear();
          dfs(x);
          sort(imps.begin(), imps.end());
          matched.push_back(imps);
        }

      // REP(i, R) {
      //   REP(j, C) {
      //     if (s & (1<<(i*C+j))) putchar('/');
      //     else putchar('\\');
      //   }
      //   putchar('\n');
      // }
      // for (auto& V: matched) {
      //   for (int x: V) printf("%d ", x+1);
      //   printf("\n");
      // }
      
      sort(matched.begin(), matched.end());
      if (matched == match) {
        REP(i, R) {
          REP(j, C) {
            if (s & (1<<(i*C+j))) putchar('/');
            else putchar('\\');
          }
          putchar('\n');
        }
        solved = true;
        break;
      }
    }

    if (!solved) puts("IMPOSSIBLE");
  }
  return 0;
}
