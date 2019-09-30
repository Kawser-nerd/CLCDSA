#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

const int mod=1000000007;

void add(int u,int v,int d,int *vertex,int *cost,int *next,int *start,int index){
  vertex[index]=v;
  cost[index]=d;
  next[index]=start[u];
  start[u]=index;
  return;
}

typedef struct heapnode{
  int64 d;
  int index;
} node;

int cmp(node *a,node *b){
  return a->d<=b->d;
}

void swap(node *a,node *b){
  node t=*a;
  *a=*b;
  *b=t;
  return;
}

node *heap=NULL;
int heapSize=0;

void push(int64 v,int index){
  int k=++heapSize;
  heap[k].d=v;
  heap[k].index=index;
  while(k>1){
    if(cmp(heap+k/2,heap+k)) return;
    swap(heap+k/2,heap+k);
    k/=2;
  }
}

void pop(node *res){
  *res=heap[1];
  heap[1]=heap[heapSize--];
  int k=1;
  while(2*k+1<=heapSize){
    int next=cmp(heap+2*k,heap+2*k+1)?2*k:2*k+1;
    if(cmp(heap+k,heap+next)) return;
    swap(heap+k,heap+next);
    k=next;
  }
  if(2*k<=heapSize && cmp(heap+2*k,heap+k)) swap(heap+2*k,heap+k);
}

void dijkstra(int from,int64 *dp,int *cnt,int n,int *vertex,int *cost,int *next,int *start){
  heapSize=0;
  int64 inf=1000000000LL*100001;
  int i;
  for(i=0;i<n;i++){
    dp[i]=inf;
    cnt[i]=0;
  }
  dp[from]=0;
  cnt[from]=1;
  push(0,from);
  while(heapSize>0){
    node t;
    pop(&t);
    int v=t.index;
    int64 d=t.d;
    if(d>dp[v]) continue;
    int p;
    for(p=start[v];p!=-1;p=next[p]){
      int u=vertex[p];
      if(dp[u]>dp[v]+cost[p]){
	dp[u]=dp[v]+cost[p];
	cnt[u]=cnt[v];
	push(dp[u],u);
      } else if(dp[u]==dp[v]+cost[p]){
	cnt[u]=(cnt[u]+cnt[v])%mod;
      }
    }
  }
  return;
}

void run(void){
  int n,m,s,t;
  scanf("%d%d%d%d",&n,&m,&s,&t);
  s--;
  t--;
  int *vertex=(int *)malloc(sizeof(int)*2*m);
  int *cost=(int *)malloc(sizeof(int)*2*m);
  int *next=(int *)malloc(sizeof(int)*2*m);
  int *start=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) start[i]=-1;
  for(i=0;i<m;i++){
    int u,v,d;
    scanf("%d%d%d",&u,&v,&d);
    u--;
    v--;
    add(u,v,d,vertex,cost,next,start,2*i);
    add(v,u,d,vertex,cost,next,start,2*i+1);
  }
  heap=(node *)malloc(sizeof(node)*(m+1));
  int64 *fromS=(int64 *)malloc(sizeof(int64)*n);
  int *cntS=(int *)malloc(sizeof(int)*n);
  dijkstra(s,fromS,cntS,n,vertex,cost,next,start);
  int64 *fromT=(int64 *)malloc(sizeof(int64)*n);
  int *cntT=(int *)malloc(sizeof(int)*n);
  dijkstra(t,fromT,cntT,n,vertex,cost,next,start);
  int64 min=fromS[t];
  int64 ans=(int64)cntS[t]*cntT[s]%mod;
  for(i=0;i<n;i++){
    if(fromS[i]==fromT[i] && fromS[i]+fromT[i]==min){
      ans=(ans-(int64)cntS[i]*cntS[i]%mod*cntT[i]%mod*cntT[i]%mod+mod)%mod;
    }
  }
  for(i=0;i<n;i++){
    int u=i;
    int p;
    for(p=start[u];p!=-1;p=next[p]){
      int v=vertex[p];
      if(fromS[v]==fromS[u]+cost[p] && fromS[v]+fromT[v]==min && MAX(fromS[u],fromT[v])<MIN(fromS[v],fromT[u])){
	ans=(ans-(int64)cntS[u]*cntS[u]%mod*cntT[v]%mod*cntT[v]%mod+mod)%mod;
      }
    }
  }
  printf("%lld\n",ans);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:98:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&n,&m,&s,&t);
   ^
./Main.c:109:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&u,&v,&d);
     ^