#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int

using namespace std;

typedef pair<int, int> P;

const int inf = 1e15;
const int mod = 1e9+7;

signed main(){
    int n;
    cin >> n;

    vector<int> d(n);
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    sort(d.begin(), d.end());

    vector<int> x(n), y(n+1);
    for(int i = n-1; i >= 0; i--){
        int l = i-1;
        int r = n;
        while(r - l > 1){
            int m = (l + r) / 2;
            if(d[m] >= d[i] * 2){
                r = m;
            }else{
                l = m;
            }
        }
        x[i] = r;
        if(r == n){
            y[i] = y[i+1];
            continue;
        }
        y[i] = y[i+1] + n - r;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int l = -1;
        int r = i+1;
        while(r - l > 1){
            int m = (l + r) / 2;
            if(d[m] <= d[i] / 2){
                l = m;
            }else{
                r = m;
            }
        }

        if(l == -1 || x[i] == n || y[x[i]] == 0){
            continue;
        }
        ans += (l+1) * y[x[i]] % mod;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}