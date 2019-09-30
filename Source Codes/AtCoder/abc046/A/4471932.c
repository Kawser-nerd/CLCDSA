#include <stdio.h>
#include <string.h>
int main(){
  int a, b, c;
  int ans = 3;

  scanf("%d%d%d", &a, &b, &c);

  if(a == b && b == c){
    ans = 1;
  }else{
    if(a == b){
      ans--;
    }else if(b == c){
      ans--;
    }
    if(a == c){
      ans--;
    }
  }
  printf("%d\n", ans);
  
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &a, &b, &c);
   ^