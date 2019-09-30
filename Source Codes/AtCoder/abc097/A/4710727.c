#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int a, b, c, d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(abs(a-c) <= d){
        printf("Yes\n");
    }else if(abs(a-b) <= d && abs(b-c) <= d){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&a,&b,&c,&d);
     ^