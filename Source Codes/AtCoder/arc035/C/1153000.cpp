#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define INF 1145141919
typedef pair<int, int> P;
int N, M, K;
int G[400][400];
int D[400][400];

void dijkstra(int i) {
  for (int j=0; j<N; j++) D[i][j]++;
  D[i][i] = 0;

  priority_queue<P, vector<P>, greater<P> > q;
  q.push(P(0, i));
  while (!q.empty()) {
    int r = q.top().first,
        s = q.top().second;
    q.pop();
    if (D[i][s] < r) continue;
    for (int t=0; t<N; t++) {
      int c = G[s][t];
      if (c == INF) continue;
      if (D[i][t] > r+c) {
        D[i][t] = r+c;
        q.push(P(D[i][t], t));
      }
    }
  }
}

long long s() {
  long long r = 0;
  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      r += D[i][j];
    }
  }
  return r;
}

int main() {
  cin >> N >> M;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      G[i][j] = INF;
      if (i == j) D[i][j] = 0;
      else D[i][j] = INF;
    }
  }
  for (int i=0; i<M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    G[a][b] = min(G[a][b], c);
    G[b][a] = min(G[b][a], c);
  }

  for (int i=0; i<N; i++) dijkstra(i);
  cin >> K;
  for (int i=0; i<K; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) {
        D[i][j] = min(D[i][j], D[i][x] + D[y][j] + z);
        D[i][j] = min(D[i][j], D[i][y] + D[x][j] + z);
      }
    }
    cout << s() << "\n";
  }
  return 0;
}