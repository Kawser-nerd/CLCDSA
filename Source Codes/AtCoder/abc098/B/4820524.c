#include <stdio.h>

int count(char s[], int len, int border){
    int n = 0;
    int s1[26] = {0};
    int s2[26] = {0};
    for(int i = 0; i < len; i++){
        if(i < border){
            s1[s[i] - 'a'] = 1;
        }
        else 
            s2[s[i] - 'a'] = 1;
    }
    for(int i = 0; i < 26; i++){
        if(s1[i] == s2[i]){
            n += s1[i];
        }
    }
    return n;
}

int main(void){
    int N;
    scanf("%d", &N);
    char s[N + 1];
    scanf("%s", s);
    int max = 0;
    for(int i = 1; i < N; i++){
        int tmp = count(s, N, i);
        max = (tmp > max) ? tmp : max;
    }
    printf("%d\n", max);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^