#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    int n;
    scanf("%d", &n);

    int a[300000];
    for (int i = 0; i < n * 3; ++i)
        scanf("%d", &a[i]);

    sort(a, a + n * 3);

    ll ans = 0;
    for (int i = 0; i < n; ++i)
        ans += a[n + i * 2];

    printf("%lld\n", ans);

    return 0;
}