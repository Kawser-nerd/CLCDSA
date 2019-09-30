#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
  
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int dp[3001]; // dp[i] = j; := i[g]???????????????

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    for (int i = 0; i <= F; i++) {
        dp[i] = -1;
    }
    dp[0] = 0;

    // satoumizu: i
    // satou: dp[i]
    // mizu = i - dp[i]
    // E
    // mizu : maxsatou = i - dp[i] : E
    // 100 * dp[i] / (i - dp[i]) <= E
    // 100 * dp[i] <= E * (i - dp[i])
    for(int i = 0; i <= F; i++) {
        if (dp[i] == -1) continue;
        if (i + A * 100 <= F) dp[i + A * 100] = max(dp[i + A * 100], dp[i]);
        if (i + B * 100 <= F) dp[i + B * 100] = max(dp[i + B * 100], dp[i]);
        if (i + C <= F && (100 * (dp[i] + C) <= E * (i - dp[i]))) dp[i + C] = max(dp[i + C], dp[i] + C);
        if (i + D <= F && (100 * (dp[i] + D) <= E * (i - dp[i]))) dp[i + D] = max(dp[i + D], dp[i] + D);
    }
/*
    for (int i = 0; i <= F; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
*/
    double m = -1;
    int ans1, ans2;
    for (int i = 0; i <= F; i++) {
        if (dp[i] == -1) continue;
        if (100 * dp[i] <= E * i) {
            if (m < (double)dp[i] / i) {
                m = (double)dp[i] / i;
                ans1 = i;
                ans2 = dp[i];
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;

    return 0;
}