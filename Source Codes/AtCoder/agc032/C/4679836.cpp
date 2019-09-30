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
typedef pair<int, int> P;

vector <int> edge[100005];
bool visited[100005];

int dfs(int cur, int goal) {
    visited[cur] = true;
    if (cur == goal) return 1;

    int ret = 0;
    for (int x : edge[cur]) {
        if (!visited[x]) {
            ret += dfs(x, goal);
        }
    }

    return ret;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int six = 0;
    int four = 0;
    vector <int> idx;
    for (int i = 0; i < n; i++) {
        if (edge[i].size() % 2 == 1) {
            cout << "No\n";
            return 0;
        } else if (edge[i].size() == 6) {
            six++;
        } else if (edge[i].size() == 4) {
            four++;
            idx.push_back(i);
        }
    }

    if (six > 0 || four > 2) {
        cout << "Yes\n";
        return 0;
    } else if (four < 2) {
        cout << "No\n";
        return 0;
    }

    int ans = 0;
    visited[idx[0]] = true;
    for (int i = 0; i < edge[idx[0]].size(); i++) {
        visited[idx[1]] = false;
        ans += dfs(edge[idx[0]][i], idx[1]);
    }

    if (ans == 2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}