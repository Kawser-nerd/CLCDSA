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
  int p[100001];
  int i;
  for(i=1;i<=n;i++){
    scanf("%d",p+i);
  }
  int cnt=0;
  for(i=1;i<n;i++){
    if(p[i]==i){
      cnt++;
      int s=p[i+1];
      p[i+1]=p[i];
      p[i]=s;
    }
  }
  if(p[n]==n) cnt++;
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
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",p+i);
     ^