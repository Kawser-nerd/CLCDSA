#include <bits/stdc++.h>

using namespace std;

long long N, K;

void _main(int TEST)
{
    scanf("%lld%lld", &N, &K);
    map<long long, long long> Q;
    Q[N]=1;
    while(!Q.empty())
    {
        long long n=(--Q.end())->first;
        long long k=(--Q.end())->second;
        if(k==0)
            continue;
        if(k>=K)
        {
            printf("%lld %lld\n", n/2, (n-1)/2);
            break;
        }
        K-=k;
        Q.erase(--Q.end());
        if(n/2>0)
            Q[n/2]+=k;
        if((n-1)/2>0)
            Q[(n-1)/2]+=k;
    }
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
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
