#include <cstdio>
#include <cstdlib>
#include <cstring>

int t,n,now,x;
char s[1000005];
long long ans;

int main()
{
    freopen("a-in.txt","r",stdin);
    freopen("a-out.txt","w",stdout);
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%s%d",s,&n);
        now=-1;
        ans=0;
        x=0;
        for(int i=0;s[i];i++)
        {
            if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')x++;
            else x=0;
            if(x>=n)now=i-n+1;
            ans+=now+1;
        }
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}
