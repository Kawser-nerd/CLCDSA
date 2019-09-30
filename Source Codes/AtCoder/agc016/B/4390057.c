#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int calc(void){
  int n;
  scanf("%d",&n);
  int *cnt=(int *)calloc(n,sizeof(int));
  int kind=0;
  int min=n;
  int i;
  for(i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    if(cnt[a]==0) kind++;
    cnt[a]++;
    min=MIN(min,a);
  }
  if(kind>2) return 0;
  if(kind==1){
    return min==n-1 || 2*min<=n;
  }
  if(cnt[min]+cnt[min+1]<n) return 0;
  int one=cnt[min];
  int two=cnt[min+1];
  if(min+1<one+1 || two<2 || min+1>one+two/2) return 0;
  return 1;
}

void run(void){
  puts(calc()?"Yes":"No");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘calc’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^