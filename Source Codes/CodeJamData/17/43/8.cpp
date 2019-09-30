#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

int N, M;
string A[60];
map<pair<int, int>, int> smap;
vector<vector<int> > edges;

bool vis[110];

bool dfs(int u, int v) {
  if (u == v) return true;
  if (vis[u]) return false;
  vis[u] = true;
  for (auto i : edges[u]) {
    if (dfs(i, v)) {
      return true;
    }
  }
  return false;
}

pair<int, int> shoot_shooter(int r, int c, int dir) {
  r += dr[dir];
  c += dc[dir];
  while (0 <= r && r < N && 0 <= c && c < M) {
    if (A[r][c] == '#') {
      return make_pair(-1, 0);
    } else if (A[r][c] == '-' || A[r][c] == '|') {
      return make_pair(smap[make_pair(r, c)], dir % 2);
    } else if (A[r][c] == '/') {
      dir ^= 3;
    } else if (A[r][c] == '\\') {
      dir ^= 1;
    }
    r += dr[dir];
    c += dc[dir];
  }
  return make_pair(-1, 0);
}

int id(pair<int, int> x) {
  return x.first + smap.size() * x.second;
}

int flip_id(pair<int, int> x) {
  return x.first + smap.size() * (1 - x.second);
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    smap.clear();
    edges.clear();

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    int shooters = 0;
    vector<bool> canh;
    vector<bool> canv;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (A[i][j] == '-' || A[i][j] == '|') {
          smap[make_pair(i, j)] = shooters;
          canh.push_back(shoot_shooter(i, j, 1).first == -1 &&
                         shoot_shooter(i, j, 3).first == -1);
          canv.push_back(shoot_shooter(i, j, 0).first == -1 &&
                         shoot_shooter(i, j, 2).first == -1);
          ++shooters;
        }
      }
    }

    bool fail = false;
    edges.resize(2 * shooters);
    for (int i = 0; i < N && !fail; i++) {
      for (int j = 0; j < M && !fail; j++) {
        if (A[i][j] == '.') {
          /* Assume both don't hit. */
          auto sid_up = shoot_shooter(i, j, 2);
          auto sid_down = shoot_shooter(i, j, 0);
          auto sid_left = shoot_shooter(i, j, 3);
          auto sid_right = shoot_shooter(i, j, 1);

          auto sid_vert = sid_up.first == -1 ? sid_down : sid_up;
          auto sid_horz = sid_left.first == -1 ? sid_right : sid_left;
          if (sid_vert.first == -1 && sid_horz.first == -1) {
            fail = true;
          } else if (sid_vert.first == -1) {
            (sid_horz.second ? canv : canh)[sid_horz.first] = false;
          } else if (sid_horz.first == -1) {
            (sid_vert.second ? canv : canh)[sid_vert.first] = false;
          } else {
            edges[flip_id(sid_vert)].push_back(id(sid_horz));
            edges[flip_id(sid_horz)].push_back(id(sid_vert));
          }
        }
      }
    }

    /* Look for cycles containing term's negations. */
    for (int i = 0; i < shooters && !fail; i++) {
      memset(vis, 0, sizeof(vis));
      if (dfs(i, shooters + i)) {
        fail = true;
        break;
      }
    }
    
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < shooters && !fail; i++) {
      int bi = -1;
      int fi = -1;
      for (int j = 0; j < shooters && bi == -1; j++) {
        if (vis[j]) continue;
        if (fi == -1) {
          fi = j;
        }
        if (!canh[j] || !canv[j]) {
          bi = j;
        }
      }
      if (bi == -1) {
        bi = fi;
        canh[bi] = false;
      }
      vis[bi] = true;
      if (!canh[bi]) {
        for (auto u : edges[bi]) {
          int id = u % shooters;
          int side = u / shooters;
          (side ? canv : canh)[id] = false;
        }
      }
      if (!canv[bi]) {
        for (auto u : edges[bi + shooters]) {
          int id = u % shooters;
          int side = u / shooters;
          (side ? canv : canh)[id] = false;
        }
      }
    }
    for (int i = 0; i < shooters && !fail; i++) {
      if (!canh[i] && !canv[i]) {
        fail = true;
      }
    }

    cout << "Case #" << t << ": ";

    if (fail) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << "POSSIBLE" << endl;
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          if (A[i][j] == '-' || A[i][j] == '|') {
            cout << (canh[smap[make_pair(i, j)]] ? '-' : '|');
          } else {
            cout << A[i][j];
          }
        }
        cout << '\n';
      }
    }
  }
  return 0;
}
