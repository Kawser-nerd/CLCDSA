#include <iostream>
#include <queue>

using namespace std;

typedef long long int LL;

struct state {
  int x, y; LL t;
  state(int x, int y, LL t) : x(x), y(y), t(t) {}
  bool operator<(const state &q) const {
    return t > q.t;
    }
  };

struct trafficInfo {
  LL S[20][20], W[20][20], T[20][20];
  LL nextNS(int i, int j, LL t) {
    LL a = t-T[i][j];
    a %= (S[i][j] + W[i][j]);
    if (a < 0) a += (S[i][j] + W[i][j]);
    if (a < S[i][j])
      return t;
    else
      return t + (S[i][j] + W[i][j] - a);
    }
  LL nextEW(int i, int j, LL t) {
    LL a = t-T[i][j];
    a %= (S[i][j] + W[i][j]);
    if (a < 0) a += (S[i][j] + W[i][j]);
    if (a >= S[i][j])
      return t;
    else
      return t + (S[i][j] - a);
    }
  };

void checkPush(priority_queue<state> &q, state &s, LL bestTimes[40][40]) {
  if ((bestTimes[s.x][s.y] == -1) || (s.t < bestTimes[s.x][s.y])) {
    q.push(s); bestTimes[s.x][s.y] = s.t;
    }
  }

int main() {
  int C; cin >> C;
  for (int cc = 1; cc <= C; ++cc) {
    int N, M; cin >> N >> M;
    trafficInfo lights;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        cin >> lights.S[i][j] >> lights.W[i][j] >> lights.T[i][j];
    LL bestTimes[40][40];
    for (int i = 0; i < 2*N; ++i)
      for (int j = 0; j < 2*M; ++j)
        bestTimes[i][j] = -1;
    bestTimes[2*N-1][0] = 0;
    priority_queue<state> q;
    q.push(state(2*N-1, 0, 0));
    while (!q.empty()) {
      state t = q.top(); q.pop();
      if (t.t == bestTimes[t.x][t.y]) {
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        for (int d = 0; d < 4; ++d) {
          int nx = t.x + dx[d], ny = t.y + dy[d];
          if ((0 <= nx) && (nx < 2*N) && (0 <= ny) && (ny < 2*M)) {
            if ((nx/2 != t.x/2) || (ny/2 != t.y/2))
              checkPush(q, state(nx, ny, t.t+2), bestTimes);
            else if (nx != t.x)
              checkPush(q, state(nx, ny, lights.nextNS(nx/2, ny/2, t.t)+1), bestTimes);
            else
              checkPush(q, state(nx, ny, lights.nextEW(nx/2, ny/2, t.t)+1), bestTimes);
            }
          }
        }
      }
    cout << "Case #" << cc << ": " << bestTimes[0][2*M-1] << '\n';
    }
  }