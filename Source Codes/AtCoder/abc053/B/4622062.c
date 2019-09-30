#include <stdio.h>

int main(){
  int ans = 0;
  int count = 0;
  int flag = 0;
  while(1){
    char c = getchar();
    if(c == EOF){
      break;
    }else if(flag == 0 && c == 'A'){
      count++;
      flag = 1;
    }else if(flag == 1){
      count++;
      if(c == 'Z'){
        ans = count;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}