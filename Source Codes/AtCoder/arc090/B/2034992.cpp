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
#include"debug_deque.hpp"
#define vector DebugDeque
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(prints) FUNC(printe) FUNC(printw) FUNC(printew) FUNC(printb) FUNC(printd) FUNC(printde);
#endif
template <class T>
istream& operator >> (istream& in, vector<T>& v){ for(auto& e : v){ in >> e; } return in; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> rds(n + 1);
    for(int i = 0; i < m; i++){
        int l, r, d;
        cin >> l >> r >> d;
        rds[l].emplace_back(r, d);
        rds[r].emplace_back(l, -d);
    }
    unordered_set<int> checked;
    bool ok = true;
    for(int i = 1; i <= n && ok; i++){
        printd(checked);
        if(checked.count(i)){ continue; }
        queue<int> q;
        q.push(i);
        unordered_map<int, int> poss;
        while(ok && q.size()){
            int idx = q.front(); q.pop();
            checked.insert(idx);
            for(auto& rd : rds[idx]){
                int pos = poss[idx];
                int i2 = rd.first;
                int p2 = pos + rd.second;
                if(!checked.count(i2)){
                    checked.insert(i2);
                    q.push(i2);
                }
                if(!poss.count(i2)){
                    poss[i2] = p2;
                }else{
                    if(poss[i2] != p2){
                        ok = false;
                    }
                }
            }
            printd(poss);
        }
    }
    cout << (ok ? "Yes" : "No") << '\n';
}