#include<stdio.h>
int main(void){

  int a, b, c ,total, rec, pro;

  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);
  total = c;
  rec = c;
   while(rec >= a ){
     total += (rec / a) * b;/*???????
     printf("%d\n",total);      ????*/
      rec = ((rec / a) * b) + (rec - (rec / a) * a); /*????????????????????
      printf("%d\n",rec); ????*/
   }
   printf("%d\n", total);
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&b);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&c);
   ^