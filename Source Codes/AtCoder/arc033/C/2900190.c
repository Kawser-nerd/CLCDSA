#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void add(int *b,int index,int x){
  int i;
  for(i=index;i<=b[0];i+=i&-i) b[i]+=x;
  return;
}

int sum(int *b,int index){
  int res=0;
  int i;
  for(i=index;i>0;i-=i&-i) res+=b[i];
  return res;
}

int calc(int *b,int x){
  int l=0;
  int r=b[0];
  while(r-l>1){
    int m=(l+r)/2;
    if(sum(b,m)>=x){
      r=m;
    } else {
      l=m;
    }
  }
  add(b,r,-1);
  return r;
}

void run(void){
  const int n=200000;
  int *b=(int *)calloc(n+1,sizeof(int));
  b[0]=n;
  int q;
  scanf("%d",&q);
  while(q--){
    int t,x;
    scanf("%d%d",&t,&x);
    if(t==1){
      add(b,x,1);
    } else {
      printf("%d\n",calc(b,x));
    }
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:44:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:47:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&t,&x);
     ^