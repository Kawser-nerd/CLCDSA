#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j,k) (((i)*5+(j))*2+(k))

int64 calc(int bit,int *f,int *p,int n){
  int ans=0;
  int i,j,k;
  for(i=0;i<n;i++){
    int cnt=0;
    for(j=0;j<5;j++){
      for(k=0;k<2;k++){
	if(f[POS(i,j,k)]==1 && ((bit>>(2*j+k))&0x01)==1) cnt++;
      }
    }
    ans+=p[11*i+cnt];
  }
  return ans;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *f=(int *)malloc(sizeof(int)*n*5*2);
  int i,j,k;
  for(i=0;i<n;i++){
    for(j=0;j<5;j++){
      for(k=0;k<2;k++){
	scanf("%d",f+POS(i,j,k));
      }
    }
  }
  int *p=(int *)malloc(sizeof(int)*n*(10+1));
  for(i=0;i<n;i++){
    for(j=0;j<=10;j++){
      scanf("%d",p+11*i+j);
    }
  }
  int64 max=calc(1,f,p,n);
  for(i=2;i<(1<<10);i++){
    max=MAX(max,calc(i,f,p,n));
  }
  printf("%lld\n",max);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:36:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",f+POS(i,j,k));
  ^
./Main.c:43:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",p+11*i+j);
       ^