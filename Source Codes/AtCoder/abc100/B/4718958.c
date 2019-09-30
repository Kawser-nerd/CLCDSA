#include<stdio.h>
int d, n, i;
int main(void){
  scanf("%d%d", &d, &n);
  if(n==100){
    printf("101");
  }else{
    printf("%d", n);
  }
  for(i=0; i<d; i++){printf("00");}
  puts("");
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &d, &n);
   ^