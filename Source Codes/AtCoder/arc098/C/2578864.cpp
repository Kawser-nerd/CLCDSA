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
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = INF;
    rep(i, n){
        int l = 0, r = 0;
        vector<int> b;
        b.push_back(a[i]);

        while(l < n){
            if(a[l] < a[i]){
                l++;
                r = l;
                continue;
            }
            if(r < n && a[r] >= a[i]){
                r++;
                continue;
            }

            vector<int> c;
            for(int j = l; j < r; j++){
                if(j == i){
                    continue;
                }
                c.push_back(a[j]);
            }
            if((int)c.size() >= k){
                sort(c.begin(), c.end());
                for(int j = 0; j <= (int)c.size()-k; j++){
                    b.push_back(c[j]);
                }
            }
            l = r;
        }
        if(q > (int)b.size()){
            continue;
        }
        sort(b.begin(), b.end());
        int tmp = b[q-1] - b[0];
        if(tmp < ans){
            ans = tmp;
        }
    }
    cout << ans << endl;

    return 0;
}