#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<vector>
#include<set>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=(int )2e5+50;
int n;
int a[maxn];
bool cz[maxn];
int ssd[maxn];
int main()
{
	int maxssd=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		
		if(cz[a[i]-1])
		{
			ssd[a[i]]=ssd[a[i]-1]+1;
		}else
		ssd[a[i]]=1;
		cz[a[i]]=true;
	}
	for(int i=1;i<=n;i++)
	maxssd=max(ssd[i],maxssd);
	cout<<n-maxssd<<endl;

}