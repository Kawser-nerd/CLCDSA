# include <stdio.h>
# include <string.h>

int main(){
    char S[10];
    int flg = 0;

    scanf("%s", S);

    if (S[0] != 'A') flg = 1;
    else S[0] = 'a';

    int ct = 0;
    for (int i = 2; i < strlen(S)-1; ++i){
        if (S[i] == 'C'){
            S[i] = 'c';
            ct++;
        }
    }
    if (ct != 1) flg = 1;

    if (flg == 0){
        for (int i = 0; i < strlen(S); ++i){
            if ('a' <= S[i] && S[i] <= 'z')
                continue;
            else{
                flg = 1;
                break;
            }
        }
    }

    if (flg == 0) printf("AC");
    else printf("WA");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^