#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp(const void *a,const void *b){
  return *(int *)a - *(int *)b;
}

void run(void){
  int n;
  scanf("%d",&n);
  int a[100000];
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  qsort(a,n,sizeof(int),cmp);

  int x,y;
  x=y=0;
  for(i=n-1;i-1>=0;i--){
    if(a[i]==a[i-1]){
      x=a[i];
      break;
    }
  }
  for(i=i-2;i-1>=0;i--){
    if(a[i]==a[i-1]){
      y=a[i];
      break;
    }
  }
  printf("%lld\n",(int64)x*y);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:20:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^