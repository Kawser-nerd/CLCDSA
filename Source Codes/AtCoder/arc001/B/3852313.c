#include<stdio.h>
short A, B, D, ans;
short pon[10]={0, 1, 2, 3, 2, 1, 2, 3, 3, 2};
int main(){
  scanf("%hd%hd", &A, &B);
  D=A<B?B-A:A-B;
  printf("%d\n", D/10+pon[D%10]);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%hd%hd", &A, &B);
   ^