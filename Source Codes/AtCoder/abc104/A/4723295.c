#include <stdio.h>

int main(void){
    int R;
    scanf("%d", &R);
    if(R < 1200){
        printf("%s\n", "ABC");
    }
    else if(R < 2800){
        printf("%s\n", "ARC");
    }
    else printf("%s\n", "AGC");
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &R);
     ^