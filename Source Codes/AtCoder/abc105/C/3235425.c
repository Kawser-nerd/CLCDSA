#include <stdio.h>
#include <math.h>
int main(void){
    int n,m,i,k=0;
    int s[100];
    scanf("%d",&n);
    do{
      m = abs(n)%2;
      s[k] = m;
      n = (n-m)/(-2);
      k++;
    }while(n!=0);
    for(i=k-1;i>=0;i--){
      printf("%d",s[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:11: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
       m = abs(n)%2;
           ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^