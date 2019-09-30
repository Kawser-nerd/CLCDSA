#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int min(int a,int b){
  if(a>b) return b;
  return a;
}
int main(void){
  int a,b;
  scanf("%d %d",&a,&b);
  printf("%d\n",min((10+a-b)%10,(10+b-a)%10));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^