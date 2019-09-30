#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;
 
#define all(c) ((c).begin()), ((c).end()) 
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end()) 
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
 
typedef long long ll;
 


const int MAX_V = 20010;
 
struct e_t { int to, cap, rev; };
 
int V, S, T;
vector<e_t> adj[MAX_V];
 
int level[MAX_V], done[MAX_V];
 
void levelize() {
  memset(level, -1, sizeof(level));
  queue<int> que;
  level[S] = 0;
  que.push(S);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int i = 0; i < adj[v].size(); i++) {
      e_t &e = adj[v][i];
      if (e.cap <= 0) continue;
      if (level[e.to] != -1) continue;
      que.push(e.to);
      level[e.to] = level[v] + 1;
    }
  }
}
 
int augment(int v, int flow) {
  if (v == T || flow == 0) return flow;
  for (; done[v] < adj[v].size(); done[v]++) {
    e_t &e = adj[v][done[v]];
    if (level[e.to] <= level[v]) continue;
    int f = augment(e.to, min(flow, e.cap));
    if (f > 0) {
      e.cap -= f;
      adj[e.to][e.rev].cap += f;
      return f;
    }
  }
  return 0;
}
 
int max_flow() {
  int total = 0, fsum, f;
  do {
    levelize();
    memset(done, 0, sizeof(done));
    fsum = 0;
    while (0 < (f = augment(S, INT_MAX))) fsum += f;
    total += fsum;
  } while (fsum > 0);
  return total;
}
 
void add_edge(int i, int j, int c) {
  adj[i].push_back((e_t){j, c, adj[j].size() + (i == j)});
  adj[j].push_back((e_t){i, 0, adj[i].size() - 1});
}

int H, W;
char fld[100][100];


int id(int x, int y) { return x * H + y; }

void connect(int x, int y, int X, int Y) {
  // xが偶数がソース寄り
  if (x % 2 == 1) {
    swap(x, X);
    swap(y, Y);
  }

  add_edge(id(x, y), id(X, Y), 1);
}

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 0, -1, 0};

int main() {
  int Test;
  scanf("%d", &Test);
  for (int t = 1; t <= Test; t++) {
    scanf("%d%d", &H, &W);

    V = (H + 2) * (W + 2) + 2;
    S = (H + 2) * (W + 2);
    T = (H + 2) * (W + 2) + 1;
    for (int i = 0; i < V; i++) adj[i].clear();

    memset(fld, 'x', sizeof(fld));
    for (int y = 1; y <= H; y++) for (int x = 1; x <= W; x++) scanf(" %c", &fld[x][y]);

    int cnt = 0;

    for (int y = 1; y <= H; y++) {
      for (int x = 1; x <= W; x++) {
        if (fld[x][y] == 'x') continue;

        // xが偶数がソース寄り
        if (x % 2 == 0) add_edge(S, id(x, y), 1);
        else add_edge(id(x, y), T, 1);

        cnt++;

        for (int i = 0; i < 4; i++) {
          int tx = x + dx[i];
          int ty = y + dy[i];
          if (fld[tx][ty] == 'x') continue;

          connect(x, y, tx, ty);
        }
      }
    }

    printf("Case #%d: %d\n", t, cnt - max_flow());
  }
}
