#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int d1, d2;
        scanf("%d %d", &d1, &d2);
        ans += d2 - d1 + 1;
    }
    printf("%d\n", ans);
    return 0;
}