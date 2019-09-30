#include<stdio.h>

int main(void){
  int n,i,ans=0;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    ans += a[i]-1;
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^