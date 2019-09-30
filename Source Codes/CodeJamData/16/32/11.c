#include <bits/stdc++.h>
using namespace std;
int adj[10][10]={};
		long long n,k;

int solve(int a){
	if(a==n)
		return 1;
	int ans=0;
	for(int i=a+1;i<=n;i++)
		if(adj[a][i]==1)
			ans+=solve(i);
	return ans;
}
int main() {
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++)
	{
		cout<<"Case #"<<tt<<": ";
		cin>>n>>k;
		int f=0;
		for(int i=0;i<(1<<(n*(n-1)/2));i++)
		{
			
			memset(adj,0,sizeof adj);
			int temp=i;
			int cc=1;
			int nn=2;
			while(temp)
			{
				if(temp%2)
					adj[cc][nn]=1;
				temp/=2;
				nn++;
				if(nn==n+1)
				{
					cc++;
					nn=cc+1;
				}
			}
			int k1 = solve(1);
			if(k1==k)
			{
				f=1;
				break;
			}
		}
		if(f==0)
			cout<<"IMPOSSIBLE\n";
		else
		{
			cout<<"POSSIBLE\n";
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
					cout<<adj[i][j];
				cout<<endl;
			}
		}
	}
	
	return 0;
}
