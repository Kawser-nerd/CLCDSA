#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  const int n=100000;
  int *a=(int *)malloc(sizeof(int)*(n+1));
  int i,j;
  for(i=0;i<=n;i++) a[i]=1;
  a[0]=a[1]=0;
  for(i=2;i*i<=n;i++){
    if(a[i]){
      for(j=i*i;j<=n;j+=i){
	a[j]=0;
      }
    }
  }
  int *b=(int *)malloc(sizeof(int)*(n+1));
  for(i=0;i<=n;i++) b[i]=0;
  for(i=3;i<=n;i+=2){
    if(a[i] && a[(i+1)/2]){
      b[i]=1;
    }
  }
  for(i=1;i<=n;i++){
    b[i]+=b[i-1];
  }
  int q;
  scanf("%d",&q);
  for(i=0;i<q;i++){
    int l,r;
    scanf("%d%d",&l,&r);
    printf("%d\n",b[r]-b[l-1]);
  }
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&l,&r);
     ^