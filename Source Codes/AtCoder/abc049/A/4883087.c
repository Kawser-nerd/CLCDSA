#include <stdio.h>
int main(void){
    char c;
    char vowel[5] = {'a','e','i','o','u'};
    scanf("%c",&c);
    for(int i = 0; i < 5; i++){
        if(c == vowel[i]){
            printf("vowel\n");
            return 0;
        }
    }
    printf("consonant\n");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&c);
     ^