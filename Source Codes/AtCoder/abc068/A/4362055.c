# include <stdio.h>

int main(){
  int a;
  scanf("%d",&a);
  printf("ABC%d\n",a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^