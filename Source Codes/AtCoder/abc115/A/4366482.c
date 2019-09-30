#include "stdio.h"
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);

    if(n==25){
        printf("Christmas\n");
    }else if(n==24){
        printf("Christmas Eve\n");
    }else if(n==23){
        printf("Christmas Eve Eve\n");
    }else if(n==22){
        printf("Christmas Eve Eve Eve\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^