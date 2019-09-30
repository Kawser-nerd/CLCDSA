#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int a, b;
    scanf("%d%d",&a,&b);
    if(a>b){
        printf("%d\n",a-1);
    }else{
        printf("%d\n",a);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^