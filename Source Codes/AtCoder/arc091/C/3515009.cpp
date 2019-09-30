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

    int n, a, b;
    cin >> n >> a >> b;

    if(a * b < n || a + b > n + 1){
        cout << -1 << endl;
        return 0;
    }

    bool rev = false;
    if(a < b){
        swap(a, b);
        rev = true;
    }

    int m = n / a;
    int ex = n % a;
    int bLen = 0;
    if(ex > 0){
        bLen++;
    }

    if(bLen > b - m){
        cout << -1 << endl;
        return 0;
    }

    int need = b - bLen - m;
    while(need > 0){
        if(ex > 0){
            bLen++;
            ex--;
            need--;
            continue;
        }

        if(m <= 1){
            cout << -1 << endl;
            return 0;
        }
        m--;
        need++;
        ex += a;
    }
    //cout << m << " " << bLen << " " << ex << endl;

    vector<int> ans;
    int last = n;
    rep(i, m){
        rep(j, a){
            ans.push_back(last - a + 1 + j);
        }
        last -= a;
    }

    for(int i = 1; i <= n - m * a - bLen; i++){
        ans.push_back(i);
    }

    for(int i = n - a * m; i > n - m * a - bLen; i--){
        ans.push_back(i);
    }

    if(rev){
        reverse(ans.begin(), ans.end());
    }

    cout << ans[0];
    for(int i = 1; i < n; i++){
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}