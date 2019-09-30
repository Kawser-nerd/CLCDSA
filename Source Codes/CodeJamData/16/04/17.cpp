#include <cstdio>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int z = 1; z <= t; z++) {
        long long k, c, s;
        scanf("%lld %lld %lld", &k, &c, &s);

        printf("Case #%d: ", z);
        if (s*c < k) {
            printf("IMPOSSIBLE\n");
            continue;
        }

        int cnt = 0;
        for (int j = 0; j < k; j += c) {
            long long num = 0;

            for (int i = j; i < j+c; i++) {
                num *= k;
                num += (i < k ? i : 0);
            }

            printf("%lld ", num + 1);
        }
        printf("\n");
    }
}
