#include<stdio.h>
int main(){
  int n,a,b,c=0;
  scanf("%d",&n);
  while(n--){
    scanf("%d %d",&a,&b);
    c+=a*b;
  }
  c*=1.05;
  printf("%d\n",c);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&a,&b);
     ^