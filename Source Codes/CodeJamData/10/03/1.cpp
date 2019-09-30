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

#define _int64 long long

int a[2000];
_int64 next[2000];
_int64 cnt[2000];

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int i,j,r,k,n,l,t;
    _int64 tot,prev,ans,now;
    scanf("%d",&t);
    for (l=0;l<t;l++)
    {
        scanf("%d%d%d",&r,&k,&n);
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (i=0;i<n;i++)
        {
            tot=0;
            prev=0;
            for (j=0;j<n;j++)
            {
                tot+=a[(i+j)%n];
                if (tot>k) break;
                prev=tot;
            }
            next[i]=(i+j)%n;
            cnt[i]=prev;
        }
        ans=0;
        now=0;
        for (i=0;i<r;i++)
        {
            ans+=cnt[now];
            now=next[now];
        }
        printf("Case #%d: %lld\n",l+1,ans);
    }
	return 0;
}

