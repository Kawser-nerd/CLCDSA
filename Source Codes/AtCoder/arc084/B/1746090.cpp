#include<iostream>
#include<queue>
using namespace std;
int k,dist[111111];
int main()
{
	cin>>k;
	deque<int> q;
	for(int i=0;i<=k;i++)dist[i]=1<<30;
	q.push_back(dist[1]=1);
	while(!q.empty())
	{
		auto x=q.front(),s=dist[x];q.pop_front();
		if(!x)
		{
			cout<<s<<endl;
			return 0;
		}
		if(dist[x*10%k]>s)dist[x*10%k]=s,q.push_front(x*10%k);
		if(dist[(x+1)%k]>s+1)dist[(x+1)%k]=s+1,q.push_back((x+1)%k);
	}
}