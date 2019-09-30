#include <stdio.h>
#include <stdlib.h>

int main(){
    int X,Y,Z;
    int count=0;
    scanf("%d%d%d", &X,&Y,&Z);
    for (int sum=Z; sum<=X; ) {
        count++;
        sum+=(Y+Z);
    }
    printf("%d",count-1);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &X,&Y,&Z);
     ^