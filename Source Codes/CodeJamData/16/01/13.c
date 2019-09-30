#include <stdio.h>


int main(void) {
    int tests;
    scanf("%d", &tests);
    for (int test_num = 1; test_num <= tests; ++test_num) {
        printf("Case #%d: ", test_num);
        long long int n;
        scanf("%lld", &n);
        if (n == 0) {
            printf("INSOMNIA\n");
            continue;
        }
        int flags = 0;
        long long int i;
        for (i = 1; flags != (1 << 10) - 1; ++i) {
            long long int cn = i * n;
            while (cn > 0) {
                flags |= 1 << (cn % 10);
                cn /= 10;
            }
        }
        printf("%lld\n", (i - 1) * n);
    }

    return 0;
}
