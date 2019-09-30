#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=2000+10;
int a[maxn],b[maxn];
int flag[maxn];
int n,t,id;

int main()
{
    for (scanf("%d",&t);t--;)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d%d",&a[i],&b[i]);
        for (int i=0;i<n;i++) flag[i]=0;

        int res=0,cnt=n,now=0;
        for (;cnt;)
        {
            int w=-1;
            for (int j=0;j<n;j++)
            if (flag[j]!=2 && b[j]<=now)
                w=j;
            
            if (w!=-1)
            {
                now+=2-flag[w];
                flag[w]=2;
                cnt--;
                res++;
                continue;
            }
            
            for (int j=0;j<n;j++)
            if (flag[j]==0 && a[j]<=now && 
                    (w==-1 || b[w]<b[j]))
                w=j;
            if (w!=-1)
            {
                flag[w]=1;
                res++;
                now++;
            } else break;
        }

        printf("Case #%d: ",++id);
        if (cnt) printf("Too Bad\n");
        else printf("%d\n",res);
    }
}

