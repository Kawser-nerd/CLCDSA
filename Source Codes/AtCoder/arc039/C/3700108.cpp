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
    int k;
    string s;
    cin >> k >> s;

    map<P, P> u, d, r, l;
    u[{0, 0}] = {0, 1};
    d[{0, 0}] = {0, -1};
    r[{0, 0}] = {1, 0};
    l[{0, 0}] = {-1, 0};

    u[{0, -1}] = {0, 1};
    d[{0, 1}] = {0, -1};
    r[{-1, 0}] = {1, 0};
    l[{1, 0}] = {-1, 0};

    P pos = {0, 0};
    rep(i, k){
        P nxt;
        if(s[i] == 'U'){
            nxt = u[pos];
            if(u.find(nxt) == u.end()){
                u[nxt] = {nxt.first, nxt.second + 1};
            }
            if(r.find(nxt) == r.end()){
                r[nxt] = {nxt.first + 1, nxt.second};
            }
            if(l.find(nxt) == l.end()){
                l[nxt] = {nxt.first - 1, nxt.second};
            }
            u[d[pos]] = u[nxt];
            d[nxt] = d[pos];
            r[l[nxt]] = r[nxt];
            l[r[nxt]] = l[nxt];
            d[u[nxt]] = d[pos];
        }
        if(s[i] == 'D'){
            nxt = d[pos];
            if(d.find(nxt) == d.end()){
                d[nxt] = {nxt.first, nxt.second - 1};
            }
            if(r.find(nxt) == r.end()){
                r[nxt] = {nxt.first + 1, nxt.second};
            }
            if(l.find(nxt) == l.end()){
                l[nxt] = {nxt.first - 1, nxt.second};
            }
            u[nxt] = u[pos];
            d[u[pos]] = d[nxt];
            r[l[nxt]] = r[nxt];
            l[r[nxt]] = l[nxt];
            u[d[nxt]] = u[pos];
        }
        if(s[i] == 'R'){
            nxt = r[pos];
            if(u.find(nxt) == u.end()){
                u[nxt] = {nxt.first, nxt.second + 1};
            }
            if(d.find(nxt) == d.end()){
                d[nxt] = {nxt.first, nxt.second - 1};
            }
            if(r.find(nxt) == r.end()){
                r[nxt] = {nxt.first + 1, nxt.second};
            }
            u[d[nxt]] = u[nxt];
            d[u[nxt]] = d[nxt];
            r[l[pos]] = r[nxt];
            l[nxt] = l[pos];
            l[r[nxt]] = l[pos];
        }
        if(s[i] == 'L'){
            nxt = l[pos];
            if(u.find(nxt) == u.end()){
                u[nxt] = {nxt.first, nxt.second + 1};
            }
            if(d.find(nxt) == d.end()){
                d[nxt] = {nxt.first, nxt.second - 1};
            }
            if(l.find(nxt) == l.end()){
                l[nxt] = {nxt.first - 1, nxt.second};
            }
            u[d[nxt]] = u[nxt];
            d[u[nxt]] = d[nxt];
            r[nxt] = r[pos];
            l[r[pos]] = l[nxt];
            r[l[nxt]] = r[pos];
        }
        pos = nxt;
    }
    cout << pos.first << " " << pos.second << endl;

    return 0;
}