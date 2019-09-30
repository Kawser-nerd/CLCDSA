#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, k;
    cin >> h >> w >> k;

    vector<vector<bool>> a(h, vector<bool>(w, false));
    P s;
    rep(i, h){
        rep(j, w){
            char c;
            cin >> c;

            if(c == 'S'){
                s = {i, j};
                a[i][j] = true;
            }
            if(c == '.'){
                a[i][j] = true;
            }
        }
    }

    vector<vector<P>> d(h, vector<P>(w, {INF, INF}));
    vector<int> dir = {1, 0, -1, 0};
    queue<pair<P, P>> q;
    queue<pair<P, P>> qq;
    q.push({s, {0, 0}});
    while(not q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        P dist = q.front().second;
        qq.push(q.front());
        q.pop();

        if(d[x][y] <= dist){
            continue;
        }
        d[x][y] = dist;

        if(dist.second == k){
            continue;
        }

        rep(i, 4){
            int nx = x + dir[i];
            int ny = y + dir[i^1];

            if(0 > nx || nx >= h || 0 > ny || ny >= w || not a[nx][ny]){
                continue;
            }

            if(d[nx][ny] <= dist){
                continue;
            }

            q.push({{nx, ny}, {0, dist.second + 1}});
        }
    }

    q = qq;

    while(not q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        P dist = q.front().second;
        q.pop();

        if(dist.first == 0){
            dist = {1, 0};
        }

        if(d[x][y].first == 1 && d[x][y] <= dist){
            continue;
        }
        d[x][y] = dist;

        rep(i, 4){
            int nx = x + dir[i];
            int ny = y + dir[i^1];

            if(0 > nx || nx >= h || 0 > ny || ny >= w){
                continue;
            }
            if(d[nx][ny] <= dist){
                continue;
            }

            q.push({{nx, ny}, {1, dist.second + 1}});
        }
    }

    int ans = INF;
    rep(i, h){
        rep(j, w){
            if(i != 0 && i != h - 1 && j != 0 && j != w - 1){
                continue;
            }

            int tmp = d[i][j].first + (d[i][j].second + k - 1) / k;
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;

    return 0;
}