#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,l;
  scanf("%d%d",&n,&l);
  int *a=(int *)malloc(sizeof(int)*(n+1));
  int i;
  for(i=1;i<=n;i++) scanf("%d",a+i);
  for(i=1;i+1<=n;i++) if(a[i]+a[i+1]>=l) break;
  if(i+1<=n){
    printf("Possible\n");
    int j;
    for(j=1;j<i;j++) printf("%d\n",j);
    for(j=n-1;j>=i+1;j--) printf("%d\n",j);
    printf("%d\n",i);
  } else {
    printf("Impossible\n");
  }
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&l);
   ^
./Main.c:16:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%d",a+i);
                     ^