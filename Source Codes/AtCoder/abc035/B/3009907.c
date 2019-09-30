#include <stdio.h>
#include <stdlib.h>

int main(void){
  char s[100001];
  int t;
  scanf("%s %d", s, &t);
  int i;
  int x = 0;
  int y = 0;
  int count = 0;
  while(s[i] != '\0'){
    if(s[i] == 'L'){
      x++;
    }else if(s[i] == 'R'){
      x--;
    }else if(s[i] == 'U'){
      y++;
    }else if(s[i] == 'D'){
      y--;
    }else{
      count++;
    }
    i++;
  }
  if(t == 1){
    printf("%d\n", abs(x) + abs(y) + count);
  }else{
    if(abs(x) + abs(y) > count){
      printf("%d\n", abs(x) + abs(y) - count);
    }else{
      printf("%d\n", (count - abs(x) + abs(y))%2);
    }
  }
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %d", s, &t);
   ^