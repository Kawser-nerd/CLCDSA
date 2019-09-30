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
    vector<int> x(n + 1);
    rep(i, n) cin >> x[i+1];
    int len, q;
    cin >> len >> q;

    vector<vector<int>> l(31, vector<int>(n+1)), r(31, vector<int>(n+1));
    for(int i = 1; i <= n; i++){
        int lo, hi;
        lo = 1;
        hi = n + 1;
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            if(x[mid] <= x[i] + len){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        r[0][i] = lo;

        lo = 0;
        hi = n;
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            if(x[mid] >= x[i] - len){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        l[0][i] = hi;
    }

    rep(i, 30){
        for(int j = 1; j <= n; j++){
            r[i+1][j] = r[i][r[i][j]];
            l[i+1][j] = l[i][l[i][j]];
        }
    }

    vector<int> p(31);
    p[0] = 1;
    rep(i, 30) p[i+1] = p[i] * 2;

    rep(i, q){
        int a, b;
        cin >> a >> b;
        int ans = 0;
        int pos = a;

        int id = 0;
        if(a < b){
            while(pos < b){
                if(r[id][pos] < b){
                    id++;
                    continue;
                }
                if(id == 0){
                    id++;
                    ans++;
                    break;
                }
                ans += p[id-1];
                pos = r[id-1][pos];
                id = 0;
            }
        }else{
            while(pos > b){
                if(l[id][pos] > b){
                    id++;
                    continue;
                }
                if(id == 0){
                    id++;
                    ans++;
                    break;
                }
                ans += p[id-1];
                pos = l[id-1][pos];
                id = 0;
            }
        }
        cout << ans << endl;
    }

    return 0;
}