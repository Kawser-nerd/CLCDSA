#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long>>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int t[SIZE],v[SIZE],a[SIZE],m;
template <class T>
void maa(T& x,T y){
  if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
  if(x>y)x=y;
}
int main(){
  DRI(N);
  REP(i,N){
    RI(t[i]);
    t[i]*=2;
  }
  REP(i,N){
    RI(v[i]);
    v[i]*=2;
  }
  REP(i,SIZE)a[i]=MOD;
  int it=0;
  a[0]=0;
  REP(i,N){
    mii(a[it],v[i]);
    REP(j,t[i]){
      it++;
      mii(a[it],v[i]);
    }
//    cout<<i<<","<<it<<endl;
  }
//  cout<<it<<endl;
  mii(a[it],0);
  REPP(i,1,it+1) {
//    if(i==140)cout<<a[i]<<","<<a[i-1]+1<<endl;
    mii(a[i],a[i-1]+1);
  }
  for(int i=it-1;i>=0;i--) {
//    if(i==140)cout<<a[i]<<","<<a[i+1]+1<<endl;
    mii(a[i],a[i+1]+1);
  }
  
//  REPP(i,0,it+1) cout<<i<<","<<a[i]<<endl;
  
  LL an=0;
  REP(i,it){
    an+=(a[i]+a[i+1]);
  }
  printf("%.12f\n",an*0.125);
  return 0;
}