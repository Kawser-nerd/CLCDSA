#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n, m, x0, a, p;
    cin >> n >> m >> x0 >> a >> p;

    vector<tuple<int, int, int>> x(n*m);
    vector<vector<int>> bef(n, vector<int>(m));
    rep(i, n){
        rep(j, m){
            if(i == 0 && j == 0){
                x[0] = make_tuple(x0, i, j);
                bef[0][0] = get<0>(x[0]);
                continue;
            }
            int score = (get<0>(x[i*m+j-1]) + a) % p;
            x[i*m+j] = make_tuple(score, i, j);
            bef[i][j] = get<0>(x[i*m+j]);
        }
    }
    sort(x.begin(), x.end());

    int ans = 0;
    rep(i, n){
        vector<int> a(m);
        rep(j, m){
            a[j] = get<2>(x[i*m+j]);
            ans += abs(get<1>(x[i*m+j]) - i);
        }
        sort(a.begin(), a.end());
        rep(j, m){
            ans += abs(a[j] - j);
        }
    }
    cout << ans << endl;

    return 0;
}