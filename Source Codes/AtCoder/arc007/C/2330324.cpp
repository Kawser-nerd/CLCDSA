#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int popcount(int n){
    if(n == 0){
        return 0;
    }

    return (n & 1) + popcount(n >> 1);
}

bool solve(vector<bool> a, const vector<bool>& b, int s){
    for(int i = 1; i < (int)a.size(); i++){
        if((s >> i & 1) == 0){
            continue;
        }
        rep(j, (int)a.size()){
            if(not b[j]){
                continue;
            }
            int x = (i + j) % (int)a.size();
            a[x] = a[x] || true;
        }
    }

    bool ret = true;
    rep(i, (int)a.size()){
        ret = ret && a[i];
    }
    return ret;
}

signed main(){
    string s;
    cin >> s;

    vector<bool> a((int)s.size(), false);
    rep(i, (int)s.size()){
        if(s[i] == 'o'){
            a[i] = true;
        }
    }

    int ans = INF;
    for(int i = 0; i < 1 << (int)a.size(); i++){
        if(solve(a, a, i) && popcount(i) + 1 < ans){
            ans = popcount(i) + 1;
        }
    }
    cout << ans << endl;
    return 0;
}