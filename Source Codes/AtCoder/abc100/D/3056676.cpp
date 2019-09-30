#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1010;
typedef long long LL;
struct Node
{
    LL x,y,z;
} a[maxn];
int n,m,i,j,k;

bool _cmp(const Node &n1,const Node &n2)
{
    return n1.x*i+n1.y*j+n1.z*k>n2.x*i+n2.y*j+n2.z*k;
}

int main()
{
    //freopen("1.txt","r",stdin);
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int q=0;q<n;q++) scanf("%lld%lld%lld",&a[q].x,&a[q].y,&a[q].z);
        LL ans=0;
        for (i=-1;i<=1;i+=2)
            for (j=-1;j<=1;j+=2)
                for (k=-1;k<=1;k+=2)
                {
                    sort(a,a+n,_cmp);
                    LL t[4]={0};
                    for (int q=0;q<m;q++)
                    {
                        t[1]+=a[q].x;
                        t[2]+=a[q].y;
                        t[3]+=a[q].z;
                    }
                    ans=max(ans,t[1]*i+t[2]*j+t[3]*k);
                }
        printf("%lld\n",ans);
    }
    return 0;
}