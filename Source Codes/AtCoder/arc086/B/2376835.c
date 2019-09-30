#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n;
  scanf("%d",&n);
  int a[51];
  int i;
  for(i=1;i<=n;i++) scanf("%d",a+i);
  int min=a[1];
  int max=a[1];
  for(i=2;i<=n;i++){
    min=MIN(min,a[i]);
    max=MAX(max,a[i]);
  }
  if(min>=0){
    printf("%d\n",n-1);
    for(i=1;i+1<=n;i++){
      printf("%d %d\n",i,i+1);
    }
    return;
  } else if(max<=0){
    printf("%d\n",n-1);
    for(i=n;i-1>=1;i--){
      printf("%d %d\n",i,i-1);
    }
    return;
  }
  if(ABS(max)>=ABS(min)){
    printf("%d\n",n-1+n-1);
    for(i=1;a[i]!=max;i++);
    int j;
    for(j=1;j<=n;j++){
      if(j==i) continue;
      printf("%d %d\n",i,j);
    }
    for(i=1;i+1<=n;i++){
      printf("%d %d\n",i,i+1);
    }
  } else {
    printf("%d\n",n-1+n-1);
    for(i=1;a[i]!=min;i++);
    int j;
    for(j=1;j<=n;j++){
      if(j==i) continue;
      printf("%d %d\n",i,j);
    }
    for(i=n;i-1>=1;i--){
      printf("%d %d\n",i,i-1);
    }
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:16:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%d",a+i);
                     ^