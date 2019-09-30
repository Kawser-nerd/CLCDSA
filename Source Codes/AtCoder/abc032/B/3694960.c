#include <stdio.h>
#include <string.h>
#include <stdio.h>

char w[301][301];
int cnt = 0;

void pool(char *s, int k) {
    for (int i = 0; i < cnt; i++) {
        if (strncmp(w[i], s, k) == 0) {
            return;
        }
    }
    strncpy(w[cnt], s, k);
    cnt++;
}

int main() {
    int k;
    char s[301] = { 0 }, t[301] = { 0 };
    int len = 0;

    scanf("%s", s);
    scanf("%d", &k);

    len = strlen(s); 

    if (len == k) {
        printf("1\n");
    } else if (len < k) {
        printf("0\n");
    } else {
        for (int i = 0; i < len - k + 1; i++) {
            strncpy(t, &s[i], k);
            pool(t, k);
        }
        printf("%d\n", cnt);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &k);
     ^