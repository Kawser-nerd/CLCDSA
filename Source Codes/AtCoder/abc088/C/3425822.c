#include <stdio.h>

int main(void){
    int ab[3][3+1];
    int min = 101;
    for(int i = 0;i<3;i++){
        scanf("%d %d %d",&ab[i][0],&ab[i][1],&ab[i][2]);
        //????????????????????
        if(ab[i][0] < min){
            min = ab[i][0];
        }
        // printf("min %d\n",min);
        // printf("ab[%d][0] %d\n",i,ab[i][0]);
        // printf("ab[%d][1] %d\n",i,ab[i][1]);
        // printf("ab[%d][2] %d\n",i,ab[i][2]);
    }
    int a[3];
    int b[3];
    int flag = 0;
    for(int i = 0;i<=min;i++){
        memset(&a,0,sizeof(a));
        memset(&b,0,sizeof(b));
        a[0] = i;
        b[0] = ab[0][0] - i;
        b[1] = ab[0][1] - i;
        b[2] = ab[0][2] - i;
        a[1] = ab[1][0] - b[0];
        a[2] = ab[2][0] - b[0];
        for(int j = 0;j<3;j++){
            // printf("a %d\n",a[j]);
            // printf("b %d\n",b[j]);
            if(b[j] < 0){
                flag++;
                break;
            }
        }
        if(flag != 0){
            flag = 0;
            continue;
        }
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

    // int min = 101;
    // int tmp = 0;
    // for(int i = 0;i<9;i++){
    //     if(min > ab[i]){
    //         min = ab[i];
    //         tmp = i;
    //     }
    // }
    // int a[3];
    // int b[3];

    // switch(i){

    // }

    //???
    // for(int i = 0;i<9;i++){
    //     printf("%d\n",ab[i]);
    // }
} ./Main.c: In function ‘main’:
./Main.c:21:9: warning: implicit declaration of function ‘memset’ [-Wimplicit-function-declaration]
         memset(&a,0,sizeof(a));
         ^
./Main.c:21:9: warning: incompatible implicit declaration of built-in function ‘memset’
./Main.c:21:9: note: include ‘<string.h>’ or provide a declaration of ‘memset’
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d",&ab[i][0],&ab[i][1],&ab[i][2]);
         ^