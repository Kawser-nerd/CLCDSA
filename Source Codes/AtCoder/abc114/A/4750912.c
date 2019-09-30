#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    if((n==7)||(n==5)||(n==3)){
        printf("YES");
    }
    else{
        printf("NO");
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^