#include<stdio.h>
int main(void){
    char c[3][4];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            scanf("%c",&c[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        printf("%c",c[i][i]);
    }
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%c",&c[i][j]);
             ^