#include<cstdio>
#include<algorithm>
using namespace std;

int p[1000000];

int main()
{
    int n,id=0,t,a;

    scanf("%d",&n);
    for (int t=0;t<n;t++)
    {
        int m;
        scanf("%d%d",&a,&m);
        for (int i=0;i<m;i++)
            scanf("%d",&p[i]);
        sort(p,p+m);
        int res=m;

        

        for (int k=0;k<=m;k++)
        {
            int rres=m-k;
            long long sum=a;
            for (int i=0;i<k;i++)
            {
                if (p[i]<sum) sum+=p[i];else
                {
                    if (sum==1) {rres=m+1;break;}
                    while (sum<=p[i] && rres<res) {sum+=sum-1;rres++;}
                    sum+=p[i];
                }
            }
            res=min(res,rres);
        }
        printf("Case #%d: %d\n",t+1,res);
    }
}
