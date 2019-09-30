#include <stdio.h>
int main(void){
    int c[3][3] = {0};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &c[i][j]);
        }
    }
    
    int a[3] = {0}; int b[3] = {0};
    a[0] = 0;
    b[0] = c[0][0] - a[0]; b[1] = c[0][1] - a[0]; b[2] = c[0][2] - a[0];
    a[1] = c[1][0] - b[0]; a[2] = c[2][0] - b[0];

    if(c[1][1] == a[1] + b[1]){
        if(c[1][2] == a[1] + b[2]){
            if(c[2][1] == a[2] + b[1]){
                if(c[2][2] == a[2] + b[2]){
                    printf("Yes\n");
                }else {
                    printf("No\n");
                }
            }else {
                printf("No\n");
            }
        }else {
            printf("No\n");
        }
    }else {
        printf("No\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &c[i][j]);
             ^