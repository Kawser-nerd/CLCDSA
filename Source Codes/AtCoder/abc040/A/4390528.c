#include <stdio.h>

int main(){
    int n, x;
    scanf("%d%d", &n,&x);
    if (n/2>=x) {
        printf("%d", x-1);
    }else{
        printf("%d", n-x);
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n,&x);
     ^