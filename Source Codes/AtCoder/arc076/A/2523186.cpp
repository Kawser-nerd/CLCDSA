#include <cstdio>
using namespace std;

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);

    int diff = (n > m) ? (n - m) : (m - n);
    long long sum = 1;

    //printf("%d\n", diff);

    if (diff >= 2)
        puts("0");
    else if (diff == 1) {
        for (int i = 2; i <= n; i++) {
            sum = sum * i % 1000000007;
        }
        for (int i = 2; i <= m; i++) {
            sum = sum * i % 1000000007;
        }
        printf("%lld\n", sum);
    }
    else {
        sum *= 2;
        for (int i = 2; i <= n; i++) {
            sum = sum * i % 1000000007;
            sum = sum * i % 1000000007;
        }
        printf("%lld\n", sum);
    }

    return 0;
}