// A - Biscuits: https://beta.atcoder.jp/contests/agc017/tasks/agc017_a
// P=0?P=1??????P=0????????????????????P-1?????????????????????
// N>=50???int?????

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
 
long long dp[51][51];
 
long long comb(int n, int r) {
    if (dp[n][r] != -1) return dp[n][r];
    if (r == 0) return dp[n][r] = 1;
    if (n == r) return dp[n][r] = 1;
    return dp[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
}
 
int main() {
 
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            dp[i][j] = -1;
        }
    }
 
    int N, P;
    cin >> N >> P;
    vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] %= 2;
        sum += A[i];
    }
    int rest = N - sum;
    long long ret = 0;
    if (P == 0) {
        for(int i = 0; i <= sum; i+=2) {
            ret += comb(sum, i) * (1LL << rest);
        }
    } else {
        for(int i = 1; i <= sum; i+=2) {
            ret += comb(sum, i) * (1LL << rest);
        }
    }
    cout << ret << endl;
 
    return 0;
}