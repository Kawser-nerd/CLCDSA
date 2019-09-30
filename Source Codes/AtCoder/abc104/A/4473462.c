#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int main(){
    int R;
    scanf("%d",&R);
    if(2800<=R) printf("AGC");
    else if(1200<=R) printf("ARC");
    else printf("ABC");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&R);
     ^