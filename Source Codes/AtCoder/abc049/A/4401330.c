#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char c;
    scanf("%c",&c);
    if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
        printf("vowel\n");
    }else{
        printf("consonant\n");
    }
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&c);
     ^