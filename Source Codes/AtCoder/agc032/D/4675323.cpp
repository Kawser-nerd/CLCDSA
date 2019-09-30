#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll dp[5010][5010];
ll sz[5010][5010];
int main(){
    int n;
    cin >> n;
    ll A,B;
    cin >> A >> B;
    vector<int>p(n+2);
    vector<int>q(n+2);
    rep(i,n)cin >> p[i+1];
    rep(i,n){
        q[p[i+1]] = i+1;
        sz[i+1][p[i+1]]++;
    }
    for(int j=n-1;j>=1;j--){
        for(int i=1;i<=n;i++){
            sz[i][j] += sz[i][j+1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sz[i][j] += sz[i-1][j];
        }
    }
    // rep(i,n){
    //     rep(j,n){
    //         cerr << sz[i+1][j+1] << " " ;
    //     }
    //     cerr << endl;
    // }
    vector<ll> v(n+1);
    Fill(dp,1LL<<60);
    rep(i,n+3){
        dp[n][i] = 0;
    }
    rep(i,n+3){
        dp[i][n+1] = 0;
        dp[i][n+2] = 0;
    }
    for(int x=n-1;x>=0;x--){
        for(int y=1;y<=n;y++){
            if(q[x+1]<=y){
                dp[x][y] = dp[x+1][y];
            }else{
                ll cnt = sz[q[x+1]-1][x+1]-sz[y-1][x+1];
                // cerr << x << " " << q[x+1] << endl;
                // cerr << x << " " << y << " " <<  cnt << endl;
                // cerr << x+1 << " " << q[x+1]+1 << endl;
                dp[x][y] = min(dp[x+1][y]+B,dp[x+1][q[x+1]+1]+A*cnt);
            }
        }
    }
    // cerr << dp[9][10] << endl;
    // cerr << dp[8][10] << endl;
    // rep(i,n){
    //     rep(j,n){
    //         cerr << i << " " << j+1 << " " <<  dp[i][j+1] << endl;
    //     }

    // }
    cout << dp[0][1] << endl;
    return 0;
}