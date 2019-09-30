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
const double EPS = 1e-10;

int area(P a, P b, P c){
    int x1 = a.first - b.first;
    int x2 = a.first - c.first;
    int y1 = a.second - b.second;
    int y2 = a.second - c.second;

    return x1 * y2 - x2 * y1;
}

signed main(){
    int n;
    cin >> n;

    vector<P> p(n);
    rep(i, n){
        int x, y;
        cin >> x >> y;
        p[i] = make_pair(x, y);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(i == j || j == k || k == i){
                    continue;
                }
                int s = area(p[i], p[j], p[k]);
                if(s != 0 && s % 2 == 0){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}