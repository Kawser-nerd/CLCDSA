#include<cstdio>
#include<assert.h>
#include<algorithm>

using namespace std;

int T;
int n,sum;
int a[30];
int a1[30];

inline pair<char,char> try2()
{
    if(sum<2)return make_pair('a','f');
    for(int i=1;i<=n;i++)
        a1[i]=a[i];
    int ma=a1[1],mai=1;
    for(int i=2;i<=n;i++)
        if(a1[i]>ma)
        {
            ma=a1[i];
            mai=i;
        }
    a1[mai]--;
    int ans1=mai;

    ma=a1[1];mai=1;
    for(int i=2;i<=n;i++)
        if(a1[i]>ma)
        {
            ma=a1[i];
            mai=i;
        }
    a1[mai]--;
    int ans2=mai;

    ma=a1[1];
    for(int i=2;i<=n;i++)
        if(a1[i]>ma)
            ma=a1[i];
    if(ma*2>(sum-2))return make_pair('a','f');
    return make_pair('A'+ans1-1,'A'+ans2-1);
}
inline char try1()
{
    assert(sum);

    for(int i=1;i<=n;i++)
        a1[i]=a[i];
    int ma=a1[1],mai=1;
    for(int i=2;i<=n;i++)
        if(a1[i]>ma)
        {
            ma=a1[i];
            mai=i;
        }
    a1[mai]--;

    ma=a1[1];
    for(int i=2;i<=n;i++)
        if(a1[i]>ma)
            ma=a1[i];
    assert(ma*2<=(sum-1));
    return 'A'+mai-1;
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);

    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        printf("Case #%d:",t);

        scanf("%d",&n);
        sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            sum+=a[i];
        }

        while(sum)
        {
            pair<char,char> temp=try2();
            if(temp.second!='f')
            {
                sum-=2;
                a[temp.first-'A'+1]--;
                a[temp.second-'A'+1]--;
                printf(" %c%c",temp.first,temp.second);
            }
            else
            {
                char temp1=try1();
                sum--;
                a[temp1-'A'+1]--;
                printf(" %c",temp1);
            }
        }
        printf("\n");
    }
    return 0;
}
