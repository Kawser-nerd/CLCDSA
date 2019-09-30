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
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int best = INF;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            if(i == j){
                continue;
            }
            int tmp = 0;
            for(int k = 0; k < n; k++){
                if(k % 2 == 0){
                    tmp += a[k] == i ? 0 : 1;
                }else{
                    tmp += a[k] == j ? 0 : 1;
                }
            }
            if(tmp < best){
                best = tmp;
            }
        }
    }

    cout << best * c << endl;
    return 0;
}