#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;
typedef pair<int, int> P;

const int INF = 1000000007;
int n, X[1005];
vector <int> edge[1005];
P dp[1005];
bool possible;

void dfs(int cur) {
    int dp2[2][X[cur]+1];
    fill(dp2[0], dp2[2], INF);
    dp2[0][0] = 0;

    int tmp = 0, nxt = 1;
    for (int i = 0; i < edge[cur].size(); i++) {
        int child = edge[cur][i];
        dfs(child);

        int x = dp[child].first;
        int y = dp[child].second;
        //cout << "cur = " << cur << " x = " << x << " y = " << y << "\n";

        for (int j = 0; j <= X[cur]; j++) {
            if (dp2[tmp][j] == INF) continue;

            if (j + x <= X[cur]) {
                dp2[nxt][j+x] = dp2[tmp][j] + y;
            }

            if (j + y <= X[cur]) {
                dp2[nxt][j+y] = dp2[tmp][j] + x;
            }
        }

        swap(tmp, nxt);
        for (int j = 0; j <= X[cur]; j++) {
            dp2[nxt][j] = INF;
        }
    }

    for (int i = X[cur]; i >= 0; i--) {
        if (dp2[tmp][i] < INF) {
            dp[cur] = P(X[cur], dp2[tmp][i]);
            return;
        }
    }

    possible = false;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        edge[p].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }

    possible = true;
    dfs(0);

    if (possible) {
        cout << "POSSIBLE\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}