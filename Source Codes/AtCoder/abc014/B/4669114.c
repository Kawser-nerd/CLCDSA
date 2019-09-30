#include<stdio.h>

int main(void){
  int a,n,x,i,ans=0;
  scanf("%d %d",&n,&x);
  int b[n];
  for(i=0;x!=0;i++){
    b[i]=x%2;
    x/=2;
  }
  for(i=0;i<n;i++){
    scanf("%d",&a);
    if(b[i]==1) ans+=a;
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&x);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^