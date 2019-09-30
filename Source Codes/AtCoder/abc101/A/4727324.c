#include <stdio.h>

int main(){
  char s[4];
  int count_plus=0;
  scanf("%s", s);

  for(int i=0;i<4;i++){
    if(s[i]=='+'){
      count_plus++;
    }
  }
  printf("%d\n", 2*count_plus - 4);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^