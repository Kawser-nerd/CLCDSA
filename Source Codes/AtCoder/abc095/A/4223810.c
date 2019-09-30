#include<stdio.h>
int main(void){
    char S[3];
    int sum = 700;
    for(int i = 0; i < 3; i++){
        scanf("%c",&S[i]);
        if(S[i] == 'o') sum += 100;
    }
    printf("%d\n",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%c",&S[i]);
         ^