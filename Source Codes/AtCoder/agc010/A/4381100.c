#include<stdio.h>
int main(){
  int n,a,b=0,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    b+=a%2;
  }
  puts(b%2?"NO":"YES");
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^