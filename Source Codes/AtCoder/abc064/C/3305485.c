#include <stdio.h>
#define MAXNUM 100

int main(void){
    int n;
    scanf("%d", &n);
    
    int i;
    int rate[MAXNUM], exist[8] = {}, num_highrate = 0;
    for(i = 0; i < n; i++){
        scanf("%d", &rate[i]);

        if(rate[i] / 400 >= 8){
            num_highrate++;
        }else{
            exist[rate[i] / 400] = 1;
        }

        //printf("current num_highrate = %d\n", num_highrate);
    }

    int ans = 0;
    for(i = 0; i < 8; i++){
        ans += exist[i];
        //printf("exist[%d] = %d, current ans = %d\n", i, exist[i], ans);
    }

    printf("%d %d\n", (ans == 0)? 1 : ans, ans + num_highrate);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &rate[i]);
         ^