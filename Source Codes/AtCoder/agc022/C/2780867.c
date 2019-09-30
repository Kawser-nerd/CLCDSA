#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cond(int *k,int n,int *a,int *b){
  int t[51];
  int i;
  for(i=0;i<n;i++){
    int aa=a[i];
    int bb=b[i];
    int j;
    for(j=0;j<51;j++) t[j]=0;
    t[aa]=1;
    for(j=50;j>0;j--){
      int kk=k[j];
      if(kk==-1) continue;
      int l;
      for(l=0;l<=aa;l++){
	if(t[l]==1){
	  t[l%kk]=1;
	}
      }
    }
    if(t[bb]==0) return 0;
  }
  return 1;
}

void run(void){
  int n;
  scanf("%d",&n);
  int a[50],b[50];
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  for(i=0;i<n;i++) scanf("%d",b+i);
  int k[51];
  for(i=1;i<=50;i++) k[i]=i;
  k[0]=-1;
  if(!cond(k,n,a,b)){
    printf("-1\n");
    return;
  }
  for(i=50;i>0;i--){
    k[i]=-1;
    if(!cond(k,n,a,b)) k[i]=i;
  }
  int64 cost=0;
  for(i=0;i<=50;i++) cost+=(k[i]>=0?1:0)*(1LL<<i);
  printf("%lld\n",cost);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:40:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^
./Main.c:41:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",b+i);
                    ^