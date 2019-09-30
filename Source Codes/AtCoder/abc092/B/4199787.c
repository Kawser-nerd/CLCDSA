#include<stdio.h>

int main(void){
  int n,d,x,i,j,ans=0;
  scanf("%d",&n);
  scanf("%d %d",&d,&x);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    for(j=0;(j*a[i]+1)<=d;j++){
      //printf("%d\n",j*a[i]+1);
      ans++;
    }
  }
  printf("%d\n",ans+x);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&d,&x);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^