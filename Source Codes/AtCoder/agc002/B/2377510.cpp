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
    int n, m;
    cin >> n >> m;

    vector<bool> a(n+1, false);
    vector<int> b(n+1, 1);
    a[1] = true;
    rep(i, m){
        int x, y;
        cin >> x >> y;

        if(a[x]){
            a[y] = true;
            b[x]--;
            b[y]++;
        }else{
            b[x]--;
            b[y]++;
        }
        if(b[x] == 0){
            a[x] = false;
        }
    }

    int ans = 0;
    rep(i, n+1){
        if(a[i]){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}