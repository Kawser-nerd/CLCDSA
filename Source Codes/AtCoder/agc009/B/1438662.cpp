#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int n,p,f[200000];
vector<int> s[200000];
int dp(int x)
{
	if(s[x].empty())return 0;
	vector<int> d;
	for(auto i:s[x])d.push_back(dp(i));
	sort(d.begin(),d.end(),greater<int>());
	int ans=0;
	for(auto i=0;i<d.size();i++)ans=max(ans,d[i]+i+1);
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)scanf("%d",&p),s[p].push_back(i);
	printf("%d\n",dp(1));
	return 0;
}