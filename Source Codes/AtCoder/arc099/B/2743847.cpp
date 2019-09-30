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

double snuke(int n){
    int m = n;
    int s = 0;
    while(m != 0){
        s += m % 10;
        m /= 10;
    }
    return (double)n / s;
}

signed main(){
    int k;
    cin >> k;

    vector<int> a;

    rep(i, 15){
        for(int j = 1; j < 150; j++){
            int x = j;
            rep(k, i){
                x *= 10;
                x += 9;
            }
            a.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    vector<bool> sn((int)a.size(), true);
    rep(i, (int)a.size()){
        for(int j = i+1; j < (int)a.size(); j++){
            if(snuke(a[i]) > snuke(a[j])){
                sn[i] = false;
            }
        }
    }

    vector<int> ans;
    rep(i, (int)a.size()){
        if(sn[i]){
            ans.push_back(a[i]);
        }
    }

    rep(i, k){
        cout << ans[i] << endl;
    }

    return 0;
}