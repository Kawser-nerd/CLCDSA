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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> s(m + 2);
    rep(i, n - 1){
        if(a[i] < a[i+1]){
            s[a[i]+1] += 1;
            s[a[i+1]] += -1;
            continue;
        }
        s[0] += 1;
        s[a[i+1]] += -1;
        s[a[i]+1] += 1;
        s[m+1] += -1;
    }
    rep(i, m){
        s[i+1] += s[i];
    }

    vector<vector<int>> x(m+1, vector<int>());
    rep(i, n-1){
        x[a[i+1]].push_back(a[i]);
    }

    int ans = 0;
    rep(i, n-1){
        int tmp1 = (a[i+1] + m - a[i]) % m;
        int tmp2 = 1 + (a[i+1] + m - 1) % m;
        ans += min(tmp1, tmp2);
    }

    int now = ans;
    for(int i = 1; i < m; i++){
        for(int j : x[i]){
            now += (i + m - j) % m - 1;
        }
        now -= s[i];
        ans = min(ans, now);
    }
    cout << ans << endl;

    return 0;
}