#include <cstdio>

using namespace std;
const int M = 1000000007;

int main()
{
    int n;
    scanf("%d", &n);

    int c[100000] = {};
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        c[a] += 1;
    }

    bool f = true;
    for (int i = n - 1; i > 0; i -= 2)
        f = f && (c[i] == 2);
    for (int i = n - 2; i > 0; i -= 2)
        f = f && (c[i] == 0);
    if (n % 2 == 0)
        f = f && (c[0] == 0) && (c[1] == 2);
    else if (n > 1)
        f = f && (c[0] == 1) && (c[1] == 0);
    else // n == 1
        f = f && (c[0] == 1);

    if (!f) {
        printf("0\n");
        return 0;
    }

    int ans = 1;
    for (int i = 0; i < n / 2; ++i)
        ans = (ans * 2) % M;
    printf("%d\n", ans);

    return 0;
}