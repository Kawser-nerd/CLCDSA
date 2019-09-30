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

    int n, k;
    cin >> n >> k;
    vector<P> a(n);
    rep(i, n){
        int t, d;
        cin >> t >> d;
        a[i] = {d, t};
    }
    sort(ALL(a), greater<P>());

    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> s;
    int ans = 0;
    int kind = 0;
    for(int i = 0; i < k; i++){
        ans += a[i].first;
        if(s.find(a[i].second) != s.end()){
            pq.push(a[i].first);
            continue;
        }
        s.insert(a[i].second);
        kind++;
    }
    ans += kind * kind;

    int tmp = ans;
    for(int i = k; i < n; i++){
        if(pq.empty()){
            break;
        }
        if(s.find(a[i].second) != s.end()){
            continue;
        }
        tmp -= pq.top();
        pq.pop();
        tmp += a[i].first;
        tmp += (kind + 1) * (kind + 1) - kind * kind;
        s.insert(a[i].second);
        kind++;

        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}