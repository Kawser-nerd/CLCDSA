#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int find(int v, vector<int>& p){
    if('0' <= v && v <= '9'){
        return v - '0';
    }
    if(p[v] == -1){
        return v;
    }
    p[v] = find(p[v], p);
    return p[v];
}

void unite(int u, int v, vector<int>& p){
    int u_root = find(u, p);
    int v_root = find(v, p);

    if(u_root == v_root){
        return;
    }
    if(u_root < v_root){
        p[v_root] = u_root;
    }else{
        p[u_root] = v_root;
    }
}

signed main(){
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    vector<int> p(150, -1);
    unite(s1[0], 10, p);
    unite(s2[0], 10, p);
    for(int i = 1; i < n; i++){
        unite(s1[i], s2[i], p);
    }

    int ans = 1;
    vector<bool> q(150, false);
    rep(i, n){
        int pp = find(s1[i], p);
        if(q[pp] || 0 <= pp && pp <= 9){
            continue;
        }
        q[pp] = true;
        if(pp == 10){
            ans *= 9;
            continue;
        }
        ans *= 10;
    }
    cout << ans << endl;
    return 0;
} ./Main.cpp:60:29: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if(q[pp] || 0 <= pp && pp <= 9){
                 ~~ ~~~~~~~~^~~~~~~~~~
./Main.cpp:60:29: note: place parentheses around the '&&' expression to silence this warning
        if(q[pp] || 0 <= pp && pp <= 9){
                            ^
                    (                 )
1 warning generated.