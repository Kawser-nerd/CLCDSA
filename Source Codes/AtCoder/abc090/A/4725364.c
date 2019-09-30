#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    char s[3][3];
    int i;
    for(i=0;i<3;i++){
        scanf("%s", s[i]);
    }
    for(i = 0; i < 3; i++)
    {
        printf("%c", s[i][i]);
    }
    
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", s[i]);
         ^