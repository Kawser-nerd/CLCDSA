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

    vector<vector<int>> x(n, vector<int>(3));
    rep(i, n){
        cin >> x[i][0] >> x[i][1] >> x[i][2];
        sort(x[i].begin(), x[i].end());
    }

    int a, b, c;
    a = b = c = 0;
    rep(i, n){
        if(a < x[i][0]){
            a = x[i][0];
        }
        if(b < x[i][1]){
            b = x[i][1];
        }
        if(c < x[i][2]){
            c = x[i][2];
        }
    }
    cout << a * b * c << endl;
    return 0;
}