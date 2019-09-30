#include <stdio.h>
int main(void){
  int a,b,c,i,j,total,max=0;
  scanf("%d%d%d",&a,&b,&c);
  for(i=0;i<=c;i++){
    for(j=0;j<=c-a*i;j++){
      total=a*i+b*j;
      if((total<=c)&&i+j>max) max=i+j;
      if(total>=c) break;
    }
  }
  printf("%d",max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^