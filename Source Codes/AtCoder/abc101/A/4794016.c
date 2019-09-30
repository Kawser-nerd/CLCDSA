#include <stdio.h>

int main(void){
    int n = 0;
    char s[5];
    scanf("%s", s);
    for(int i = 0; i < 4; i++){
        if(s[i] == '+'){n += 1;}
        else if(s[i] == '-'){n -= 1;}
    }
    printf("%d\n", n);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^