#include<stdio.h>

void run(void){
  int k;
  scanf("%d",&k);
  if(k==1){
    puts("1 1");
    return;
  }
  int a=2;
  int b=1;
  while(--k){
    int c=a+b;
    b=a;
    a=c;
  }
  printf("%d %d\n",a,b);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^