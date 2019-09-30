#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
  return a<b?a:b;
}

typedef struct RMQ{
  int *a;
  int size;
} segTree;

segTree* newRMQ(const int n){
  int k=1;
  while(k<n) k*=2;
  segTree *s=(segTree *)malloc(sizeof(segTree));
  s->a=(int *)calloc(2*k,sizeof(int));
  s->size=k;
  for(int i=1;i<2*k;i++) s->a[i]=2147483647;
  return s;
}

void update(segTree *s,int x,int v){
  int *a=s->a;
  x+=s->size;
  a[x]=v;
  x/=2;
  while(x>=1){
    a[x]=min(a[2*x],a[2*x+1]);
    x/=2;
  }
}

int find(segTree *s,int l,int r){
  int res=2147483647;
  for(l+=s->size,r+=s->size;l<r;l>>=1,r>>=1){
    if(l&1) res=min(res,s->a[l++]);
    if(r&1) res=min(res,s->a[--r]);
  }
  return res;
}

typedef long long int int64;

void run(void){
  int n,x;
  scanf("%d%d",&n,&x);
  int *a=(int *)calloc(n,sizeof(int));
  int i,j;
  for(i=0;i<n;i++) scanf("%d",a+i);
  segTree *s=newRMQ(2*n);
  for(i=0;i<n;i++){
    update(s,i,a[i]);
    update(s,i+n,a[i]);
  }
  int64 ans=1000000000LL*n;
  for(i=0;i<n;i++){
    int64 sum=(int64)x*i;
    for(j=0;j<n;j++){
      sum+=find(s,j+n-i,j+n+1);
    }
    if(ans>sum) ans=sum;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:50:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^