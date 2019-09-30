#include<stdio.h>
int main(void){

  int num, sum;
  sum = 0;
  scanf("%d", &num);

  while(num - 10 >= 0){
    sum += 100;
    num -= 10;
//  printf("%d %d\n",sum,num);
  }
  if(num >= 7){
    sum += 100;

  }else{
    sum += num * 15;
  }
  printf("%d\n",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &num);
   ^