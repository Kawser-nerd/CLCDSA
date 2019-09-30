#include<stdio.h>
#define SIZE 10000
int main(){
  int n,a[SIZE],i,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    sum=sum+a[i]-1;
  }
  printf("%d\n",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^