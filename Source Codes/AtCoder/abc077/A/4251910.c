#include <stdio.h>
int main(void){
    char c[2][3] = {0};
    for(int i = 0; i < 2; i++){
        scanf("%s", c[i]);
    }
    int flag1 = 0; int flag2 = 0; int flag3 = 0;
    if(c[0][0] == c[1][2]){
        flag1 = 1;
    }
    if(c[0][1] == c[1][1]){
        flag2 = 1;
    }
    if(c[0][2] == c[1][0]){
        flag3 = 1;
    }

    if(flag1 == 1 && flag2 == 1 && flag3 == 1){
        printf("YES\n");
    }else {
        printf("NO\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", c[i]);
         ^