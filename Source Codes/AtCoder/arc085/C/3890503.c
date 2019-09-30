#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

const int f=102;
#define POS(i,j) ((i)*f+(j))

int dfs(int v,int64 *g,int *array,int *used){
  used[v]=1;
  array[0]=v;
  if(v==f-1) return 1;
  int i;
  for(i=0;i<f;i++){
    if(!used[i] && g[POS(v,i)]>0){
      int c=dfs(i,g,array+1,used);
      if(c>0) return c+1;
    }
  }
  return 0;
}

int64 calc(int *a,int n){
  int64 *g=(int64 *)calloc(f*f,sizeof(int64));
  int i,j;
  for(i=1;i<=n;i++){
    if(a[i]>=0){
      g[POS(i,f-1)]=a[i];
    } else {
      g[POS(0,i)]=-a[i];
    }
  }
  for(i=1;i<=n;i++){
    for(j=2*i;j<=n;j+=i){
      g[POS(i,j)]=1000000000LL*1000;
    }
  }
  int array[128];
  int used[128]={0};
  int64 ans=0;
  int64 len=dfs(0,g,array,used);
  while(len){
    int64 min=1000000000LL*1000;
    for(i=0;i+1<len;i++){
      int64 t=g[POS(array[i],array[i+1])];
      if(min>t) min=t;
    }
    ans+=min;
    for(i=0;i+1<len;i++){
      int v=array[i];
      int u=array[i+1];
      g[POS(v,u)]-=min;
      g[POS(u,v)]+=min;
    }
    for(i=0;i<f;i++) used[i]=0;
    len=dfs(0,g,array,used);
  }
  free(g);
  return ans;
}

void run(void){
  int n;
  scanf("%d",&n);
  int i;
  int a[101];
  for(i=1;i<=n;i++) scanf("%d",a+i);
  int64 sum=0;
  for(i=1;i<=n;i++) if(a[i]>=0) sum+=a[i];
  int64 ans=sum-calc(a,n);
  printf("%lld\n",ans);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:64:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:67:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%d",a+i);
                     ^