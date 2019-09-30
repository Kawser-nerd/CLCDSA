#include <stdio.h>

int main (void) {

    char s[20];
    int i;

    scanf("%s" ,s);

    for( i = 0; i < 19; i++) {
        if (i == 5 || i == 13) {
            s[i] = ' ';
        }
    }

    printf("%s\n" ,s);
    
    return 0;

} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s" ,s);
     ^