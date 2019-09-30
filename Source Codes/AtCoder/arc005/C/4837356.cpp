#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;

    int s, g;
    char c[H][W];
    for (int i = 0; i < H; i++) {
        cin >> c[i];
        for (int j = 0; j < W; j++) {
            if (c[i][j] == 's') s = i * W + j;
            if (c[i][j] == 'g') g = i * W + j;
        }
    }

    deque <int> q;
    vector <int> cost(H*W, 1e9);

    q.push_back(s);
    cost[s] = 0;

    while (q.size()) {
        int cur = q.front();
        q.pop_front();

        for (int i = 0; i < 4; i++) {
            int x = cur / W + dx[i];
            int y = cur % W + dy[i];
            if (x < 0 || x >= H || y < 0 || y >= W) continue;

            int wall = c[x][y] == '#' ? 1 : 0;
            if (cost[x * W + y] <= cost[cur] + wall) continue;
            cost[x * W + y] = cost[cur] + wall;

            if (wall) {
                q.push_back(x * W + y);
            } else {
                q.push_front(x * W + y);
            }
        }
    }

    if (cost[g] <= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}