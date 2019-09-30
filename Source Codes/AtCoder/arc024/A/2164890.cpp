#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
    int l, r;
    cin >> l >> r;

    vector<int> ll(l);
    rep(i, l){
        cin >> ll[i];
    }

    int ans = 0;
    rep(i, r){
        int r;
        cin >> r;
        rep(j, (int)ll.size()){
            if(r != ll[j]){
                continue;
            }
            ans++;
            ll.erase(ll.begin() + j);
            break;
        }
    }
    cout << ans << endl;

    return 0;
}