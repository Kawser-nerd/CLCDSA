#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <set>
using namespace std;


int main()
{
    const int inf = 1000000;
    int n;
    cin >> n;
    int dp[n];
    vector<int> c(n);
    for (int i=0; i<n; ++i){
        dp[i] = inf;
        cin >> c[i];
    }
    for (int i=0; i<n; ++i){
        *lower_bound(dp, dp+n, c[i]) = c[i];
    }
    int ans = n;
    for (int i=0; i<n; ++i){
        if(dp[i] == inf){
            ans -= i;
            break;
        }
        else if(i == n-1){
            ans = 0;
        }
    }
    cout << ans << endl;
    return 0;
}