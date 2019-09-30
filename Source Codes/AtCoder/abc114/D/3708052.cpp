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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

vector<int> prime(int n){
    vector<int> t;
    vector<bool> x(n+1, true);
    t.push_back(2);

    int i;
    for(i = 3; i * i <= n; i += 2){
        if(!x[i]){
            continue;
        }
        t.push_back(i);
        for(int j = i; j <= n; j += i){
            x[j] = false;
        }
    }
    for(; i <= n; i += 2){
        if(x[i]){
            t.push_back(i);
        }
    }
    return t;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> p = prime(n);
    vector<int> cnt(SZ(p));
    for(int i = 1; i <= n; i++){
        int x = i;
        for(int j = 0; j < SZ(p); j++){
            while(x % p[j] == 0){
                x /= p[j];
                cnt[j]++;
            }
        }
    }

    int ans = 0;

    rep(i, SZ(p)){
        if(cnt[i] >= 74){
            ans++;
        }
        for(int j = i + 1; j < SZ(p); j++){
            if(cnt[i] >= 2 && cnt[j] >= 24){
                ans++;
            }
            if(cnt[i] >= 24 && cnt[j] >= 2){
                ans++;
            }
            if(cnt[i] >= 4 && cnt[j] >= 14){
                ans++;
            }
            if(cnt[i] >= 14 && cnt[j] >= 4){
                ans++;
            }
            for(int k = j + 1; k < SZ(p); k++){
                if(cnt[i] >= 2 && cnt[j] >= 4 && cnt[k] >= 4){
                    ans++;
                }
                if(cnt[i] >= 4 && cnt[j] >= 2 && cnt[k] >= 4){
                    ans++;
                }
                if(cnt[i] >= 4 && cnt[j] >= 4 && cnt[k] >= 2){
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}