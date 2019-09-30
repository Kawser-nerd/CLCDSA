#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int a, b, x;
    scanf("%d%d%d",&a,&b,&x);
    if(x<a || a+b <x){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&x);
     ^