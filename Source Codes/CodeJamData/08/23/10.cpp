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

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);

	int i,j,k,l,t,n,m,now,tmp,x;	
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d",&n);
		scanf("%d",&m);
		printf("Case #%d:",l+1);
		for (i=0;i<m;i++)
		{
			scanf("%d",&x);
			x--;
			for (j=1;j<=n;j++)
			{
				tmp=(j-1)%(n-j+1);
				if (x==tmp) break;
				if (x>tmp) x=x-1-tmp;
				else x=n-j+1-tmp-1+x;
			}
			printf(" %d",j);
		}
		printf("\n");
	}
	return 0;
}

