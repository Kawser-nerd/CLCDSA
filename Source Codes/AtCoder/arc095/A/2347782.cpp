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

    vector<int> x(n);
    rep(i, n) cin >> x[i];
    vector<int> y = x;
    sort(y.begin(), y.end());

    int h = n / 2;
    rep(i, n){
        if(x[i] <= y[h-1]){
            cout << y[h] << endl;
        }else{
            cout << y[h-1] << endl;
        }
    }
    return 0;
}