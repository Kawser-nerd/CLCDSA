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
  int *c=(int *)calloc(n+1,sizeof(int));
  int i;
  int cnt=0;
  for(i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    if(a<=n){
      c[a]++;
    } else {
      cnt++;
    }
  }
  for(i=1;i<=n;i++){
    if(c[i]!=i){
      cnt+=(c[i]>i?c[i]-i:c[i]);
    }
  }
  printf("%d\n",cnt);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^