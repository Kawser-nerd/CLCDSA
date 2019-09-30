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
    int n;
    cin >> n;

    vector<int> ans;
    for(int i = n-9*17; i < n; i++){
        int j = i;
        int tmp = 0;
        while(j != 0){
            tmp += j % 10;
            j /= 10;
        }
        if(tmp + i == n){
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for(int i = 0; i < (int)ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}