#include <stdio.h>

int main(void) {
    char str[103];
    scanf("%s", str);
    int i = 0, cnt = 0;
    while(str[i] != '\0') {
        if(str[i] == '\n') { break; }
        cnt++; i++;
    }
    printf("%c%d%c\n", str[0], cnt-2, str[i-1] );
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", str);
     ^