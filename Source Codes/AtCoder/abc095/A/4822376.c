#include <stdio.h>

int main(void){
    char s[4];
    scanf("%s", s);
    int ans = 0;
    for (int i = 0; i < 3; i++){
        if(s[i] == 'o') ans += 1;
    }
    printf("%d\n", ans * 100 + 700);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^