#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int now_tmp, target_tmp;    //???????
    int dif_tmp;    //???????
    int num = 0;    //??
    
    scanf("%d %d%*c", &now_tmp, &target_tmp);
    dif_tmp = (int)abs(target_tmp - now_tmp);
    while(dif_tmp != 0){
        if(dif_tmp >= 8){
            dif_tmp = (int)abs(dif_tmp - 10);
        }else if(dif_tmp >= 3){
            dif_tmp = (int)abs(dif_tmp - 5);
        }else if(dif_tmp >= -2){
            dif_tmp = (int)abs(dif_tmp - 1);
        }else{
            printf("error\n");
            break;
        }
        num++;
    }
    printf("%d\n", num);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d%*c", &now_tmp, &target_tmp);
     ^