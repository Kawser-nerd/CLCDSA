#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define string_MAX 101
#define min(a, b) (a<b ? a:b)

void sort_String (int N, int K, char str[]) {
    char T[N+1];
    int count_s[26] = {0}, count_t[26] = {0};
    // ????????????????????
    for (size_t i = 0; i < N; i++) {
        count_s[str[i] - 'a'] ++;
        count_t[str[i] - 'a'] ++;
    }
    // ????
    for (size_t i = 0; i < N; i++) {
        for (size_t index = 0; index < 26; index++) {
            if (count_t[index] == 0) { continue;} //???????????
            char c = 'a' + index;
            int different = 0;  // ?????
            for (size_t j = 0; j < i; j++) {
                if (str[j] != T[j]) {different ++;} // i-1???????????
            }
            if (c != str[i]) {different ++;}    // i???????????
            count_s[str[i] - 'a'] --;
            count_t[index] --;
            int number = (N-1)-i;   // ??????
            for (size_t j = 0; j < 26; j++) {
                number -= min(count_s[j], count_t[j]);
            }
            different += number;
            if (different <= K) {
                T[i] = ('a'+index);
                break;
            }
            count_s[str[i]-'a'] ++;
			count_t[index] ++;
        }
    }

    for (size_t i = 0; i < N; i++) {
        printf("%c", T[i] );
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    // ???
    int N, K;
    char S[string_MAX];
    // ??
    scanf("%d %d", &N, &K);
    scanf("%s", S);
    // ??
    sort_String(N, K, S);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:52:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &K);
     ^
./Main.c:53:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^