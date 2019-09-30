#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#include <set>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}
const int lim = 50;

int N,M;
int a[lim] , b[lim];

bool graph[lim][lim];
bool visited[lim];

void dfs(int v) {
    visited[v] = true;
    for (int v2 = 0; v2 < N; ++v2) {
        if (graph[v][v2] == false) continue;
        if (visited[v2] == true) continue;
        dfs(v2);
    }
}
int main(){
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }

    int ans = 0;

    for (int i = 0; i < M; ++i) {
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;

        for (int k = 0; k < N; ++k) {
            visited[k] = false;
        }

        dfs(0);

        bool bridge = false;
        for (int k = 0; k < N; ++k) {
            if (visited[k] == false) {
                bridge = true;
            }
        }
        if (bridge) ans += 1;

        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }
    cout << ans << endl;
    return 0;
}