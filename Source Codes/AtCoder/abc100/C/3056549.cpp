#include <cstdio>
const int maxn=10010;
int n;
int main()
{
    //freopen("1.txt","r",stdin);
    while (scanf("%d",&n)!=EOF)
    {
        int t,ans=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&t);
            while (t%2==0)
            {
                ans++;
                t/=2;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}