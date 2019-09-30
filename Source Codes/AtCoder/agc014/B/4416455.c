#include<stdio.h>
#include<stdlib.h>

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *cnt=(int *)calloc(n+1,sizeof(int));
  while(m--){
    int a,b;
    scanf("%d%d",&a,&b);
    cnt[a]++;
    cnt[b]++;
  }
  int i;
  for(i=1;i<=n;i++) if(cnt[i]&1) break;
  puts(i>n?"YES":"NO");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^