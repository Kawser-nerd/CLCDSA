#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int x, t;
    scanf("%d%d", &x,&t);
    if(x > t){
        printf("%d\n",x-t);
    }else{
        printf("0\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &x,&t);
     ^