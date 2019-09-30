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
    int l;
    cin >> l;

    vector<int> b(l);
    rep(i, l) cin >> b[i];

    int bb = 0;
    rep(i, l-1) bb ^= b[i];
    if(bb != b[l-1]){
        cout << -1 << endl;
        return 0;
    }

    int a = 0;
    rep(i, l){
        cout << a << endl;
        a = b[i] ^ a;
    }

    return 0;
}