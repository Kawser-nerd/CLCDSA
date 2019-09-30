// #include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)

#define CHMAX(a,b) a=max((a),(b))

int n,m;
int a[5000];
int b[5000][200];
int mx[200];

int main(){
  scanf("%d%d",&n,&m);
  REP(i,n-1)scanf("%d",a+i);
  REP(i,n)REP(j,m)scanf("%d",&b[i][j]);
  // REP(i,n-1)a[i]=1;
  // REP(i,n)REP(j,m)b[i][j]=1;

  ll ans = 0;
  REP(l,n){
    ll lensum = 0;
    REP(j,m)mx[j]=b[l][j];
    ll ysum = 0;
    REP(j,m)ysum+=mx[j];
    CHMAX(ans,ysum-lensum);

    FOR(r,l+1,n){
      lensum += a[r-1];
      REP(j,m)CHMAX(mx[j],b[r][j]);
      ysum = 0;
      REP(j,m)ysum += mx[j];
      CHMAX(ans,ysum-lensum);
    }

  }
  printf("%lld\n",ans);
  return 0;
}