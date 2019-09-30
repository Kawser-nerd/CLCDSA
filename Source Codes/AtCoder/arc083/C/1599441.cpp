#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using uint = unsigned int;
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd);
#endif

struct Node{
    int x;
    vector<Node*> dests;
    void add(Node* n){
        dests.push_back(n);
    }
    void add2(Node* n){
        add(n);
        n->add(this);
    }
    pair<int, int> dfs(){
        prints(x);
        vector<pair<int, int>> ps;
        for(Node* d : dests){
            ps.push_back(d -> dfs());
        }
        int c = dests.size(), sum = 0;
        // vector<vector<int>> dp(c, vector<int> (x + 1));
        vector<int> dp(x + 1);
        dp[0] = 1;
        for(int i = 0; i < c; i++){
            sum += ps[i].first + ps[i].second;
            vector<int> next(x + 1);
            for(int j = 0; j <= x; j++){
                if(dp[j]){
                    // next[j] = 1;
                    if(j + ps[i].first <= x){ next[j + ps[i].first] = 1; }
                    if(j + ps[i].second <= x){ next[j + ps[i].second] = 1; }
                }
            }
            dp.swap(next);
        }
        for(int i = x; i >= 0; i--){
            if(dp[i]){
                printd(i, x, sum - i);
                return {x, sum - i};
            }
        }
        cout << "IMPOSSIBLE" << '\n';
        exit(0);
        // return {x, 
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<Node> nodes(n);
    for(int i = 1; i < n; i++){
        int p; cin >> p;
        p--;
        // nodes[i].add(&nodes[p]);
        nodes[p].add(&nodes[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> nodes[i].x;
    }
    nodes[0].dfs();
    // cout << (nodes[0].dfs() ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
    cout << "POSSIBLE" << '\n';
    return 0;
}