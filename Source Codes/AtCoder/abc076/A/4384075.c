#include <stdio.h>

int main(){
    int R,G;
    int score;
    scanf("%d%d", &R,&G);
    score = 2 * G - R;
    printf("%d", score);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &R,&G);
     ^