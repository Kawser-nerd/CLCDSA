#include <stdio.h>

int main(){
  int state = 0;
  while(1){
    char c = getchar();
    if (c == '\0' || c == '\n'){
      break;
    }
    if(state==0){
      if(c == 'A'){
        state = 1;
      }else{
        state = 5;
      }
    }else if (state == 1){
      if (c >= 'a' && c <= 'z'){
        state = 2;
      }else{
        state = 5;
      }
    }else if (state == 2){
      if (c >= 'a' && c <= 'z'){
        continue;
      }else if(c == 'C'){
        state = 3;
      }else{
        state = 5;
      }
    }else if (state == 3){
      if (c >= 'a' && c <= 'z'){
        state = 4;
      }else{
        state = 5;
      }
    }else if (state == 4){
      if (c >= 'a' && c <= 'z'){
        continue;
      }else{
        state = 5;
      }
    }
  }
  if (state == 4){
    puts("AC");
  }else{
    puts("WA");
  }
  return 0;
}