#include<stdio.h>
int main(){
  int n,a,min=1000,max=0;
  scanf("%d",&n);
  while(n--){
    scanf("%d",&a);
    if(a<min) min=a;
    if(a>max) max=a;
  }
  printf("%d",max-min);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^