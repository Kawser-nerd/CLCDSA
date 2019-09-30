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

vector<pair<int,int> > a;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
	int i,len,s,r,n,l,t,x,y,z,tot,tt;
	double remain,ans,tmp;
	scanf("%d",&tt);
	for (l=0;l<tt;l++)
	{
		scanf("%d%d%d%d%d",&len,&s,&r,&t,&n);
		tot=len;
		a.clear();
		for (i=0;i<n;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			tot-=(y-x);
			a.push_back(make_pair(z,y-x));
		}
		a.push_back(make_pair(0,tot));
		sort(a.begin(),a.end());
		ans=0;
		remain=t;
		for (i=0;i<a.size();i++)
		{
			tmp=(double)a[i].second/(a[i].first+r);
			if (tmp<remain)
			{
				remain-=tmp;
				ans+=tmp;
			}
			else
			{
				ans+=(a[i].second-(a[i].first+r)*remain)/(a[i].first+s)+remain;
				remain=0;
			}
		}
		printf("Case #%d: %.10lf\n",l+1,ans);

	}
	return 0;
}

