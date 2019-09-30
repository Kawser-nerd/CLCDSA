#include <stdio.h>
int main(void){
    int a,b,n,i;
    a = 100;
    scanf("%d",&n);
    for(i=0;i<n;i++){
         scanf("%d",&b);
         if(a > b){
              a = b;
         }
    }
    printf("%d\n",a);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:10: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
          scanf("%d",&b);
          ^