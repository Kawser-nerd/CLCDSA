#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cstdlib>
#include <utility>
#include <cassert>

using namespace std;

vector<string> A;

bool vis[60*60*60*60];

bool dfs(int c, int L, int R, int C, int M) {
  int xx = M * 60*60+L*60+c;
  assert(xx < 60*60*60*60);
  if(vis[xx]) return false;
  vis[xx] = true;

  if(M == 0) return c + 1 != C;
  if(c == C) return false;

  bool res = false;
  for(int i = 1; i <= L && i <= M; i++) {
    A[i - 1][c] = '*';
    if(i + 1 == R) continue;
    if(c + 1 == C && i != L) continue;
    if(dfs(c + 1, i, R, C, M - i)) {
      return true;
    }
  }
  for(int i = 1; i <= L && i <= M; i++) {
    A[i - 1][c] = '.';
  }
  return false;
}

vector<string> tryplace(int R, int C, int M) {
  if(R == 1) {
    A = vector<string>(1);
    A[0] += string(M, '*');
    A[0] += string(C - M - 1, '.');
    A[0] += 'c';
    return A;
  } else if(C == 1) {
    return vector<string>();
  } else if(M == R * C - 1) {
    A = vector<string>(R, string(C, '*'));
    A[0][0] = 'c';
    return A;
  }

  A = vector<string>(R, string(C, '.'));
  A[R - 1][C - 1] = 'c';
  memset(vis, 0, sizeof(vis));
  if(dfs(0, R, R, C, M)) {
    return A;
  }
  return vector<string>();
}

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    int R, C, M;
    cin >> R >> C >> M;

    vector<string> res = tryplace(R, C, M);
    if(res.empty()) {
      res = tryplace(C, R, M);
      if(!res.empty()) {
        vector<string> nres(R, string(C, 0));
        for(int i = 0; i < R; i++) {
          for(int j = 0; j < C; j++) {
            nres[i][j] = res[j][i];
          }
        }
        res.swap(nres);
      }
    }
      

    printf("Case #%d:\n", t);
    if(res.empty()) {
      printf("Impossible\n");
    } else {
int cnt = 0;
assert(res.size() == R && res[0].size() == C);
      for(int i = 0; i < R; i++) {
for(int j = 0; j < C; j++) if(res[i][j] == '*') cnt++;
        printf("%s\n", res[i].c_str());
      }
assert(cnt == M);
    }
  }
  return 0;
}
