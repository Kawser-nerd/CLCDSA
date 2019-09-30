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
    int n, p;
    cin >> n >> p;
    vector<P> item;
    rep(i, n){
        int a, b;
        cin >> a >> b;
        item.emplace_back(a, b);
    }

    sort(item.begin(), item.end(), greater<P>());
    vector<int> dp(p + 101, 0);
    int ans = 0;
    rep(i, n){
        int weight = item[i].first;
        int value = item[i].second;
        vector<int> tmp(p + 101);

        for(int j = p + 100; j >= 0; j--){
            if(j - weight < 0){
                tmp[j] = dp[j];
                continue;
            }

            tmp[j] = max(dp[j], dp[j-weight] + value);
        }

        if(ans < tmp[p+weight]){
            ans = tmp[p+weight];
        }
        swap(dp, tmp);
    }
    cout << ans << endl;

    return 0;
}