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

//n : ???
class topological_sort{
    public:
        int n;
        vector<vector<int>> edge;
        vector<int> sorted;
        vector<int> mark;

        topological_sort(int n, vector<vector<int>>edge)
            : n(n), edge(edge), sorted(), mark(n) {}

        bool sort(){
            rep(i, n+1){
                if(mark[i] != 0){
                    continue;
                }
                if(not dfs(i)){
                    return false;
                }
            }
            return true;
        }

    private:
        bool dfs(int v){
            if(mark[v] == -1){
                return false;
            }
            if(mark[v] == 1){
                return true;
            }
            mark[v] = -1;

            for(int u : edge[v]){
                if(not dfs(u)){
                    return false;
                }
            }

            mark[v] = 1;
            sorted.push_back(v);
            return true;
        }
};


signed main(){
    int n, m;
    string s;
    cin >> n >> m >> s;

    vector<vector<int>> edge(2*n+1, vector<int>());
    rep(i, m){
        int a, b;
        cin >> a >> b;

        if(s[a-1] == s[b-1]){
            edge[a].push_back(b+n);
            if(a != b){
                edge[b].push_back(a+n);
            }
        }else{
            edge[a+n].push_back(b);
            edge[b+n].push_back(a);
        }
    }

    topological_sort ts(2*n+1, edge);

    cout << (ts.sort() ? "No" : "Yes") << endl;

    return 0;
}