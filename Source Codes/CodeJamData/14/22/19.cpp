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
int A[40],B[40],K[40];
long long dp[40][2][2][2];
long long dfs(int pos,int up1,int up2,int uu)
{
	long long &ans=dp[pos][up1][up2][uu];
	if(ans!=-1)return ans;
	if(pos==0)return ans=1;
	int ma1=1;if(up1)ma1=A[pos];
	int ma2=1;if(up2)ma2=B[pos];
	ans=0;
	for(int i=0;i<=ma1;i++)
		for(int j=0;j<=ma2;j++)
		{
			int x=i&j;
			if(uu&&x>K[pos])continue;
			ans+=dfs(pos-1,up1&&i==ma1,up2&&j==ma2,uu&&x==K[pos]);
		}
	return ans;
}
void solve()
{
	int a,b,k;
	cin>>a>>b>>k;
	a--;b--;k--;
	for(int i=1;i<=30;i++)A[i]=a%2,a/=2;
	for(int i=1;i<=30;i++)B[i]=b%2,b/=2;
	for(int i=1;i<=30;i++)K[i]=k%2,k/=2;
	memset(dp,-1,sizeof(dp));
	long long ans=dfs(30,1,1,1);
	cout<<ans<<endl;
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
