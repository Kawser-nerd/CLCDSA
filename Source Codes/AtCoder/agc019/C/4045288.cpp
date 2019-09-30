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

//Longest Increasing Subsequence
int lis(const vector<P>& a, int begin, int end, int low, int high){
    int n = end - begin;
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    int i = 0;
    for(int j = begin; j < end; j++){
        if(a[begin+i].second > high || a[begin+i].second < low){
            i++;
            continue;
        }
        int l = 0;
        int r = n;
        while(r - l > 1){
            int m = (r + l) / 2;
            if(dp[m] < a[begin+i].second){
                l = m;
            }else{
                r = m;
            }
        }
        dp[l+1] = a[begin+i].second;
        i++;
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(dp[i] != INF){
            ans = i;
        }
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 > x2){
        swap(x1, x2);
        swap(y1, y2);
    }

    int n;
    cin >> n;
    vector<P> h(n);
    rep(i, n){
        int x, y;
        cin >> x >> y;
        h[i] = {x, y};
    }
    h.emplace_back(-INF, -INF);
    h.emplace_back(INF, INF);
    n += 2;
    sort(ALL(h));

    double diff = 20.0 - 20.0 * M_PI / 4.0;
    double ans = abs(x1 - x2) + abs(y1 - y2);
    ans *= 100.0;
    int begin, end;
    if(y1 <= y2){
        int lo = -1;
        int hi = n - 1;
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            if(h[mid].first >= x1){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        begin = hi;

        lo = -1;
        hi = n - 1;
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            if(h[mid].first > x2){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        end = hi;
    }else{
        reverse(ALL(h));
        int lo = -1;
        int hi = n - 1;
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            if(h[mid].first <= x2){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        begin = hi;

        lo = -1;
        hi = n - 1;
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            if(h[mid].first < x1){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        end = hi;
    }

    int cnt = lis(h, begin, end, min(y1, y2), max(y1, y2));
    if(cnt == min(abs(x2 - x1), abs(y2 - y1)) + 1){
        cnt--;
        ans += 20.0 * M_PI / 2.0 - 20.0;
    }
    ans -= diff * cnt;
    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}