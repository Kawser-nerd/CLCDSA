#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
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
    signed n;
    cin >> n;

    vector<int> t(n);
    rep(i, n){
        cin >> t[i];
    }

    int best;
    int diff = 1000;
    for(int i = 1; i < (2 << n) - 1; i++){
        int a = 0;
        int b = 0;

        for(int j = 0; j < n; j++){
            if(((i >> j) & 1) == 1){
                a += t[j];
            }else{
                b += t[j];
            }
        }
        if(diff > abs(a - b)){
            diff = abs(a - b);
            best = max(a, b);
        }
    }
    cout << best << endl;

    return 0;
}