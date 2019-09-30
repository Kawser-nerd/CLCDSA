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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n, m;
    cin >> n >> m;

    vector<P> M, F;
    rep(i, n){
        int a, b;
        cin >> a >> b;
        M.emplace_back(a, b);
    }
    rep(i, m){
        int c, d;
        cin >> c >> d;
        F.emplace_back(d, c);
    }
    sort(M.begin(), M.end());
    sort(F.begin(), F.end());

    int ans = 0;
    multiset<int> ms;
    int j = 0;
    rep(i, n){
        int a = M[i].first;
        int b = M[i].second;

        while(j < m && F[j].first <= a){
            ms.insert(F[j++].second);
        }

        auto it = ms.upper_bound(b-1);
        if(it != ms.end()){
            ans++;
            ms.erase(it);
        }
    }
    cout << ans << endl;

    return 0;
}