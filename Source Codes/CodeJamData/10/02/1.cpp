#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

struct rec
{
    int a[200];
    int w;
};

rec a[2000];
vector<string> ss;

bool pcmp(string a,string b)
{
    int i;
    if (a.length()!=b.length())
        return a.length()<b.length();
    for (i=0;i<a.length();i++)
    {
        if (a[i]!=b[i])
            return a[i]<b[i];
    }
    return false;
}

void jian(rec &x,rec y)
{
    int i;
    for (i=0;i<200;i++)
    {
        x.a[i]-=y.a[i];
        if (x.a[i]<0)
        {
            x.a[i]+=10;
            x.a[i+1]--;
        }
    }
    while ((x.w>1)&&(x.a[x.w-1]==0)) x.w--;
}

void mod(rec &x,rec y)
{
    int i,j,b1;
    rec tmp;
    for (i=199;i>=y.w;i--)
    {
        memset(tmp.a,0,sizeof(tmp.a));
        for (j=y.w-1;j>=0;j--)
            tmp.a[i-1-(y.w-1-j)]=y.a[j];
        tmp.w=i;
        while (x.a[i]>0)
        {
            jian(x,tmp);
        }
    }
    while (1)
    {
        b1=1;
        for (i=y.w-1;i>=0;i--)
        {
            if (x.a[i]>y.a[i]) break;
            if (y.a[i]>x.a[i])
            {
                b1=0;break;
            }
        }
        if (b1==0) break;
        jian(x,y);
    }
    while ((x.w>1)&&(x.a[x.w-1]==0)) x.w--;
}

void gcd(rec &x,rec &y)
{
    rec z;
    while (1)
    {
        if ((y.w==1)&&(y.a[0]==0)) return;
        z=y;
        y=x;
        x=z;
        mod(y,x);
    }
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int i,j,n,l,t;
    char s[1000];
    rec ans,tmp;
    scanf("%d",&t);
    for (l=0;l<t;l++)
    {
        scanf("%d",&n);
        ss.clear();
        for (i=0;i<n;i++)
        {
            scanf("%s",s);
            ss.push_back(s);
        }
        sort(ss.begin(),ss.end(),pcmp);
        for (i=0;i<n;i++)
        {
            memset(a[i].a,0,sizeof(a[i].a));
            for (j=ss[i].length()-1;j>=0;j--)
            {
                a[i].a[ss[i].length()-1-j]=ss[i][j]-'0';
            }
            a[i].w=ss[i].length();
        }
        for (i=n-1;i>0;i--)
        {
            jian(a[i],a[i-1]);
        }
        ans=a[1];
        for (i=2;i<n;i++)
        {
            gcd(ans,a[i]);
        }
        memset(tmp.a,0,sizeof(tmp.a));
        for (j=ss[0].length()-1;j>=0;j--)
            tmp.a[ss[0].length()-1-j]=ss[0][j]-'0';
        tmp.w=ss[0].length();
        mod(tmp,ans);
        if ((tmp.w==1)&&(tmp.a[0]==0)) ans=tmp;
        else jian(ans,tmp);
        printf("Case #%d: ",l+1);
        for (i=ans.w-1;i>=0;i--)
            printf("%d",ans.a[i]);
        printf("\n");
    }
	return 0;
}

