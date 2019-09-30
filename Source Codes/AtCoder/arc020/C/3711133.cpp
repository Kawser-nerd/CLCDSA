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

int pow10(const vector<int>& t, int x, int b){
    int res = 1;
    int i = 0;
    //cout << " " << x << " ";
    while(x != 0){
        if(x % 2){
            res *= t[i];
            res %= b;
        }
        x /= 2;
        i++;
    }
    //cout << res << endl;
    return res;
}

signed main(){
    int n, b;
    cin >> n;

    vector<int> a(n), l(n);
    rep(i, n) cin >> a[i] >> l[i];
    cin >> b;

    vector<int> cnt(n), zcnt(n);
    for(int i = n-1; i >= 0; i--){
        int x = a[i];
        while(x > 0){
            cnt[i]++;
            x /= 10;
        }
        if(i == 0){
            break;
        }
        zcnt[i-1] = zcnt[i] + cnt[i] * l[i];
    }

    vector<int> t(60);
    t[0] = 10 % b;
    rep(i, 59){
        //cout << i << " " << t[i] << endl;
        t[i+1] = t[i] * t[i] % b;
    }
    //cout << endl;

    int ans = 0;
    rep(i, n){
        vector<int> tt(30);
        tt[0] = a[i] % b;
        int k = cnt[i];
        rep(j, 29){
            //cout << a[i] << " " << j << " " << tt[j] << " " << k << endl;
            tt[j+1] = tt[j] * pow10(t, k, b) % b;
            tt[j+1] += tt[j];
            tt[j+1] %= b;
            k *= 2;
        }

        int tmp = 0;
        int m = l[i];
        int j = 0;
        k = 0;
        while(m != 0){
            if(m % 2){
                tmp += tt[j] * pow10(t, k, b) % b;
                tmp %= b;
                //cout << " " << j << " " << k << " " << tmp << endl;
                k += cnt[i] * round(pow(2, j));
            }
            m /= 2;
            j++;
        }
        tmp *= pow10(t, zcnt[i], b);
        tmp %= b;
        ans += tmp;
        ans %= b;
    }
    cout << ans << endl;

    return 0;
}