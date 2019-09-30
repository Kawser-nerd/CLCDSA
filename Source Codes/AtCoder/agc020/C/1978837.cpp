#include <cstdio>
#include <bitset>
using namespace std;
bitset<2000025> sum1, sum2;
int a[2005];
int main()
{
    int n, i, rea = 0, j = 2000005, ans;
    scanf("%d", &n);
    for(i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
        rea += a[i];
    }
    sum1[0] = 1, sum2[0] = 1;
    for(i = 1; i <= n / 2; ++i)
        sum1 |= sum1 << a[i];
    for(i = n; i > n / 2; --i)
        sum2 |= sum2 << a[i];
    i = 0, ans = rea;
    while(i < 2000005 && ~j)
    {
        if(!sum1[i]) ++i;
        else if(!sum2[j]) --j;
        else if(i + j < (rea + 1) / 2) ++i;
        else
        {
            if(ans > i + j) ans = i + j;
            --j;
        }
    }
    printf("%d\n", ans);
    return 0;
}