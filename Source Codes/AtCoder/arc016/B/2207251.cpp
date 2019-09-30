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
    int n;
    cin >> n;

    vector<string> s(n);
    rep(i, n) cin >> s[i];

    int ans = 0;
    rep(i, n){
        rep(j, 9){
            if(s[i][j] == 'x'){
                ans++;
            }
        }
    }

    for(int i = 0; i < n-1; i++){
        rep(j, 9){
            if(i == 0 && s[i][j] == 'o'){
                ans++;
            }
            if(s[i][j] != 'o' && s[i+1][j] == 'o'){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}