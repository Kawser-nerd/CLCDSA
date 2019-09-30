# include <stdio.h>
# include <string.h>

char *rotation(char s[]){
    char tmp_1, tmp_2;
    tmp_2 = s[0];
    for (int i = 0; i < strlen(s)-1; ++i){
        tmp_1 = s[i+1];
        s[i+1] = tmp_2;
        tmp_2 = tmp_1;
    }
    s[0] = tmp_1;

    return s;
}

int main(){
    char S[100], T[100];

    scanf("%s", S);
    scanf("%s", T);

    int flg = 0;
    for (int i = 0; i < strlen(T); ++i){
        *S = *rotation(S);
        int ct = 0;
        for (int i = 0; i < strlen(T); ++i){
            if (S[i] == T[i]) ct++;
        }
        if (ct == strlen(T)){
            flg = 1;
            break;
        }
    }

    if (flg == 1) printf("Yes");
    else printf("No");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", T);
     ^