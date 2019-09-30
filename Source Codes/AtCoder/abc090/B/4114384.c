# include <stdio.h>

int main(){
  int a, b;
  scanf("%d %d", &a, &b);
  int a_flg, b_flg;
  a_flg = (a/100) * 100
    + ((a/1000)%10) * 10
    + (a/10000) - a >= 0;
  b_flg = (b/100) * 100
    + ((b/1000)%10) * 10
    + (b/10000) - b <= 0;
  printf("%d\n",b/100-a/100-1+a_flg+b_flg);
 return 0; 
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &a, &b);
   ^