#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define MAX_N 100
#define MAX_A 100
#define MAX_B 10

int N, A, B;
int X[MAX_N], Y[MAX_N];
int U[MAX_N], V[MAX_N];
vector<int> e[MAX_N];
int ein[MAX_N];
bool eis[MAX_N];

int cal(int st){
  queue<int> Q;
  int ret=0;
  rep(i, N){
    e[i].clear();
    ein[i] = 0;
    eis[i] = false;
  }
  
  
  rep(i, A){
    e[Y[i]-1].pb(X[i]-1);
    ein[X[i]-1]++;
  }

  rep(i, B){
    if(st & (1<<i)){
      eis[U[i]-1]=true;
    }else{
      e[U[i]-1].pb(V[i]-1);
      ein[V[i]-1]++;
    }
  }

  rep(i, N){
    if(ein[i]==0 && !eis[i])Q.push(i);
  }
  while(!Q.empty()){
    int v = Q.front(); Q.pop();
    ret++;
    rep(i, e[v].size()){
      ein[e[v][i]]--;
      if(ein[e[v][i]]==0 && !eis[e[v][i]])Q.push(e[v][i]);
    }
  }  
  return ret;
}

int solve(){
  int ans = 0;
  for(int i=0; i<(1<<B); i++){
    ans = max(ans, cal(i));
  }
  return ans;
}

int main(){
  scanf("%d", &N);
  scanf("%d", &A);
  rep(i, A)scanf("%d %d", X+i, Y+i);
  scanf("%d", &B);
  rep(i, B)scanf("%d %d", U+i, V+i);
  printf("%d\n", solve());
  return 0;
}