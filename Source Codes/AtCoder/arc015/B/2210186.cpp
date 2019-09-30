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

    vector<int> ans(7);
    rep(i, n){
        double max, min;
        cin >> max >> min;

        if(35 <= max){
            ans[1]++;
        }
        if(30 <= max && max < 35){
            ans[2]++;
        }
        if(25 <= max && max < 30){
            ans[3]++;
        }
        if(25 <= min){
            ans[4]++;
        }
        if(0 <= max && 0 > min){
            ans[5]++;
        }
        if(0 > max){
            ans[6]++;
        }
    }
    cout << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << " " << ans[5] << " " << ans[6] << endl;

    return 0;
}