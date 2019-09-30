#include <stdio.h>
#include <string.h>

const int M = 2000;
int main() {
    int tc;
    char str[M];
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        int m, n;
        scanf("%s%d", str, &n);
        m = strlen(str);
        bool flag = true;
        int inc = 0;
        for (int p = 0; p < m; p++) {
            if (str[p] == '+') {
                continue;
            }
            if (p + n > m) {
                flag = false;
                break;
            }
            for (int q = p; q < p + n; q++) {
                str[q] = (str[q] == '+' ? '-' : '+');
            }
            inc++;
            //printf("%s\n", str);
        }
        printf("Case #%d: ", t);
        if (flag == false) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", inc);
        }
    }
}
