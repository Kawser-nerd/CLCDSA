#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct item{
  int64 v,w;
} node;

int cmp(const void *a,const void *b){
  node *p=(node *)a;
  node *q=(node *)b;
  if(p->w!=q->w) return p->w<q->w?-1:1;
  return p->v>q->v?-1:1;
}

node* enumerate(node *a,int n){
  node *p=(node *)calloc(1<<n,sizeof(node));
  int i,j;
  for(i=0;i<n;i++){
    for(j=0;j<(1<<i);j++){
      p[j+(1<<i)]=(node){p[j].v+a[i].v,p[j].w+a[i].w};
    }
  }
  qsort(p,1<<n,sizeof(node),cmp);
  for(i=1;i<(1<<n);i++) p[i].v=MAX(p[i].v,p[i-1].v);
  return p;
}

void run(void){
  int n,w;
  scanf("%d%d",&n,&w);
  node *p=(node *)calloc(n,sizeof(node));
  int maxV=0;
  int maxW=0;
  int i;
  for(i=0;i<n;i++){
    scanf("%lld%lld",&p[i].v,&p[i].w);
    maxV=MAX(maxV,p[i].v);
    maxW=MAX(maxW,p[i].w);
  }
  int64 ans=0;
  if(n<=30){
    int m=n/2;
    node *a=enumerate(p,m);
    node *b=enumerate(p+m,n-m);
    i=0;
    int j=(1<<(n-m))-1;
    while(i<(1<<m) && j>=0){
      if(a[i].w+b[j].w<=w){
	ans=MAX(ans,a[i].v+b[j].v);
	i++;
      } else {
	j--;
      }
    }
  } else if(maxW<=1000){
    int m=maxW*n;
    int64 *dp=(int64 *)calloc(m+1,sizeof(int64));
    for(i=0;i<n;i++){
      for(int j=m;j>=p[i].w;j--){
	dp[j]=MAX(dp[j],dp[j-p[i].w]+p[i].v);
      }
    }
    ans=dp[MIN(w,m)];
  } else {
    int m=maxV*n;
    int64 *dp=(int64 *)calloc(m+1,sizeof(int64));
    for(i=1;i<=m;i++) dp[i]=w+1;
    for(i=0;i<n;i++){
      for(int j=m;j>=p[i].v;j--){
	dp[j]=MIN(dp[j],dp[j-p[i].v]+p[i].w);
      }
    }
    for(i=m;dp[i]>w;i--);
    ans=i;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&w);
   ^
./Main.c:43:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&p[i].v,&p[i].w);
     ^