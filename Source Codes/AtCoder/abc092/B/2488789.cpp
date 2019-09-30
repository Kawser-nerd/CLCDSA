#include <cstdio>
#define MAX_N 100
using namespace std;

int main() {
    int n, d, x;
    int ans = 0;
    int a[MAX_N];
    scanf("%d %d %d", &n, &d, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= d; j+=a[i]) {
            ans++;
        }
    }
    printf("%d\n", ans + x);
    return 0;
}