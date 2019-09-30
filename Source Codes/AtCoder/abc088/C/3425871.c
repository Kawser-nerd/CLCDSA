#include <stdio.h>

int main(void){
    int ab[3][3+1];
    int min = 101;
    //3????????ab?????
    for(int i = 0;i<3;i++){
        scanf("%d %d %d",&ab[i][0],&ab[i][1],&ab[i][2]);
        //????????????????????
        if(ab[i][0] < min){
            min = ab[i][0];
        }
    }
    //a1~a3?b1~b3??????????
    int a[3];
    int b[3];
    //??????????????
    int flag = 0;
    //a1b1???0~min?????????????????????????
    for(int i = 0;i<=min;i++){
        //??a,b??????
        memset(&a,0,sizeof(a));
        memset(&b,0,sizeof(b));
        //a[0]??????????????????
        a[0] = i;
        b[0] = ab[0][0] - i;
        b[1] = ab[0][1] - i;
        b[2] = ab[0][2] - i;
        a[1] = ab[1][0] - b[0];
        a[2] = ab[2][0] - b[0];

        // for(int j = 0;j<3;j++){
        //     if(b[j] < 0){
        //         flag++;
        //         break;
        //     }
        // }
        // if(flag != 0){
        //     flag = 0;
        //     continue;
        // }
        for(int j = 0;j<3;j++){
            if(flag != 0){
                break;
            }
            for(int k = 0;k<3;k++){
                if(ab[j][k] != a[j] + b[k]){
                    flag++;
                    break;
                }
            }
        }
        if(flag == 0){
            printf("Yes\n");
            return 0;
        }
        flag = 0;
    }
    printf("No\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:9: warning: implicit declaration of function ‘memset’ [-Wimplicit-function-declaration]
         memset(&a,0,sizeof(a));
         ^
./Main.c:22:9: warning: incompatible implicit declaration of built-in function ‘memset’
./Main.c:22:9: note: include ‘<string.h>’ or provide a declaration of ‘memset’
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d",&ab[i][0],&ab[i][1],&ab[i][2]);
         ^