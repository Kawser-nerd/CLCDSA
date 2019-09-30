#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *cnt=(int *)calloc(n+1,sizeof(int));
  int i;
  for(i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    cnt[a]++;
    cnt[b]++;
  }
  for(i=1;i<=n;i++){
    if(cnt[i]%2!=0){
      printf("NO\n");
      return;
    }
  }
  printf("YES\n");
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^