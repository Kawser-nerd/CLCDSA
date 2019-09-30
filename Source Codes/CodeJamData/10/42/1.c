#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define INF 1000000000

int p, n, node;

int need[2000], mx[2000];
int dp[2000][40];
int place[2000];

void get_mx(int now, int a, int b){
  int i,sz;
  mx[now] = INF;

  REP(i,a,b+1) if(mx[now] > need[i]) mx[now] = need[i];

  sz = b-a+1;
  if(sz==1) return; sz /= 2;
  get_mx(now*2+1, a, b-sz);
  get_mx(now*2+2, a+sz, b);
}

int solve(int now, int used){
  int i,j,k,res=INF,tmp;

  if(dp[now][used] >= 0) return dp[now][used];

  if(now * 2 + 2 > node){
    if(used <= mx[now]) res = place[now];
    if(used+1 <= mx[now]) res = 0;
  } else {
    tmp = solve(now*2+1, used) + solve(now*2+2, used) + place[now];
    if(tmp < res) res = tmp;
    tmp = solve(now*2+1, used+1) + solve(now*2+2, used+1);
    if(tmp < res) res = tmp;
  }

  return dp[now][used] = res;
}

int main(){
  int i,j,k,l,m,res;
  int st, ed;
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    scanf("%d",&p);
    n = (1<<p); node = (1<<p)-1;

    rep(i,n) scanf("%d",need+i);
    rep(i,p){
      st = (1<<(p-i-1))-1; ed = (1<<(p-i))-1;
      REP(j,st,ed) scanf("%d",place+j);
    }
    

    get_mx(0,0,n-1);
    rep(i,node) rep(j,p+2) dp[i][j]=-1;
    res = solve(0,0);

    printf("Case #%d: %d\n",++count,res);
  }

  return 0;
}
