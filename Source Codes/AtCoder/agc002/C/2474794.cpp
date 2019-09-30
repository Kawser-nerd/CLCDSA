#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
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
    int n, l;
    cin >> n >> l;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    stack<int> ans;
    rep(i, n-1){
        if(a[i] + a[i+1] >= l){
            ans.push(i+1);
            break;
        }
    }

    if(ans.empty()){
        cout << "Impossible" << endl;
        return 0;
    }

    int x = ans.top();
    for(int i = x - 1; i > 0; i--){
        ans.push(i);
    }
    for(int i = x + 1; i < n; i++){
        ans.push(i);
    }

    cout << "Possible" << endl;
    while(!ans.empty()){
        cout << ans.top() << endl;
        ans.pop();
    }

    return 0;
}