#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int x[n];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++) {
        ans += min(x[i], k - x[i]);
    }
    printf("%d\n", 2 * ans);
    return 0;
}