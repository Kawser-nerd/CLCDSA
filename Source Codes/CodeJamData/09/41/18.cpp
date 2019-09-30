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

char a[50][50];

int main()
{
    int l,t,i,j,ans,tmp,n,k,b1;
    int min[50];
    //freopen("pa.in","r",stdin);
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    vector<int> aa;
    vector<int> d;
    scanf("%d",&t);
    for (l=0;l<t;l++)
    {
        scanf("%d",&n);
        for (i=0;i<n;i++)
            scanf("%s",a[i]);
        d.clear();
        for (i=0;i<n;i++)
            d.push_back(i);
        for (i=0;i<n;i++)
        {
            for (j=n-1;j>=0;j--)
                if (a[i][j]=='1') break;
            min[i]=j;
        }
        ans=0;
        for (i=n-1;i>=1;i--)
        {
            for (j=d.size()-1;j>=0;j--)
            {
                aa.clear();
                for (k=0;k<d.size();k++)
                    if (k!=j)
                    {
                        aa.push_back(min[d[k]]);
                    }
                sort(aa.begin(),aa.end());
                b1=1;
                for (k=aa.size()-1;k>=0;k--)
                    if (aa[k]>i-((int)aa.size()-k)) b1=0;
                if (b1==1) break;
            }
            ans+=d.size()-1-j;
            d.erase(d.begin()+j);
        }
        printf("Case #%d: %d\n",l+1,ans);
    }
	return 0;
}

