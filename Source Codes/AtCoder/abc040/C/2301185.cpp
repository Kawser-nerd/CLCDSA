#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
 
#define int long long
#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define REV(i,a,n) for(int i=n;i>=a;--i)
#define all(e) e.begin(),e.end()
#define rall(e) e.rbegin(),e.rend()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define show(n) cerr<<#n<<" = "<<n<<endl
#define shows(n) for(auto z:n){cerr<<z<<", ";}cerr<<endl
 
//????AtCoder??define
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
 
using namespace std;
 
//using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pint = pair<int,int>;
 
const int INF = (1 << 30);

const int max_n=100000;
int dp[max_n];
vi height(max_n);
int n;

void solve(){
    REP(i,2,n){
        dp[i]=min(abs(height[i]-height[i-2])+dp[i-2],abs(height[i]-height[i-1])+dp[i-1]);
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,n) cin>>height[i];

    fill(dp, dp+n, INF);
    dp[0]=0;
    dp[1]=abs(height[1]-height[0]);
    solve();

    cout<<dp[n-1]<<endl;

    return 0;
}