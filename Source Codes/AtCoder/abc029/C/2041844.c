#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char moji[10];

int main(void){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        moji[i] = 'a';
    }
    moji[n] = '\0';
    for (int i = 0; i < pow(3, n-1); i++){
        for (int j = 0; j < 3; j++){
            printf("%s\n", moji);
            moji[n-1]++;
        }
        for (int k = n-1; k > 0; k--){
            if (moji[k] == 'd'){
                moji[k] = 'a';
                moji[k-1]++;
            }
        }
    }
    return 0;

} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^