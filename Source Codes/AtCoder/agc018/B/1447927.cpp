#include<cstdio>
#include<cstring>
#include<unordered_map>
using namespace std;
int n,m,a[500][500],ban[500],cur[500];
bool check(int x)
{
	memset(ban,0,sizeof ban);
	for(int i=1;i<=n;i++)cur[i]=1;
	for(;;)
	{
		unordered_map<int,int> M;
		for(int i=1;i<=n;i++)
		{
			while(cur[i]<=m&&ban[a[i][cur[i]]])cur[i]++;
			if(cur[i]>m)return false;
			M[a[i][cur[i]]]++;
		}
		bool f=true;
		for(auto i:M)
			if(i.second>x){f=false;ban[i.first]=1;}
		if(f)return true;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	int l=1,r=n,ans=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}