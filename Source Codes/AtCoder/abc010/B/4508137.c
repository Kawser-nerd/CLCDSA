#include<stdio.h>

int main(void){
  int n,i,cnt,ans=0;
  scanf("%d",&n);
  int a[n+1];
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  for(i=1;i<=n;i++){
    cnt=0;
    while(!((a[i]-2)%3!=0 && a[i]%2!=0)){
      a[i]-=1;
      cnt++;
    }
    ans+=cnt;
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