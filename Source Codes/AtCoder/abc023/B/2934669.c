#include <stdio.h>
#include <string.h>
int main() {
    int N;
    char S[128];
    scanf("%d%s", &N, S);
    char ans[100][128];
    strcpy(ans[0], "b");
    for (int i = 1; i < 60; i++) {
        if (i % 3 == 1) {
            strcpy(ans[i], "a");
            strcat(ans[i], ans[i-1]);
            strcat(ans[i], "c");
        } else if (i % 3 == 2) {
            strcpy(ans[i], "c");
            strcat(ans[i], ans[i-1]);
            strcat(ans[i], "a");
        } else {
            strcpy(ans[i], "b");
            strcat(ans[i], ans[i-1]);
            strcat(ans[i], "b");
        }
    }
    int res = -1;
    for (int i = 0; i < 60; i++) {
        if (strcmp(ans[i], S) == 0) {
            res = i;
            break;
        }
    }
    printf("%d\n", res);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%s", &N, S);
     ^