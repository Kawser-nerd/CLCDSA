#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
    char s[10];
    int min = 1000;
    scanf("%s", s);
    int i = 0;

    while(i < strlen(s) - 2) {
        int num = (s[i] - '0') * 100 + (s[i + 1] - '0') * 10 + (s[i + 2] - '0');
        if(abs(num - 753) < min){
            min = abs(num-753);
        }
        i++;
    }

    printf("%d\n", min);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^