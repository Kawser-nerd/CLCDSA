#include<stdio.h>

int main(void){
 int five=0;
  int hund=0;
  int ten=0;
  int price;
  int count=0;
  int nfive,nhund,nten;
  scanf("%d",&nfive);
  scanf("%d",&nhund);
  scanf("%d",&nten);
  scanf("%d",&price);
  
  for(five=0;five<=nfive;five++){
    for(hund=0;hund<=nhund;hund++){
      for(ten=0;ten<=nten;ten++){
        if(five*500+hund*100+ten*50==price)count++;
      }
    }
  }
  printf("%d",count);
  
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&nfive);
   ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&nhund);
   ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&nten);
   ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&price);
   ^