#include <stdio.h>

int main(){
  int a[5];
  int sumA,sumB,i=0;
  while(i<4){
  	scanf("%d",&a[i]);
    i++;
  }
  sumA = a[0]+a[1];
  sumB = a[2]+a[3];
  
  if(sumA > sumB) printf("Left\n");
  else if(sumA < sumB) printf("Right\n");
  else printf("Balanced");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&a[i]);
    ^