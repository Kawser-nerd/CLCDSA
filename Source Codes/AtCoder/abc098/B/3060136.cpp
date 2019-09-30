#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=110;
char s[maxn];
int a[maxn],b[maxn];
int n;
int main()
{
    //freopen("1.txt","r",stdin);
    while (scanf("%d%s",&n,s)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for (int i=0;i<n;i++) b[s[i]-'a']++;
        int ans=0;
        for (int i=0;i<n;i++)
        {
            a[s[i]-'a']++;
            b[s[i]-'a']--;
            int t=0;
            for (int j=0;j<='z'-'a';j++)
                if (a[j] && b[j])
                    t++;

            ans=max(ans,t);
        }
        printf("%d\n",ans);
    }
    return 0;
}