#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;
bool OPEN=1;
vector <pair<char,int> > gao(string a)
{
	vector <pair<char,int> > ans;
	int t=0;
	for(int i=0;i<a.size();i++)
	{
		if(i==0)t++;
		else
		{
			if(a[i]!=a[i-1])
			{
				ans.push_back(make_pair(a[i-1],t));
				t=1;
			}
			else t++;
		}
	}
	ans.push_back(make_pair(a[a.size()-1],t));
	return ans;
}
vector < pair<char,int> > num[111];
int n;
int Solve()
{
	for(int i=1;i<=n;i++)if(num[i].size()!=num[1].size())return -1;
	for(int i=0;i<num[1].size();i++)
		for(int j=1;j<=n;j++)
			if(num[j][i].first!=num[1][i].first)
				return -1;
	int ans=0;
	for(int i=0;i<num[1].size();i++)
	{
		int mi=10000000;
		for(int x=1;x<=100;x++)
		{
			int t=0;
			for(int j=1;j<=n;j++)t+=abs(x-num[j][i].second);
			mi=min(mi,t);
		}
		ans+=mi;
	}
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		num[i]=gao(s);
	}
	int ans=Solve();
	if(ans==-1)puts("Fegla Won");
	else printf("%d\n",ans);
}
int main()
{
	if(OPEN)
	{
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	}
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		printf("Case #%d: ",cas);
		solve();
	}
	return 0;
}
