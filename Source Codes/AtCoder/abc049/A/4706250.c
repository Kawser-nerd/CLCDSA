#include<stdio.h>
int main(){
    char c;
    scanf("%c",&c);
    if(c=='a' || c == 'i' || c == 'u' || c=='e' || c=='o')
    printf("vowel\n");
    else printf("consonant\n");
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&c);
     ^