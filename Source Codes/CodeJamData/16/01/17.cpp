#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int z = 1; z <= t; z++) {
        int n;
        scanf("%d", &n);

        printf("Case #%d: ", z);
        if (n == 0) {
            printf("INSOMNIA\n");
            continue;
        }

        bool digits[10];
        memset(digits, 0, sizeof digits);

        int cur = 0;
        int seen = 0;

        while (seen < 10) {
            cur += n;
            int tmp = cur;

            while (tmp > 0) {
                if (!digits[tmp % 10])
                    seen++;
                digits[tmp % 10] = true;
                tmp /= 10;
            }
        }

        printf("%d\n", cur);
    }
}
