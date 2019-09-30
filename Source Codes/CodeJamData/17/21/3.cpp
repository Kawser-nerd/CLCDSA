#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <cmath>
#include <string>
#define SIZE 1005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		int D,n;
		scanf("%d %d",&D,&n);
		double mx=0.0;
		for(int i=0;i<n;i++)
		{
			int K,s;
			scanf("%d %d",&K,&s);
			mx=max(mx,(double) (D-K)/(double) s);
		}
		printf("%.10f\n",(double) D/(double) mx);
	}
	return 0;
}
