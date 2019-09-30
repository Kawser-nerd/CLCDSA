#include<iostream>
#include<vector>
using namespace std;
vector<int>v[200001];
int arr[200001];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
		if(a==n)
		{
			arr[b]=1;
		}
		else if(b==n)
		{
			arr[a]=1;
		}
	}
	for(int i=0;i<v[1].size();i++)
	{
		if(arr[v[1][i]]==1)
		{
			cout<<"POSSIBLE";
			return 0;
		}
	}
				cout<<"IMPOSSIBLE";

	return 0;
}