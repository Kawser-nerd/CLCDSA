#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

constexpr int MAXC = 1000000000;

long route_cost(int pos, int R, long cost_now, int count,
                vector<bool> &reached, vector<vector<int>> &rtotal) {
    if (count + 1 == R) {
        return cost_now;
    }

    reached[pos] = true;
    int min_cost = MAXC;
    for (int i = 0; i < R; i++) {
        if (reached[i] || rtotal[pos][i] == MAXC) continue;
        reached[i] = true;
        long next_cost = route_cost(i, R, cost_now + rtotal[pos][i], count + 1,
                                    reached, rtotal);
        reached[i] = false;
        if (next_cost < min_cost) {
            min_cost = next_cost;
        }
    }
    reached[pos] = false;
    return min_cost;
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> town(R);
    for (int i = 0; i < R; i++) {
        cin >> town[i];
    }
    vector<vector<int>> total(N + 1, vector<int>(N + 1, MAXC));
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        total[a][b] = c;
        total[b][a] = c;
    }

    for (int route = 1; route <= N; route++) {
        int sum;
        for (int start = 1; start <= N; start++) {
            for (int goal = 1; goal <= N; goal++) {
                if (start == goal) continue;
                if (total[start][route] == MAXC || total[route][goal] == MAXC) continue;
                sum = total[start][route] + total[route][goal];
                if (sum < total[start][goal]) {
                    total[start][goal] = sum;
                    total[goal][start] = sum;
                }
            }
        }
    }

    vector<vector<int>> rtotal(R, vector<int>(R, MAXC));
    for (int sid = 0; sid < R; sid++) {
        int start = town[sid];
        for (int gid = 0; gid < R; gid++) {
            if (sid == gid) continue;
            int sgcost = total[start][town[gid]];
            rtotal[sid][gid] = sgcost;
            rtotal[gid][sid] = sgcost;
        }
    }

    long ans = MAXC;
    vector<bool> reached(R, false);
    for (int i = 0; i < R; i++) {
        long ret = route_cost(i, R, 0, 0, reached, rtotal);
        if (ret < ans) {
            ans = ret;
        }
    }
    cout << ans << endl;
}