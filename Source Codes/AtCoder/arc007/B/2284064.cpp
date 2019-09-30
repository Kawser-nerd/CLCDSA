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

    vector<int> d(n+1);
    for(int i = 1; i <= n; i++){
        d[i] = i;
    }

    int now = 0;
    rep(i, m){
        int c;
        cin >> c;

        swap(d[now], d[c]);
        now = c;
    }

    vector<P> ans(n+1);
    for(int i = 0; i <= n; i++){
        ans[i] = make_pair(d[i], i);
    }
    sort(ans.begin(), ans.end());

    for(int i = 1; i <= n; i++){
        cout << ans[i].second << endl;
    }

    return 0;
}