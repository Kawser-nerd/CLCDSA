#include <stdio.h>
#include <assert.h>


int main(void) {
    int tests;
    scanf("%d", &tests);
    for (int test_num = 1; test_num <= tests; ++test_num) {
        printf("Case #%d: ", test_num);
        long long int k, c, s;
        scanf("%lld%lld%lld", &k, &c, &s);
        long long int len = 1;
        for (int i = 0; i < c; ++i) {
            len *= k;
        }
        assert(k == s); // small dataset
        for (long long int i = 0; i < k; ++i) {
            printf("%lld ", len / k * i + 1);
        }
        printf("\n");
    }

    return 0;
}
