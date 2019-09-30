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
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n;
    cin >> n;

    vector<vector<int>> edge(n+1, vector<int>());
    rep(i, n-1){
        int a, b;
        cin >> a >> b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vector<int> depth(n+1, -1);
    queue<P> q;
    q.emplace(1, 0);
    while(not q.empty()){
        P p = q.front();
        q.pop();

        if(depth[p.first] != -1){
            continue;
        }
        depth[p.first] = p.second;

        rep(i, (int)edge[p.first].size()){
            if(depth[edge[p.first][i]] == -1){
                q.emplace(edge[p.first][i], p.second+1);
            }
        }
    }

    int max = 0;
    int pos1;
    rep(i, n+1){
        if(depth[i] > max){
            max = depth[i];
            pos1 = i;
        }
    }

    depth = vector<int>(n+1, -1);
    q = queue<P>();
    q.emplace(pos1, 0);
    while(not q.empty()){
        P p = q.front();
        q.pop();

        if(depth[p.first] != -1){
            continue;
        }
        depth[p.first] = p.second;

        rep(i, (int)edge[p.first].size()){
            if(depth[edge[p.first][i]] == -1){
                q.emplace(edge[p.first][i], p.second+1);
            }
        }
    }

    max = 0;
    int pos2;
    rep(i, n+1){
        if(depth[i] > max){
            max = depth[i];
            pos2 = i;
        }
    }

    cout << pos1 << " " << pos2 << endl;

    return 0;
}