#include<stdio.h>
int n[3], ans;
int main(){
  scanf("%d%d%d", n, n+1, n+2);
  if(n[0] == n[1]){
    ans = n[2];
  }else if(n[0] == n[2]){
    ans = n[1];
  }else{
    ans = n[0];
  }
  printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", n, n+1, n+2);
   ^