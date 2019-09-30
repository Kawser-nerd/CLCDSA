#include <stdio.h>

int main(void) 
{
    char str[4]; int i, cnt = 0;
    scanf("%s", str);
    for(i = 0; i < 3; ++i) {
        if(str[i] == '1') { ++cnt; }
    }
    printf("%d\n", cnt);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", str);
     ^