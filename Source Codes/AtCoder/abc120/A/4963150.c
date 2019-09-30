#include <stdio.h>

int main(){
  int a, b, c, count;
  int flag = 0;
  scanf("%d %d %d", &a, &b, &c);

  count = (int)(b / a);
  if(count > c){
    count = c;
  }
  /* while(flag == 0){ */
  /*   if(b > a && count < c){ */
  /*     b -= a; */
  /*     count++; */
  /*   } */
  /*   if(b < a || count == c){ */
  /*     flag = 1; */
  /*   } */
  /* } */
  
  printf("%d\n", count);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &a, &b, &c);
   ^