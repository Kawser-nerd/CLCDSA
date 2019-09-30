#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

typedef struct weightval{
  int64 v,w;
} node;

int cmp(const void *a,const void *b){
  int64 p=((node *)a)->w;
  int64 q=((node *)b)->w;
  return p==q?0:p<q?-1:1;
}

void solve1(int n,int W,int *v,int *w){
  int alen=n/2;
  int blen=n-alen;
  node *a=(node *)calloc(1<<alen,sizeof(node));
  node *b=(node *)calloc(1<<blen,sizeof(node));
  int i,j;
  for(i=0;i<alen;i++){
    for(j=0;j<(1<<i);j++){
      a[(1<<i)+j]=(node){a[j].v+v[i],a[j].w+w[i]};
    }
  }
  for(i=0;i<blen;i++){
    for(j=0;j<(1<<i);j++){
      b[(1<<i)+j]=(node){b[j].v+v[i+alen],b[j].w+w[i+alen]};
    }
  }
  qsort(a,1<<alen,sizeof(node),cmp);
  qsort(b,1<<blen,sizeof(node),cmp);
  int64 *maxB=(int64 *)calloc(1<<blen,sizeof(int64));
  maxB[0]=b[0].v;
  for(i=1;i<(1<<blen);i++) maxB[i]=MAX(maxB[i-1],b[i].v);
  int64 max=0;
  i=0;
  j=(1<<blen)-1;
  while(i<(1<<alen) && j>=0){
    if(a[i].w+b[j].w<=W){
      if(a[i].v+maxB[j]>max) max=a[i].v+maxB[j];
      i++;
    } else {
      j--;
    }
  }
  printf("%lld\n",max);
  free(a);
  free(b);
  free(maxB);
}

void solve2(int n,int W,int *v,int *w){
  int64 *dp=(int64 *)calloc(n*1000+1,sizeof(int64));
  int64 sum=0;
  int i,j;
  for(i=0;i<n;i++){
    for(j=sum;j>=0;j--){
      dp[j+w[i]]=MAX(dp[j+w[i]],dp[j]+v[i]);
    }
    sum+=w[i];
  }
  int64 max=dp[0];
  for(i=1;i<=W && i<=sum;i++) max=MAX(max,dp[i]);
  printf("%lld\n",max);
  free(dp);
}

void solve3(int n,int W,int *v,int *w){
  int64 *dp=(int64 *)calloc(n*1000+1,sizeof(int64));
  int i,j;
  for(i=1;i<=1000*n;i++) dp[i]=W+1;
  int64 sum=0;
  for(i=0;i<n;i++){
    for(j=sum;j>=0;j--){
      dp[j+v[i]]=MIN(dp[j+v[i]],dp[j]+w[i]);
    }
    sum+=v[i];
  }
  int64 max=0;
  for(i=0;i<=sum;i++) if(dp[i]<=W) max=i;
  printf("%lld\n",max);
  free(dp);
}

void run(void){
  int n,W;
  scanf("%d%d",&n,&W);
  int v[200];
  int w[200];
  int i;
  for(i=0;i<n;i++) scanf("%d%d",v+i,w+i);
  if(n<=30){
    solve1(n,W,v,w);
    return;
  }
  int max=w[0];
  for(i=1;i<n;i++) max=MAX(max,w[i]);
  if(max<=1000){
    solve2(n,W,v,w);
  } else {
    solve3(n,W,v,w);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:92:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&W);
   ^
./Main.c:96:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d%d",v+i,w+i);
                    ^