#include<stdio.h>

int main(void){
  int ans,n,i,a,cnt=0,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    if(a!=0){
      sum+=a;
      cnt++;
    }
  }
  if(sum%cnt!=0) ans=sum/cnt+1;
  else ans=sum/cnt;
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^