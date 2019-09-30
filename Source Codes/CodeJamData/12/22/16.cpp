#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

inline bool inRange(int x, int l, int r) {
    return (x >= l && x < r);
}


int main(void) {
    int testCount;
    cin >> testCount;
    for (int testNo = 1; testNo <= testCount; ++testNo) {
        int N, M, H;
        cin >> H >> N >> M ;
        vector< vector<int> > F(N, vector<int>(M));
        auto C = F;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> C[i][j];
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> F[i][j];
            }
        }
        const int INF = 1000000000;
        vector< vector<int> > dist(N, vector<int>(M, INF));
        dist[0][0] = 0;
        typedef pair<int, int> pii;
        typedef pair<int, pii> pipii;
        priority_queue<pipii, vector<pipii>, greater<pipii> > q;
        q.push(pipii(0, pii(0, 0)));
        while (!q.empty()) {
            pii cur = q.top().second;
            if (q.top().first != dist[cur.first][cur.second]) {
                q.pop();
                continue;
            }
            q.pop();
            static const int dx[] = {0, 0, 1, -1};
            static const int dy[] = {1, -1, 0, 0};
            int cx = cur.first;
            int cy = cur.second;
            for (int i = 0; i < 4; ++i) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (!inRange(nx, 0, N) || !inRange(ny, 0, M))
                    continue;
                if (min(C[nx][ny], C[cx][cy]) - max(F[nx][ny], F[cx][cy]) < 50)
                    continue;
                int requiredWaterLevel = min(C[nx][ny], C[cx][cy]) - 50;
                int timeWhenWeCanPass = 0;
                if (requiredWaterLevel < H)
                    timeWhenWeCanPass = H - requiredWaterLevel;
                timeWhenWeCanPass = max(timeWhenWeCanPass, dist[cx][cy]);
                int wl = H - timeWhenWeCanPass;
                int mt = 10*10;
                if (wl >= 20 + F[cx][cy])
                    mt = 10;
                if (timeWhenWeCanPass == 0)
                    mt = 0;
                if (mt + timeWhenWeCanPass < dist[nx][ny]) {
                    dist[nx][ny] = mt + timeWhenWeCanPass;
                    q.push(pipii(dist[nx][ny], pii(nx, ny)));
                }
            }
        }
        cout << "Case #" << testNo << ": ";
        cout << dist[N - 1][M - 1] / 10 << "." << dist[N - 1][M - 1] % 10 << endl;
    }
    return 0;
}
