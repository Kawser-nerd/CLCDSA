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

    int n, l, t;
    cin >> n >> l >> t;

    vector<int> x(n), w(n);
    rep(i, n) cin >> x[i] >> w[i];

    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(w[0] == w[i]){
            continue;
        }
        int diff;
        if(w[0] == 1){
            diff = (x[i] - x[0]);
        }else{
            diff = (x[0] + l - x[i]);
        }

        if(diff > t * 2){
            continue;
        }
        cnt += 1 + (t * 2 - diff) / l;
    }
    cnt %= n;

    rep(i, n){
        if(w[i] == 1){
            x[i] += t % l;
        }else{
            x[i] += l;
            x[i] -= t % l;
        }
        x[i] %= l;
    }

    if(n == 1){
        cout << x[0] << endl;
        return 0;
    }

    int id;
    if(w[0] == 1){
        id = cnt;
    }else{
        id = (n - cnt) % n;
    }
    int base = x[0];

    sort(ALL(x));
    int start = 0;
    rep(i, n){
        if(x[i] == base){
            start = i;
            if(w[0] == 1 && x[(i+1)%n] == base){
                start++;
            }
            break;
        }
    }

    rep(i, n){
        cout << x[(n+start-id)%n] << endl;
        (start += 1) %= n;
    }

    return 0;
}