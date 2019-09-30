#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <ctime>

using namespace std;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);
	int t,i,j,ii=0;

	scanf("%d",&t);
	while(t--)
	{
		long long n,rr;
		int ans=0;
		cin>>rr>>n;
		rr*=2,rr-=3;

		long long l=1,r=1000000000,mid;

		while(l<r)
		{
			mid=(l+r+1)/2;

			if(rr+2*(mid+1)<=n/mid)
				l=mid;
			else
				r=mid-1;
		}

		ans=l;
		printf("Case #%d: ",++ii);
		cout<<ans<<endl;
	}
}