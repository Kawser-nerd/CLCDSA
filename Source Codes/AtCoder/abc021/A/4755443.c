#include <stdio.h>
#include <math.h>

int main(void){
    int n;
    int cnt;
    int jousu;
    int ans[200];
    int i;

    scanf("%d", &n);

    jousu = 10;
    cnt = 0;
    while(n != 0){
        if(n >= pow(2, jousu)){
            n = n - pow(2, jousu);
            ans[cnt] = pow(2, jousu);
            cnt++;
        }
        else{jousu--;}
    }
    printf("%d\n", cnt);
    for(i = 0; i < cnt; i++){
        printf("%d\n", ans[i]);
    }
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^