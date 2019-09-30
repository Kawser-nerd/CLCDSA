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

    int n;
    cin >> n;
    vector<P> a(n);
    rep(i, n){
        int x, y;
        cin >> x >> y;
        if(x > y){
            swap(x, y);
        }
        a[i] = {x, y};
    }
    sort(ALL(a));

    int maxi = 0;
    for(int i = 1; i < n; i++){
        if(a[maxi].second <= a[i].second){
            maxi = i;
        }
    }

    int mini = 0;
    rep(i, n){
        if(a[mini].second >= a[i].second){
            mini = i;
        }
    }
    int ans = (a[n-1].first - a[0].first) * (a[maxi].second - a[mini].second);

    maxi = 1;
    for(int i = 1; i < n; i++){
        if(a[maxi].second <= a[i].second){
            maxi = i;
        }
    }

    multiset<int> ms;
    rep(i, n){
        if(i == 0){
            ms.insert(a[0].second);
            continue;
        }
        ms.insert(a[i].first);
    }
    for(int i = 1; i < n; i++){
        if(*ms.begin() < a[i].second){
            ms.erase(ms.find(a[i].first));
            ms.insert(a[i].second);
        }
        int tmp = (a[maxi].second - a[0].first) * (*ms.rbegin() - *ms.begin());
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}