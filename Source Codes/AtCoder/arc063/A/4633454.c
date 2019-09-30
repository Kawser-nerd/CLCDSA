#include <stdio.h>

int main(){
  char c1 = getchar();
  int ans = 0;
  while(1){
    char c2 = getchar();
    if (c2 == 'B' || c2 == 'W'){
      if(c1 != c2){
        ans++;
      }
    }else{
      break;
    }
    c1 = c2;
  }
  printf("%d\n", ans);
  return 0;
}