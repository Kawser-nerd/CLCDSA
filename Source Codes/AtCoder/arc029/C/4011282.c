#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef unsigned long long int uint64;
typedef unsigned int uint;
typedef uint64 edge;

static inline edge encode(uint a,uint b,uint c){
  return ((uint64)c<<34)+((uint64)a<<17)+b;
}

static inline void decode(edge e,uint *a,uint *b,uint *c){
  *b=e&((1<<17)-1);
  e>>=17;
  *a=e&((1<<17)-1);
  e>>=17;
  *c=e;
}

void sort(uint64 *a,uint n){
  if(n<=1) return;
  uint p=rand()%n;
  uint64 pivot=a[p];
  a[p]=a[0];
  uint l=1;
  uint r=n;
  while(l<r){
    if(a[l]<=pivot){
      a[l-1]=a[l];
      l++;
    } else {
      uint64 swap=a[r-1];
      a[r-1]=a[l];
      a[l]=swap;
      r--;
    }
  }
  a[l-1]=pivot;
  sort(a,l-1);
  sort(a+l,n-l);
}

uint root(uint *u,uint x){
  if(u[x]==x) return x;
  return u[x]=root(u,u[x]);
}

int same(uint *u,uint x,uint y){
  return root(u,x)==root(u,y);
}

void unite(uint *u,uint x,uint y){
  x=root(u,x);
  y=root(u,y);
  if(x==y) return;
  u[x]=y;
}

void run(void){
  uint n,m;
  scanf("%u%u",&n,&m);
  edge *e=(edge *)calloc(n+m,sizeof(edge));
  uint i;
  for(i=0;i<n;i++){
    uint c;
    scanf("%u",&c);
    e[i]=encode(0,i+1,c);
  }
  for(i=0;i<m;i++){
    uint a,b,r;
    scanf("%u%u%u",&a,&b,&r);
    e[i+n]=encode(a,b,r);
  }
  srand((unsigned)time(NULL));
  sort(e,n+m);
  uint *u=(uint *)calloc(n+1,sizeof(uint));
  for(i=0;i<=n;i++) u[i]=i;
  uint cnt=0;
  uint64 sum=0;
  for(i=0;cnt<n;i++){
    uint a,b,c;
    decode(e[i],&a,&b,&c);
    if(same(u,a,b)) continue;
    unite(u,a,b);
    sum+=c;
    cnt++;
  }
  printf("%llu\n",sum);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:62:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%u%u",&n,&m);
   ^
./Main.c:67:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%u",&c);
     ^
./Main.c:72:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%u%u%u",&a,&b,&r);
     ^