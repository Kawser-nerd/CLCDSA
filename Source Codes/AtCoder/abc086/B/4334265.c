#include <stdio.h>
int main(){
  int a,b,c,judge=1;
  scanf("%d%d",&a,&b);
  if (b<10){
    c=a*10+b;
  }
  if (9<b && b<100){
    c=a*100+b;
  }
  if (b==100){
    c=1000*a+b;
  }
  for (int i=1;i<317;i++){
    if (i*i==c){
      judge=0;
      printf("Yes\n");
      break;
    }
  }
  if (judge){
    printf("No\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^