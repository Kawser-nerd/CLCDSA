#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long int uint64;
typedef unsigned int uint;

static inline uint64 encode(uint a,uint b,uint c){
  return ((uint64)c<<34)+((uint64)a<<17)+b;
}

#define DECODE(a,b,c,e) do{b=e&131071;a=(e>>17)&131071;c=e>>34;}while(0)

void sort(uint64 *a,uint n){
  uint64 *array=(uint64 *)calloc(8*n,sizeof(uint64));
  for(uint i=34;i<64;i+=3){
    uint len[8]={0};
    for(uint j=0;j<n;j++){
      uint k=(a[j]>>i)&7;
      array[k*n+len[k]++]=a[j];
    }
    uint l=0;
    for(uint j=0;j<8;j++){
      for(uint k=0;k<len[j];k++){
	a[l++]=array[j*n+k];
      }
    }
  }
  free(array);
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
  uint64 *e=(uint64 *)calloc(n+m,sizeof(uint64));
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
  sort(e,n+m);
  uint *u=(uint *)calloc(n+1,sizeof(uint));
  for(i=0;i<=n;i++) u[i]=i;
  uint cnt=0;
  uint64 sum=0;
  for(i=0;cnt<n;i++){
    uint a,b,c;
    DECODE(a,b,c,e[i]);
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
./Main.c:49:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%u%u",&n,&m);
   ^
./Main.c:54:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%u",&c);
     ^
./Main.c:59:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%u%u%u",&a,&b,&r);
     ^