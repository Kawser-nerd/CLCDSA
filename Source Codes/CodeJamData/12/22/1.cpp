#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int C[111][111];
int F[111][111];
int best[111][111];
typedef pair<int,int> pii;
#define MP make_pair

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
  int T; cin >> T;
  for (int ti = 1; ti <= T; ti++) {
    int H, N, M; cin >> H >> N >> M;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        cin >> C[i][j];
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        cin >> F[i][j], best[i][j] = 1e9;

    best[0][0] = 0;
    priority_queue<pair<int, pii> > pq;
    pq.push(MP(0, MP(0, 0)));
    while (pq.size()) {
      int t = -pq.top().first;
      pii pp = pq.top().second;
      int x = pp.first, y = pp.second;
      pq.pop();
      if (t > best[x][y]) continue;
      for (int d = 0; d < 4; d++) {
        unsigned nx = x + dx[d], ny = y + dy[d];
        if (nx < N && ny < M) {
          if (F[x][y] + 50 > C[nx][ny] ||
              F[nx][ny] + 50 > C[nx][ny] ||
              F[nx][ny] + 50 > C[x][y]) continue;
          int nt = t;
          if (H-t+50 > C[nx][ny]) {
            nt += H-t+50 - C[nx][ny];
          }
          if (nt) {
            if (H-nt >= F[x][y]+20) nt += 10;
            else nt += 100;
          }
          if (nt < best[nx][ny]) {
            best[nx][ny] = nt;
            pq.push(MP(-nt, MP(nx, ny)));
          }
        }
      }
    }

    int ans = best[N-1][M-1];
    printf("Case #%d: %d.%d\n", ti, ans/10, ans%10);
  }
}
