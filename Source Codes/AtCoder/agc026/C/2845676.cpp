#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include<cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include<bitset>

#define REP(i, b, n) for(int i=b;i<(int)n;i++)
#define rep(i, n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define FOR(it, o)  for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)
#define dbg(x) cout << __LINE__ << ' ' << #x << " = " << (x) << endl


typedef long long ll;

using namespace std;

//??????????????!!

ll dp[20][20];

ll solve(string &R, string &sub1, string &sub2){
    rep(i, 19)rep(j, 19)dp[i][j] = 0;
    dp[0][0] = 1;

        rep(i, sub1.length()+1){
            rep(j, sub2.length()+1){
                ll now = dp[i][j];
                if(i<sub1.length() && R[i+j] == sub1[i]){
                    dp[i+1][j] += now;
                }
                if(j<sub2.length() && R[i+j] == sub2[j]){
                    dp[i][j+1] += now;
                }
            }
        }
    return dp[sub1.length()][sub2.length()];
}

int main() {
    ll N;
    cin >> N;
    string S;
    cin >> S;

    string R = S;
    reverse(ALL(R));
    ll ans = 0;

    rep(bit, (1<<N)){
        string s;
        bitset<20> B(bit);
        string sub[2];
        rep(i, N){
            sub[B[i]] += S[i];
        }
        ans += solve(R, sub[0], sub[1]);
    }
    cout << ans <<endl;

    return 0;
}