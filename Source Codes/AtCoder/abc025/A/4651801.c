#include<stdio.h>
int main(){
    char S[5];
    int N;
    scanf("%s%d",S,&N);
    printf("%c%c\n",S[(N-1)/5],S[(N-1)%5]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d",S,&N);
     ^