#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define INF 1000000

int n,n1,n2;
int target;
int type[20000], change[20000]; /* type=1 and, type=0 or */
int value[20000];
int opt0[20000],opt1[20000];

void solve(int node){
  int i,j,k;
  int tmp0,tmp1;

  if(opt0[node]>=0) return;

  if(node>=n1){
    if(value[node]==0){opt0[node]=0; opt1[node]=INF;}
    else              {opt0[node]=INF; opt1[node]=0;}
    return;
  }

  opt0[node]=opt1[node]=INF;
  solve(node*2+1); solve(node*2+2);

  tmp0 = opt0[node*2+1] + opt0[node*2+2];
  if(opt0[node] > tmp0) opt0[node]=tmp0;

  tmp1 = opt1[node*2+1] + opt1[node*2+2];
  if(opt1[node] > tmp1) opt1[node]=tmp1;

  tmp0 = opt0[node*2+1] + opt1[node*2+2];
  tmp1 = opt1[node*2+1] + opt0[node*2+2];
  if(tmp0 > tmp1) tmp0 = tmp1; tmp1=tmp0;

  if(type[node]==0) if(opt1[node] > tmp0) opt1[node]=tmp0;
  if(type[node]==1) if(opt0[node] > tmp0) opt0[node]=tmp0;
  
  if(change[node]){
    if(opt0[node] > tmp0+1) opt0[node]=tmp0+1;
    if(opt1[node] > tmp0+1) opt1[node]=tmp0+1;
  }
}

int main(){
  int i,j,k,l,m;
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    scanf("%d%d",&n,&target);
    n1=(n-1)/2; n2=(n+1)/2;

    rep(i,n1){
      scanf("%d%d",&j,&k);
      type[i]=j; change[i]=k;
    }
    REP(i,n1,n){
      scanf("%d",&j);
      value[i]=j;
    }

    rep(i,n) opt0[i]=opt1[i]=-1;
    
    solve(0);

    printf("Case #%d: ",++count);

    if(target==0) m=opt0[0]; else m=opt1[0];
    if(m>=INF) puts("IMPOSSIBLE");
    else printf("%d\n",m);
    
  }

  return 0;
}
