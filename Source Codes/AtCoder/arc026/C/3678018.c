#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

typedef struct RMQ{
  int64 *a;
  int size;
} seg;

seg* newRMQ(const int n){
  int k=1;
  while(k<n) k*=2;
  seg *s=(seg *)malloc(sizeof(seg));
  s->a=(int64 *)calloc(2*k,sizeof(int64));
  s->size=k;
  int i;
  for(i=1;i<2*k;i++) s->a[i]=10000000000LL+1;
  return s;
}

int64 min(int64 a,int64 b){
  return a<b?a:b;
}

void update(seg *s,int x,int64 v){
  x+=s->size;
  int64 *a=s->a;
  a[x]=v;
  x/=2;
  while(x>=1){
    a[x]=min(a[2*x],a[2*x+1]);
    x/=2;
  }
}

int64 find(seg *s,int l,int r){
  int64 res=10000000000LL+1;
  for(l+=s->size,r+=s->size;l<r;l>>=1,r>>=1){
    if(l&1) res=min(res,s->a[l++]);
    if(r&1) res=min(res,s->a[--r]);
  }
  return res;
}

typedef struct keikoutou{
  int l,r,c;
} range;

int cmp(const void *a,const void *b){
  return ((range *)a)->l-((range *)b)->l;
}

void run(void){
  int n,len;
  scanf("%d%d",&n,&len);
  range *a=(range *)calloc(n,sizeof(range));
  int i;
  for(i=0;i<n;i++){
    int l,r,c;
    scanf("%d%d%d",&l,&r,&c);
    a[i]=(range){l,r,c};
  }
  qsort(a,n,sizeof(range),cmp);
  seg *s=newRMQ(len+1);
  update(s,0,0);
  for(i=0;i<n;i++){
    int64 d=find(s,a[i].l,a[i].r+1)+a[i].c;
    if(find(s,a[i].r,a[i].r+1)>d) update(s,a[i].r,d);
  }
  printf("%lld\n",find(s,len,len+1));
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:56:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&len);
   ^
./Main.c:61:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&l,&r,&c);
     ^