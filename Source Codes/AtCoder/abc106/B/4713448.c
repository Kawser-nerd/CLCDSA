#include <stdio.h>

int main(void){
    int N; 
    scanf("%d", &N);
    //105 = 3*5*7;
    //165 = 3*5*11;
    //195 = 3*5*13;
    //135 = 3*3*3*5;
    //189 = 3*3*3*7;
    int num[5] = {105, 135, 165, 189, 195};
    int ans = 0;
    for (int i = 0; i < 5; i++){
        if(N >= num[i]){ans += 1;}
        else break;
    }
    printf("%d\n", ans);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^