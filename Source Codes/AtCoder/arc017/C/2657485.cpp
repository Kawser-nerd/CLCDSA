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

signed main(){
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    rep(i, n) cin >> w[i];

    int h = n / 2;

    vector<int> s;
    rep(i, (1 << (n - h))){
        int weight = 0;
        for(int j = 0; j < n - h; j++){
            if(((i >> j) & 1) == 1){
                weight += w[h + j];
            }
        }
        s.push_back(weight);
    }
    sort(s.begin(), s.end());

    int ans = 0;
    rep(i, (1 << h)){
        int weight = 0;
        for(int j = 0; j < n - h; j++){
            if(((i >> j) & 1) == 1){
                weight += w[j];
            }
        }

        if(weight > x){
            continue;
        }
        int remain = x - weight;

        int l = 0;
        int r = 1 << (n - h);
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(s[mid] <= remain){
                l = mid;
            }else{
                r = mid;
            }
        }
        int ll = l;
        if(ll == (1 << (n - h)) || s[ll] != remain){
            continue;
        }

        l = -1;
        r = (1 << (n - h)) - 1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(s[mid] >= remain){
                r = mid;
            }else{
                l = mid;
            }
        }
        ans += ll - r + 1;
    }
    cout << ans << endl;

    return 0;
}