#include<stdio.h>
int main(void){

  int a, ans;

  scanf("%d", &a); scanf("%d", &ans);

    if (ans != a) {
      printf("%d", a);
    }else{
      printf("%d", a - 1);
    }
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a); scanf("%d", &ans);
   ^
./Main.c:6:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a); scanf("%d", &ans);
                    ^