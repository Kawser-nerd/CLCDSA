#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <complex>
#include <queue>
#include <stack>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define MEMSET(a) memset(a,0,sizeof(a))
#define inf (1ll<<60)
#define Yes(f) cout<<(f?"Yes":"No")<<endl
#define yes(f) cout<<(f?"yes":"no")<<endl
#define YES(f) cout<<(f?"YES":"NO")<<endl

using namespace std;

const int mod=1e9+7;

void run();

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
}

signed main(){
    init();
    run();
    return 0;
}


void run(){
  int n,m,q;
  cin>>n>>m>>q;
  vi l(m),r(m);
  rep(i,m){
    cin>>l[i]>>r[i];
  }
  vvi a(n+1,vi(n+1));
  rep(i,m){
    a[l[i]][r[i]]++;
  }
  rep(i,n+1){
    rep(j,n){
      a[i][j+1]+=a[i][j];
    }
  }
  while(q--){
    int x,y;
    cin>>x>>y;
    int ans=0;
    REP(i,x,y){
      ans+=a[i][y]-a[i][x-1];
    }
    cout<<ans<<endl;
  }
}