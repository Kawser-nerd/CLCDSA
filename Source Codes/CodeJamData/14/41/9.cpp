#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int X, N;
        multiset<int> S;
        scanf("%d%d", &N, &X);
        for(int i=0; i<N; i++)
        {
            int s;
            scanf("%d", &s);
            S.insert(-s);
        }
        int ans=0;
        while(!S.empty())
        {
            ans++;
            int F1=*S.begin();
            S.erase(S.begin());
            if(!S.empty())
            {
                auto F2=S.lower_bound(-(F1+X));
                if(F2!=S.end())
                {
                    S.erase(F2);
                }
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
}
