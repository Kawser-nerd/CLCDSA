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

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define mod 1000000007
ll dp[10010];
ll dp2[10010];
int main(){
    int n,k;
    cin >> n >> k;
    vector<int>a;
    ll sm = 0;
    rep(i,n){
        int tmp;
        cin >> tmp;
        if(tmp<k){
            a.PB(tmp);
        }
        sm += (ll)tmp;
    }
    if(sm<k){
        cout << n << endl;
        return 0;
    }
    n = a.size();
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2*k;j++){
            dp2[j] = dp[j];
            dp[j] = 0;
        }
        for(int j=0;j<=2*k;j++){
            dp[j] += dp2[j];
            dp[j] %= mod;
            dp[j+a[i-1]] += dp2[j];
            dp[j+a[i-1]] %= mod;
        }
    }
    for(int i=0;i<=2*k;i++){
        dp2[i] = 0;
    }
    ll s= 0;
    for(int i=k;i<=2*k;i++){
        s += dp[i];
        s %= mod;
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=2*k;j++){
            if(j<a[i-1]){
                dp2[j] = dp[j];
            }else{
                dp2[j] = (mod+dp[j]-dp2[j-a[i-1]])%mod;
            }
        }
        ll ss = 0;
        for(int j=k;j<=2*k;j++){
            //cerr << dp2[i][j] << " ";
            ss += dp2[j];
            ss %= mod;
        }
        if(s==(ss*2%mod)){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}