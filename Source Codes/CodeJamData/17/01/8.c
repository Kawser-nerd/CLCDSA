#include <stdio.h>
#include <stdlib.h>

char s[1001];

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int t, ti;
    scanf("%i", &t);
    for (ti = 1; ti <= t; ++ti) {
        int k;

        scanf("%s%i", s, &k);

        int sl = strlen(s);

        int i, j;

        int plus = 0;
        for (i = 0; i <= sl - k; ++i) {
            if (s[i] == '+') continue;

            ++plus;
            for (j = 0; j < k; ++j) {
                if (s[i + j] == '+') s[i + j] = '-';
                else s[i + j] = '+';
            }
        }

        for (i = 0; i < sl; ++i) {
            if (s[i] != '+') plus = -1;
        }

        printf("Case #%i: ", ti);
        if (plus == -1) printf("IMPOSSIBLE\n");
        else printf("%i\n", plus);
    }

    return 0;
}
