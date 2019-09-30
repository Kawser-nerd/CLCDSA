#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int d[11];
    for (int i = 0; i < 11; i++) {
        d[i] = int(pow(2.0, double(i)));
    }
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (d[i + 1] - d[i] < k) ans *= 2;
        else ans += k;
    }
    printf("%d\n", ans);
    return 0;
}