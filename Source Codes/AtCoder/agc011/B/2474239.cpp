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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    vector<int> s(n);
    s[0] = a[0];
    for(int i = 1; i < n; i++){
        s[i] = s[i-1] + a[i];
    }

    int ans = 1;
    for(int i = n-2; i >= 0; i--){
        if(s[i] * 2 >= a[i+1]){
            ans++;
        }else{
            break;
        }
    }
    cout << ans << endl;

    return 0;
}