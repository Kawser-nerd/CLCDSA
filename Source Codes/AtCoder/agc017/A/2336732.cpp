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
    int n, p;
    cin >> n >> p;

    int b0, b1;
    b0 = b1 = 0;
    rep(i, n){
        int a;
        cin >> a;
        if(a % 2 == 0){
            b0++;
        }else{
            b1++;
        }
    }

    if(b0 == n && p == 0){
        cout << (1LL << n) << endl;
        return 0;
    }
    if(b0 == n && p == 1){
        cout << 0 << endl;
        return 0;
    }

    cout << (1LL << (n - 1)) << endl;

    return 0;
}