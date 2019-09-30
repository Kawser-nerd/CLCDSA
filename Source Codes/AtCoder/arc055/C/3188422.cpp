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

class rolling_hash{
    private:
        const static int mod1 = 999999937LL;
        const static int mod2 = 1000000007LL;
        const static int base = 9973;

    public:
        int n;
        string s;
        vector<int> hash1, hash2, pow1, pow2;

        rolling_hash(string s)
            :n(s.length()), s(s), hash1(n+1), hash2(n+1), pow1(n+1, 1), pow2(n+1, 1){
                rep(i, n){
                    hash1[i+1] = (hash1[i] + s[i]) * base % mod1;
                    hash2[i+1] = (hash2[i] + s[i]) * base % mod2;
                    pow1[i+1] = pow1[i] * base % mod1;
                    pow2[i+1] = pow2[i] * base % mod2;
                }

            }

        //[l, r)
        P hash(int l, int r){
            int t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
            int t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
            return make_pair(t1, t2);
        }

        bool compare(int l1, int r1, int l2, int r2){
            return hash(l1, r1) == hash(l2, r2);
        }
};

signed main(){
    string s;
    cin >> s;
    int n = s.length();

    rolling_hash rh(s);

    int ans = 0;
    for(int i = 3; i < n - 1; i++){
        if(i <= n - i){
            continue;
        }

        int lo, hi;
        lo = 0;
        hi = n - i + 1;
        while(hi - lo > 1){
            int mid = (hi + lo) / 2;
            if(rh.compare(0, mid, i, i + mid)){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        int la = min(n - i - 1, lo);

        lo = 0;
        hi = n - i + 1;
        while(hi - lo > 1){
            int mid = (hi + lo) / 2;
            if(rh.compare(i - mid, i, n - mid, n)){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        int lc = min(n - i - 1, lo);

        ans += max(0LL, la + lc - n + i + 1);
    }
    cout << ans << endl;

    return 0;
}