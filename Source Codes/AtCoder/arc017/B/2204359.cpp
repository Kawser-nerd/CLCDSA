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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> inc;
    int before = a[0];
    int len = 1;
    for(int i = 1; i < n; i++){
        if(before >= a[i]){
            inc.push_back(len);
            len = 0;
        }
        before = a[i];
        len++;
    }
    inc.push_back(len);

    int ans = 0;
    for(int i = 0; i < (int)inc.size(); i++){
        if(k > inc[i]){
            continue;
        }

        ans += inc[i] - k + 1;
    }
    cout << ans << endl;

    return 0;
}