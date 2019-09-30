#include <stdio.h>
#include <string.h>

const int M = 2000;
int main() {
    int tc;
    char str[M];
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        int m, n;
        scanf("%s", str);
        m = strlen(str);
        for (int i = m - 1; i > 0; i--) {
            if (str[i] < str[i - 1]) {
                str[i - 1] --;
                for (int j = i; j < m; j++) {
                    str[j] = '9';
                }
            }
        }
        char *p = str;
        while (*p == '0') p++;
        printf("Case #%d: ", t);
        printf("%s\n", p);
    }
}
