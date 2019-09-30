#include<stdio.h>

int main(void){
  int n,i,x,ans=0;
  scanf("%d",&n);
  int a[100001];
  for(i=0;i<100001;i++) a[i]=0;
  for(i=0;i<n;i++){
    scanf("%d",&x);
    if(a[x]++) ans++;
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^