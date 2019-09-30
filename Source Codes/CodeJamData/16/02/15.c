#include <stdio.h>
#include <string.h>


int main(void) {
    int tests;
    scanf("%d", &tests);
    for (int test_num = 1; test_num <= tests; ++test_num) {
        printf("Case #%d: ", test_num);
        char s[256];
        scanf("%s", s);
        int slen = strlen(s);
        s[slen] = '+';
        s[++slen] = 0;
        int ans = 0;
        for (char *c = s; c[1]; ++c) {
            if (c[0] != c[1]) {
                ++ans;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
