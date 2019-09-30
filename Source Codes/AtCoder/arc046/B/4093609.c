#include<stdio.h>
#include<stdlib.h>

int calc(int n,int a,int b){
  if(n<=a) return 1;
  if(a==b) return n%(a+1)!=0;
  return a>b;
}

void run(void){
  int n,a,b;
  scanf("%d%d%d",&n,&a,&b);
  puts(calc(n,a,b)?"Takahashi":"Aoki");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&a,&b);
   ^