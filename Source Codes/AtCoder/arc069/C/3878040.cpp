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
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    map<int, int> minIdx, cnt;
    rep(i, n){
        if(minIdx.find(a[i]) == minIdx.end()){
            minIdx[a[i]] = i;
            cnt[a[i]] = 0;
        }
        cnt[a[i]]++;
    }

    vector<int> ans(n);
    int sum = 0;
    auto now = minIdx.rbegin();
    auto nxt = now;
    nxt++;
    int idx = now->second;
    for(; nxt != minIdx.rend(); nxt++){
        sum += cnt[now->first];
        ans[idx] += sum * (now->first - nxt->first);
        idx = min(idx, nxt->second);
        now++;
    }
    ans[0] += n * now->first;

    rep(i, n){
        cout << ans[i] << endl;
    }

    return 0;
}