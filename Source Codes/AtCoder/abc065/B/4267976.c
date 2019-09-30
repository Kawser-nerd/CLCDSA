#include <stdio.h>
int main(void){
  int n,i,a[100000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int count=1,j,k=0;
  for(i=0;i<=n;i++){
    j=a[k];
    if(j==2) {printf("%d",count);return 0;}
    k=j-1;
    count++;
  }
  printf("-1");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^