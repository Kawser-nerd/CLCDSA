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
    int n, m;
    cin >> n >> m;
    vector<int> x(n+1);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        x[a] = (x[a] + 1) % 2;
        x[b] = (x[b] + 1) % 2;
    }

    rep(i, n){
        if(x[i+1] == 1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}