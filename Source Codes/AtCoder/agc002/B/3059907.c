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
  int *cnt=(int *)malloc(sizeof(int)*(n+1));
  int *can=(int *)malloc(sizeof(int)*(n+1));
  int i;
  for(i=1;i<=n;i++){
    cnt[i]=1;
    can[i]=0;
  }
  can[1]=1;
  while(m--){
    int x,y;
    scanf("%d%d",&x,&y);
    cnt[x]--;
    cnt[y]++;
    if(can[x]==1) can[y]=1;
    if(cnt[x]==0) can[x]=0;
  }
  int ans=0;
  for(i=1;i<=n;i++) ans+=can[i];
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&x,&y);
     ^