#include <stdio.h>

void sort(char *s, int n) {
    char w;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] > s[j]) {
                w = s[i];
                s[i] = s[j];
                s[j] = w;
            }
        }
    }
}

int main() {
    char s[5] = { 0 };
    int n, count = 0;

    scanf("%s", s);
    scanf("%d", &n);

    sort(s, 5);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            count++;
            if (count == n) {
                printf("%c%c\n", s[i], s[j]);
                goto FOUND_IT;
            }
        }
    }
FOUND_IT:
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^