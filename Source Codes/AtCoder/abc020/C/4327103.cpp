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

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
typedef pair<int,int> pint;
 
int n, m;
long long t;
int sx, sy, tx, ty;
string str[21];
 
long long INF = 1LL<<60;
long long dp[21][21];
long long calc(long long x) {
    for (int i = 0; i < 21; ++i) for (int j = 0; j < 21; ++j) dp[i][j] = INF;
    dp[sx][sy] = 0;
    priority_queue<pair<long long, pair<int,int> >, vector<pair<long long, pair<int,int> > >, greater<pair<long long, pair<int,int> > > > que;
    que.push(make_pair(0, pint(sx, sy)));
    while (!que.empty()) {
    int cx = que.top().second.first;
    int cy = que.top().second.second;
    long long cdp = que.top().first;
    que.pop();
    if (cdp > dp[cx][cy]) continue;
    //cout << x << ", " << cx << ", " << cy << ": " << cdp << endl;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = cx + dx[dir], ny = cy + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        long long ndp = cdp;
        if (str[nx][ny] == '.') ndp += 1;
        else if (str[nx][ny] == '#') ndp += x;
        if (chmin(dp[nx][ny], ndp)) {
        que.push(make_pair(ndp, pint(nx, ny)));
        }
    }
  }
  return dp[tx][ty];
}
 
int main() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (str[i][j] == 'S') {
                sx = i, sy = j;
            }
            if (str[i][j] == 'G')  {
                tx = i, ty = j;
                str[tx][ty] = '.';
            }
        }
    }
    long long lo = 1, hi = t;
    while (hi - lo > 1) {
        long long mid = (lo + hi)/2;
        //cout << mid << ": " << calc(mid) << endl;
        if (calc(mid) > t) hi = mid;
        else lo = mid;
    }
    cout << lo << endl;
    return 0;
}