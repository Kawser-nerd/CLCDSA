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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge(n+1, vector<int>(n+1, INF));
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a][b] = c;
        edge[b][a] = c;
    }

    rep(i, n){
        edge[i+1][i+1] = 0;
    }

    rep(k, n){
        rep(i, n){
            rep(j, n){
                edge[i+1][j+1] = min(edge[i+1][j+1], edge[i+1][k+1] + edge[k+1][j+1]);
            }
        }
    }

    int k;
    cin >> k;
    rep(i, k){
        int x, y, z;
        cin >> x >> y >> z;

        /*
        if(edge[x][y] > z){
            edge[x][y] = z;
            edge[y][x] = z;
        }
        */

        rep(i, n){
            rep(j, n){
                edge[i+1][j+1] = min(edge[i+1][j+1], edge[i+1][x] + edge[y][j+1] + z);
                edge[i+1][j+1] = min(edge[i+1][j+1], edge[i+1][y] + edge[x][j+1] + z);
            }
        }

        int ans = 0;
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j <= n; j++){
                ans += edge[i][j];
            }
        }
        cout << ans << endl;
    }

    return 0;
}