#include <stdio.h>
int MIN(int a,int b){
    return a<b?a:b;
}
int main(){
  int n,x;
  scanf("%d%d",&n,&x);
  printf("%d",MIN(n-x,x-1));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^