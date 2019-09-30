#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,D;
  scanf("%d%d",&n,&D);
  int *d=(int *)malloc(sizeof(int)*(n+1));
  int i;
  for(i=1;i<=n;i++) scanf("%d",d+i);
  int *now=(int *)malloc(sizeof(int)*(n+1));
  now[0]=D;
  for(i=1;i<=n;i++) now[i]=MIN(now[i-1],ABS(now[i-1]-d[i]));
  int *can=(int *)malloc(sizeof(int)*(n+1));
  int64 min=0;
  for(i=n;i>=1;i--){
    can[i]=!(now[i-1]<=min);
    if(d[i]<=2*min+1){
      min+=d[i];
    }
  }
  int q;
  scanf("%d",&q);
  while(q--){
    int x;
    scanf("%d",&x);
    printf("%s\n",can[x]?"YES":"NO");
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&D);
   ^
./Main.c:16:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%d",d+i);
                     ^
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:32:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^