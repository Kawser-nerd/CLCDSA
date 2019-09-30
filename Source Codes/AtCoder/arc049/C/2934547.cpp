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

int n, a, b;

int solve(int s, const vector<vector<int>>& edge, const vector<P>& cond){
    vector<vector<int>> edgeB(n+1, vector<int>());
    vector<bool> never(n+1, false);
    rep(i, b){
        if((s >> i) % 2 == 0){
            never[cond[i].first] = true;
            continue;
        }
        edgeB[cond[i].second].push_back(cond[i].first);
    }

    vector<bool> mark(n+1, false);
    for(int i = 1; i <= n * 2; i++){
        for(int j = 1; j <= n; j++){
            if(never[j] || mark[j]){
                continue;
            }

            bool isAble = true;
            rep(k, (int)edge[j].size()){
                if(not mark[edge[j][k]]){
                    isAble = false;
                }
            }
            rep(k, (int)edgeB[j].size()){
                if(not mark[edgeB[j][k]]){
                    isAble = false;
                }
            }

            if(isAble){
                mark[j] = true;
            }
        }
    }

    int ans = 0;
    rep(i, n){
        if(mark[i+1]){
            ans++;
        }
    }
    return ans;
}

signed main(){
    cin >> n;

    cin >> a;
    vector<vector<int>> edge(n+1, vector<int>());
    rep(i, a){
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
    }

    cin >> b;
    vector<P> cond;
    rep(i, b){
        int u, v;
        cin >> u >> v;
        cond.emplace_back(u, v);
    }

    int ans = 0;
    rep(s, (1 << b)){
        int tmp = solve(s, edge, cond);
        if(ans < tmp){
            ans = tmp;
        }
    }
    cout << ans << endl;

    return 0;
}