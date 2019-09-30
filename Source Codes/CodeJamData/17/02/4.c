#include <stdio.h>

char s[20];

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    int t, ti;
    scanf("%i", &t);
    for (ti = 1; ti <= t; ++ti) {
        scanf("%s", &s);

        int nines = 0;
        int i, j;
        for (i = 1; s[i]; ++i) {
            if (s[i - 1] > s[i]) {
                if (s[i - 1] == '1' && s[i] == '0') {
                    for (j = 0; s[j]; ++j) {
                        s[j] = '9';
                    }
                    s[j - 1] = 0;
                }
                else {
                    while (i > 0 && s[i - 1] > s[i]) {
                        --s[i - 1];
                        --i;
                    }

                    for (j = i + 1; s[j]; ++j) s[j] = '9';
                }
                break;
            }
        }

        printf("Case #%i: %s\n", ti, s);
    }

    return 0;
}

