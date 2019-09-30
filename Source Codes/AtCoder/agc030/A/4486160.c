#include<stdio.h>
int main(void)
{
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  if(a+b >= c-1){
    printf("%d", b+c);
  }
  else{
    if(a<c){
      if(c-a-1 >= b){
        printf("%d", a+1+2*b);
      }
      else{
        printf("%d", a+1+b);
      }
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &a, &b, &c);
   ^