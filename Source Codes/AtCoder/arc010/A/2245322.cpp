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
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    rep(i, m){
        int c;
        cin >> c;

        if(n <= a){
            n += b;
        }

        n -= c;
        if(n < 0){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << "complete" << endl;

    return 0;
}