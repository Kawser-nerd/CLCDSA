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

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> b = a;

    int ans1 = 0;
    for(int i = 1; i <= n; i++){
        ans1 += a[i] / 2;
        a[i] %= 2;
        if(i < n && a[i] > 0 && a[i+1] > 0){
            ans1++;
            a[i]--;
            a[i+1]--;
        }
    }

    int ans2 = 0;
    for(int i = n; i >= 1; i--){
        ans2 += a[i] / 2;
        a[i] %= 2;
        if(i > 1 && a[i] > 0 && a[i-1] > 0){
            ans2++;
            a[i]--;
            a[i-1]--;
        }
    }
    cout << max(ans1, ans2) << endl;

    return 0;
}