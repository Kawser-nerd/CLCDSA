#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  if(N/3600 < 10) printf("0");
  printf("%d:",N/3600);

  if(N/60-(N/3600)*60 < 10) printf("0");
  printf("%d:",N/60-(N/3600)*60);

  if(N%60 < 10) printf("0");
  printf("%d\n",N%60);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^