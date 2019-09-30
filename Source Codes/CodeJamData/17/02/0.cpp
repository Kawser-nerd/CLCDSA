#include <bits/stdc++.h>

using namespace std;

long long N;

long long rec(__int128 cur, int last)
{
    if(cur>N)
        return 0;
    long long ret=cur;
    for(; last<=9; last++)
        ret=max(ret, rec(cur*10+last, last));
    return ret;
}

void _main(int TEST)
{
    scanf("%lld", &N);
    printf("%lld\n", rec(0, 1));
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        //cerr << i << endl;
        printf("Case #%d: ", i);
        _main(i);
    }
    return 0;
}
