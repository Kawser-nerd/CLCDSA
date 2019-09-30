#include <cstdio>

int main() {
    int n, t1, ans;
    ans = 1001;
    scanf("%d%d", &n, &t1);
    int tmp_min = 1001;
    for (int i = 0; i < n; i++) {
        int c, t;
        scanf("%d%d", &c, &t);
        if (t <= t1) {
            if (c <= tmp_min) {
                ans = c;
                tmp_min = ans;
            };
        }
    }
    if (ans == 1001) {
        printf("TLE\n");
        return 0;
    }
    printf("%d\n", ans);
    return 0;
}