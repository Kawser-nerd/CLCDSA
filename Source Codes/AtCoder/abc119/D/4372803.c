#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int search(int64 *a,int n,int64 v){
  int l=0;
  int r=n;
  while(r-l>1){
    int m=(l+r)/2;
    if(a[m]<=v){
      l=m;
    } else {
      r=m;
    }
  }
  return l;
}

void run(void){
  int a,b,q;
  scanf("%d%d%d",&a,&b,&q);
  int64 *s=(int64 *)calloc(a+2,sizeof(int64));
  int64 *t=(int64 *)calloc(b+2,sizeof(int64));
  int i;
  for(i=1;i<=a;i++) scanf("%lld",s+i);
  for(i=1;i<=b;i++) scanf("%lld",t+i);
  s[0]=t[0]=-2000000000000LL;
  s[a+1]=t[b+1]=200000000000LL;
  while(q--){
    int64 x;
    scanf("%lld",&x);
    int l=search(s,a+2,x);
    int r=search(t,b+2,x);
    int64 p[2]={s[l],s[l+1]};
    int64 q[2]={t[r],t[r+1]};
    int64 min=1000000000000000LL;
    for(int i=0;i<2;i++){
      for(int j=0;j<2;j++){
	min=MIN(min,ABS(x-p[i])+ABS(p[i]-q[j]));
	min=MIN(min,ABS(x-q[j])+ABS(p[i]-q[j]));
      }
    }
    printf("%lld\n",min);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&q);
   ^
./Main.c:31:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=a;i++) scanf("%lld",s+i);
                     ^
./Main.c:32:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=b;i++) scanf("%lld",t+i);
                     ^
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&x);
     ^