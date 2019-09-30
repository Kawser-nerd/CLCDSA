#include <cstdio>
#include <algorithm>

using namespace std;

int main () {

    int n;
    scanf("%d", &n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        ans += max(0, 80 - m);
    }
    printf("%d\n", ans);

    return 0;
}