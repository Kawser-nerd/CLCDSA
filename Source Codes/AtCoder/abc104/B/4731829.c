#include <stdio.h>
#include <string.h>

int main(void){
    char S[11];
    int c = 0;
    int small = 0;
    scanf("%s", S);
    for(int i = 1; i < strlen(S) ; i++){
        if((i > 1) && (i < strlen(S)-1) && S[i] == 'C') c += 1;
        else if('a' > S[i] || S[i] > 'z') small += 1;  
    }
    printf("%s\n", (small == 0 && c == 1 && S[0] == 'A') ? "AC" : "WA");
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^