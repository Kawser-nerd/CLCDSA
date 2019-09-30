#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};

string A[110];

bool vis[210];
bool cn[210][210];
set<int> cndeps[110][110];

set<int> TUR[110][110];
int dist[110][110];
set<int> deps[110][110];

bool dfs(int u, int snk) {
  if (u == snk) return true;
  if (vis[u]) return false;
  vis[u] = true;

  for (int i = 0; i <= snk; i++) {
    if (cn[u][i] && dfs(i, snk)) {
      cn[u][i] = false;
      cn[i][u] = true;
      return true;
    }
  }
  return false;
}

int dfs2(int u, int v, vector<int>& asn, vector<int>& rasn) {
  if (vis[u]) return 0;
  vis[u] = true;

  for (auto i : cndeps[u][asn[u]]) {
    int j = rasn[i];
    if (j == -1) {
      asn[u] = i;
      return 2;
    } else if (j == v) {
      asn[u] = i;
      return 1;
    } else {
      int r = dfs2(j, v, asn, rasn);
      if (r == 2) {
        return 2;
      } else if (r == 1) {
        asn[u] = i;
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int C, R, M;
    cin >> C >> R >> M;

    memset(vis, 0, sizeof(vis));
    memset(cn, 0, sizeof(cn));
    for (int i = 0; i < 110; i++) {
      for (int j = 0; j < 110; j++) {
        cndeps[i][j].clear();
      }
    }
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        TUR[i][j].clear();
      }
    }

    for (int i = 0; i < R; i++) {
      cin >> A[i];
    }

    int soldiers = 0;
    int turrets = 0;
    map<pair<int, int>, int> smap;
    map<pair<int, int>, int> tmap;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (A[i][j] == 'S') {
          smap[make_pair(i, j)] = soldiers++;
        } else if (A[i][j] == 'T') {
          tmap[make_pair(i, j)] = turrets++;
        }
      }
    }

    int src = soldiers + turrets;
    int snk = src + 1;
    for (int i = 0; i < soldiers; i++) {
      cn[src][i] = true;
    }
    for (int i = 0; i < turrets; i++) {
      cn[soldiers + i][snk] = true;
    }
    
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (A[i][j] != 'T') {
          continue;
        }
        int tid = tmap[make_pair(i, j)];
        for (int k = 0; k < 4; k++) {
          int nr = i + dr[k];
          int nc = j + dc[k];
          while (0 <= nr && nr < R && 0 <= nc && nc < C &&
                  A[nr][nc] != '#') {
            TUR[nr][nc].insert(tid);
            nr += dr[k];
            nc += dc[k];
          }
        }
      }
    }

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (A[i][j] != 'S') {
          continue;
        }
        int sid = smap[make_pair(i, j)];

        queue<int> q;
        q.push(i * C + j);
        memset(dist, -1, sizeof(dist));
        dist[i][j] = 0;
        deps[i][j].clear();
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          int ur = u / C;
          int uc = u % C;
          if (dist[ur][uc] > M) {
            break;
          }

          for (auto i : TUR[ur][uc]) {
            if (!cn[sid][soldiers + i]) {
              cn[sid][soldiers + i] = true;
              cndeps[sid][i] = deps[ur][uc];
            }
          }
          for (auto i : TUR[ur][uc]) {
            deps[ur][uc].insert(i);
          }

          for (int k = 0; k < 4; k++) {
            int nr = ur + dr[k];
            int nc = uc + dc[k];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C ||
                  A[nr][nc] == '#' || dist[nr][nc] != -1) {
              continue;
            }
            dist[nr][nc] = dist[ur][uc] + 1;
            deps[nr][nc] = deps[ur][uc];
            q.push(nr * C + nc);
          }
        }
      }
    }

    int result = 0;
    memset(vis, 0, sizeof(vis));
    while (dfs(src, snk)) {
      memset(vis, 0, sizeof(vis));
      ++result;
    }

    vector<int> asn(soldiers, -1);
    for (int i = 0; i < soldiers; i++) {
      for (int j = 0; j < turrets; j++) {
        if (cn[soldiers + j][i]) {
          asn[i] = j;
          break;
        }
      }
    }

    bool changed = true;
    while (changed) {
      changed = false;

      vector<int> rasn(turrets, -1);
      for (int i = 0; i < soldiers; i++) {
        if (asn[i] != -1) {
          rasn[asn[i]] = i;
        }
      }

      for (int i = 0; i < soldiers && !changed; i++) {
        if (asn[i] == -1) {
          continue;
        }
      memset(vis, 0, sizeof(vis));
        if (dfs2(i, i, asn, rasn)) {
          changed = true;
          break;
        }
      }
    }

    cout << "Case #" << t << ": " << result << endl;

    int cnt = 0;
    vector<bool> destroyed(turrets, false);
    while (cnt < result) {
      for (int i = 0; i < soldiers; i++) {
        if (asn[i] == -1 || destroyed[asn[i]]) continue;
        bool ok = true;
        for (int j : cndeps[i][asn[i]]) {
          if (!destroyed[j]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          ++cnt;
          destroyed[asn[i]] = true;
          cout << i + 1 << ' ' << asn[i] + 1 << '\n';
        }
      }
    }
  }
  return 0;
}
