#include <cstdio>
#include <algorithm>

using namespace std;

int main () {

    int n, k;
    scanf("%d %d", &n, &k);

    int t[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    int ans = -1, sumSleepTime = t[0] + t[1];
    for (int i = 2; i < n; i++) {
        sumSleepTime += t[i];
        if (sumSleepTime < k) {
            ans = i + 1;
            break;
        }
        sumSleepTime -= t[i - 2];
    }
    printf("%d\n", ans);

    return 0;
}