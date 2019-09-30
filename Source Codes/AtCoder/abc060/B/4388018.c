#include<stdio.h>

int main(void)
{
  int a, b, c;
  int i;

  scanf("%d%d%d",&a, &b, &c);
  for(i=1;i<b;i++){
    if(a * i % b == c){
      break;
    }
  }
  if(i == b)
    printf("NO\n");
  else
    printf("YES\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a, &b, &c);
   ^