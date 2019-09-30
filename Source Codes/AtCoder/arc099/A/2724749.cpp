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

int calc(int n, int K){
    int ret = n / (K-1);
    if(n%(K-1) != 0)ret++;
    return ret;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int mini = 1e9;
    rep(i, N) mini = min(mini, A[i]);

    vector<int> distR(N);
    int now = 1e9;
    rep(i, N){
        now++;
        if(A[N-i-1] == mini)now = 0;
        distR[N-i-1] = now;
    }

    bool needMini = true;
    int remain = 0;
    int ans = 0;
    rep(i, N){
        if(A[i] == mini){
            needMini = false;
            remain--;
            continue;
        }
        // ???????????
        if(needMini){
            assert(remain >= 0);
            if(remain <= 1){
                ans++;
                remain = K;
            }
            remain--;
            continue;
        }
       // ??????
        else{
            // ???
            if(remain <= 0){
                // ??????????????????
                if(distR[i] != 1e9){
                    needMini = true;
                    remain = K;
                }
                else{
                    // ???????
                    needMini = false;
                    remain = K-1;
                }
                ans++;
            }
            remain--;
        }
    }
    cout << ans <<endl;
    return 0;
}