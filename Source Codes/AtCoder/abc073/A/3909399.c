#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
      if(n%10==9 || n/10==9){
          printf("Yes");
      }
      else{
          printf("No");
      }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^