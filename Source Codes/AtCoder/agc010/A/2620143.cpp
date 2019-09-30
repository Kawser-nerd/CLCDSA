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

    int ans = 0;
    rep(i, n){
        int a;
        cin >> a;
        if(a % 2 == 1){
            ans++;
        }
    }

    if(ans % 2 == 0){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;

    return 0;
}