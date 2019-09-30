#include <bits/stdc++.h>

using namespace std;

vector<int> getkey(long long i, int dig)
{
    vector<int> key;
    for(int b=2; b<=10; b++)
    {
        long long n=0;
        for(int j=dig-1; j>=0; j--)
            n=n*b+((i>>j)&1);
        for(int j=2; 1LL*j*j<=min((long long)n, 3000LL); j++) if(n%j==0)
        {
            key.push_back(j);
            break;
        }
        if((int)key.size()<b-1)
            return vector<int>();
    }
    return key;
}

void _main(int TEST)
{
    map<vector<int>, vector<int>> m;
    for(int i=1; i<(1<<16); i+=2) if((i>>15)&1)
    {
        vector<int> key=getkey(i, 16);
        if(key.size()==9)
            m[key].push_back(i);
    }
    int limit=500;
    for(auto& it: m)
    {
        for(auto& it2: it.second)
        {
            for(auto& it3: it.second)
            {
                for(int i=15; i>=0; i--)
                    printf("%d", (it2>>i)&1);
                for(int i=15; i>=0; i--)
                    printf("%d", (it3>>i)&1);
                for(auto& it4: it.first)
                    printf(" %d", it4);
                printf("\n");
                limit--;
                if(limit==0)
                    return;
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("D-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        printf("Case #%d:\n", i);
        _main(i);
    }
    return 0;
}
