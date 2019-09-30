#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

void run(void){
  int n;
  scanf("%d",&n);
  int *cnt=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    cnt[a]++;
  }
  const int mod=1000000007;
  int ans=1;
  for(i=n-1;i>0;i-=2){
    if(cnt[i]!=2){
      printf("0\n");
      return;
    }
    ans=ans*2%mod;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^