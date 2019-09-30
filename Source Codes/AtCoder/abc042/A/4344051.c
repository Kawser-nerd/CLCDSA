#include<stdio.h>

int main(void){
  int a[3],cnt5=0,cnt7=0,i;
  scanf("%d%d%d",&a[0],&a[1],&a[2]);
  for(i=0;i<3;i++){
    if(a[i]==5) cnt5++;
    else if(a[i]==7) cnt7++;
  }
  if((cnt5==2) && (cnt7==1)) printf("YES\n");
  else printf("NO\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a[0],&a[1],&a[2]);
   ^