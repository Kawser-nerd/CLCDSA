#include <stdio.h>

int main(){
    int d;
    scanf("%d",&d);
    if(d==22) printf("Christmas Eve Eve Eve\n");
    else if(d==23) printf("Christmas Eve Eve\n");
    else if(d==24) printf("Christmas Eve\n");
    else if(d==25) printf("Christmas\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&d);
     ^