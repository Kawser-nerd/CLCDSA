#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matcher(char *pattern, char *word) {
    int i;
    int l = 0;
    int matched = 1;
    for (i = 0; i < strlen(pattern); i ++) {
        if (l > strlen(word)) {
            return 0;
        }
        if (pattern[i] == '(') {
            i ++;
            matched = 0;
            while (i < strlen(pattern) && pattern[i] != ')') {
                if (pattern[i] == word[l]) {
                    matched = 1;
                    l ++;
                    // iterate pattern until pattern[i] = ')'
                    while (i < strlen(pattern) && pattern[i] != ')') {
                        i++;
                    }
                    break;
                }
                i ++;
            }
            if (matched == 0) {
                return 0;
            }
        }
        else if (pattern[i] == word[l]) {
            l ++;
            continue;
        }
        else {
            return 0;
        }
    }
    // came here mean we matched..
    return 1;
}

int main() {
    int L;
    int D;
    int N;
    scanf("%d %d %d", &L, &D, &N);

    int i;
    char **words;
    words = (char**)malloc(sizeof(char*) * D);
    for (i = 0; i < D; i ++) {
        words[i] = (char*)malloc(sizeof(char*) * (L + 1));
        scanf("%s", words[i]);
    }

    char pattern[100000];
    int j;
    for (i = 0; i < N; i ++) {
        scanf("%s", pattern);
        int count = 0;
        for (j = 0; j < D; j ++) {
            count += matcher(pattern, words[j]);
        }
        printf("Case #%d: %d\n", i + 1, count);
    }
    return 0; 
}
